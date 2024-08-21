from enum import Enum, auto
import re
from typing import Optional, Mapping
import argparse

class CmdType(Enum):
    A_COMMAND = auto()
    C_COMMAND = auto()
    L_COMMAND = auto()

class Parser:
    def __init__(self, input_file: str): 
        self.input_file = input_file
        self.fd = open(self.input_file)
        self.current_line = None        
        self.output_file = input_file.replace(".asm", ".hack")
        self.fw = open(self.output_file, "w")
        self.symbol_table = SymbolTable()
        print(f"Processing {self.input_file} -> {self.output_file}")
        
    def hasMoreCommands():
        """ Stub method because I don't need this in python """
        pass

    def advance(self) -> bool: 
        """Reads the next comand from the input and makes it the
        current command. Shold be called only if hasMoreCommands() is true.
        Initially there is no current command.
        """
        self.current_line = self.fd.readline()

        if not self.current_line:
            return False
        else:
            return True

    def stripline(self, line) -> str:
        """Takes any given line and:
        - strips it of comments
        - trims of extra whitespace on both sides
        """
        result = re.search(r"(.*)\/\/.*", line)
        if result:
            return result.group(1).strip()
        else:
            return line.strip()

    def commandType(self) -> Optional[CmdType]:
        """
        Returns the type of the current command:
        - A_COMMAND for @Xxx where Xxx is either a symbol or decimal number
        - C_COMMAND for dest=comp;jump
        - L_COMMAND (actually pseudo-command) for (Xxx) where Xxx is a symbol
        - None for nothing
        """
        
        line = self.stripline(self.current_line)

        if "=" in line:
            return CmdType.C_COMMAND
        elif "(" in line:
            return CmdType.L_COMMAND
        elif "@" in line:
            return CmdType.A_COMMAND
        elif ";" in line:
            return CmdType.C_COMMAND
        else:
            return None

    def symbol(self) -> str:
        """Returns the symbol or decimal Xxx of the current command @Xxx
        or (Xxx). Should be called only when commandType() is A_COMMAND or L_COMMAND.
        """
        if self.commandType() == CmdType.C_COMMAND:
            raise ValueError("Symbol cannot be called with a C_COMMAND")

        line = self.stripline(self.current_line)
        if self.commandType() == CmdType.A_COMMAND:
            line = line.replace("@", "")
            return line
        else:
            line = line.replace("(", "")
            line = line.replace(")", "")
            return line

    def dest(self) -> str:
        """Returns the dest mnemonic in the current C-command (8 possibilities). 
        Should be called only when commandType() is C_COMMAND.
        """
        if self.commandType() != CmdType.C_COMMAND:
            raise ValueError(f"Dest can only be called with a C_COMMAND, you have {commandType()}")

        line = self.stripline(self.current_line)
        if ";" in line:
            dest = Code.dest("")
            return dest
        else:
            # split on the first "="
            dest, *_ = line.split("=", 1)
            return Code.dest(dest)
            
    
    def comp(self) -> str:
        """Returns the comp mnemonic in the current C-command (28 possibilities).
        Should be called only when commandType() is C_COMMAND.
        """
        if self.commandType() != CmdType.C_COMMAND:
            raise ValueError(f"Comp can only be called with a C_COMMAND, you have {commandType()}")
        
        line = self.stripline(self.current_line)
        if ";" in line:
            comp, _ = line.split(";", 1)
            return Code.comp(comp)
        else:
            # split on the first "="
            _, comp = line.split("=", 1)
            return Code.comp(comp)

    def jump(self) -> str:
        """Returns the jump menomnic in the current C-command (8 possibilities).
        Should be called only when commandType() is C_COMMAND.
        """
        if self.commandType() != CmdType.C_COMMAND:
            raise ValueError(f"Jump can only be called with a C_COMMAND, you have {commandType()}")
        
        line = self.stripline(self.current_line)
        if ";" in line:
            _, jump = line.split(";", 1)
            return Code.jump(jump)
        else:
            return Code.jump("")

    def __enter__(self):
        return self

    def __exit__(self, *args, **kwargs):
        self.fw.close()
        self.fd.close()

    def _reopen(self):
        self.fd.close()
        self.fd = open(self.input_file)

    def buildLSymbols(self):
        counter = 0

        while (self.advance()):
            line = self.stripline(self.current_line)
            if self.commandType() == CmdType.L_COMMAND:
                symbol = self.symbol()
                if not self.symbol_table.contains(symbol):
                    self.symbol_table.addEntry(symbol, counter)
            else:
                if len(line)>0:
                    counter += 1 
        self._reopen()

    def buildSymbols(self):
        """ Builds the symbol table on first pass through of the file
        """
        counter = 0
        remote = 16
        while (self.advance()):
            line = self.stripline(self.current_line)

            if self.commandType() == CmdType.A_COMMAND:
                symbol = self.symbol()

                try:
                    int(symbol)
                except:
                    if not self.symbol_table.contains(symbol):
                        self.symbol_table.addEntry(symbol, remote)
                        remote += 1
                finally:
                    counter += 1 
            # elif self.commandType() == CmdType.L_COMMAND:
            #     symbol = self.symbol()
            #     if not self.symbol_table.contains(symbol):
            #         self.symbol_table.addEntry(symbol, counter)
            else:
                if len(line)>0:
                    counter +=1 

        # reopen the file since we are done reading
        self._reopen()
    
    def parse(self):
        self.buildLSymbols()
        self.buildSymbols() # build symbolmap
        first_line = True
       
        while (self.advance()):
            line = self.stripline(self.current_line)
            match self.commandType():
                case CmdType.C_COMMAND:
                    if "=" in line:
                        address = "111" + self.comp() + self.dest() + Code.jump("")
                    elif ";" in line:
                        address = "111" + self.comp() + Code.dest("") + self.jump()

                    if first_line:
                        self.fw.write(address)
                        first_line = False
                    else:
                        self.fw.write("\n" + address)
                case CmdType.A_COMMAND:
                    symbol = self.symbol()
                    if self.symbol_table.contains(symbol):
                        address = self.symbol_table.GetAddress(symbol)
                    else:
                        address = int(symbol)

                    if first_line:
                        self.fw.write(Code.memoryaddress(address))
                        first_line = False
                    else:
                        self.fw.write("\n")
                        self.fw.write(Code.memoryaddress(address))

                case CmdType.L_COMMAND:
                    # do nothing, as not writing
                    pass
                case _:
                    # do nothing, as not writing
                    pass


class Code:
    @staticmethod
    def memoryaddress(address: int) -> str:
        binvalue = bin(address)[2:]
        return binvalue.zfill(16)

    @staticmethod
    def dest(mnemonic: str) -> str:
        """Returns the binary code of the destination mnemonic.
        """
        match mnemonic:
            case "M":
                return "001"
            case "D":
                return "010"
            case "MD":
                return "011"
            case "A":
                return "100"
            case "AM":
                return "101"
            case "AD":
                return "110"
            case "AMD":
                return "111"
            case _:
                return "000"

    @staticmethod
    def comp(mnemonic: str) -> str:
        """Returns the binary code of the comp mnemonic.
        """
        match mnemonic:
            case "0":
                return "0101010"
            case "1":
                return "0111111"
            case "-1":
                return "0111010"
            case "D":
                return "0001100"
            case "A":
                return "0110000"
            case "!D":
                return "0001101"
            case "!A":
                return "0110001"
            case "-D":
                return "0001111"
            case "-A":
                return "0110011"
            case "D+1":
                return "0011111"
            case "A+1":
                return "0110111"
            case "D-1":
                return "0001110"
            case "A-1":
                return "0110010"
            case "D+A":
                return "0000010"
            case "D-A":
                return "0010011"
            case "A-D":
                return "0000111"
            case "D&A":
                return "0000000"
            case "D|A":
                return "0010101"
            case "M":
                return "1110000"
            case "!M":
                return "1110001"
            case "-M":
                return "1110011"
            case "M+1":
                return "1110111"
            case "M-1":
                return "1110010"
            case "D+M":
                return "1000010"
            case "D-M":
                return "1010011"
            case "M-D":
                return "1000111"
            case "D&M":
                return "1000000"
            case "D|M":
                return "1010101"
            case _:
                raise ValueError("Not a valid comp code")

    @staticmethod
    def jump(mnemonic: str) -> str:
        """Returns the binary code of the jump mnemonic"""
        match mnemonic:
            case "JGT": 
                return "001"
            case "JEQ":
                return "010"
            case "JGE":
                return "011"
            case "JLT":
                return "100"
            case "JNE":
                return "101"
            case "JLE":
                return "110"
            case "JMP":
                return "111"
            case _:
                return "000"


class SymbolTable:
    def __init__(self):
        self.symbols: Mapping[str, int] = {
                "SP": 0,
                "LCL": 1,
                "ARG": 2,
                "THIS": 3,
                "THAT": 4,
                "R0": 0,
                "R1": 1,
                "R2": 2,
                "R3": 3,
                "R4": 4,
                "R5": 5,
                "R6": 6,
                "R7": 7,
                "R8": 8,
                "R9": 9,
                "R10": 10,
                "R11": 11,
                "R12": 12,
                "R13": 13,
                "R14": 14,
                "R15": 15,
                "SCREEN": 16384,
                "KBD": 24576,
                }

    def addEntry(self, symbol: str, address: int) -> None:
        """Adds the pair (symbol, address) to the table.
        """
        if self.contains(symbol):
            raise ValueError(f"Symbol {symbol} already exists in the symbol table")
        else:
            self.symbols[symbol] = address

    def contains(self, symbol: str) -> bool:
        """Does the symbol table contain the given symbol?
        """
        return symbol in self.symbols

    def GetAddress(self, symbol: str) -> int:
        """Returns the address associated with the symbol.
        """
        if self.contains(symbol):
            return self.symbols[symbol]
        else:
            raise ValueError(f"Symbol {symbol} is not available in symbol table")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog="Parser",
                                     description="NandtoTetris chapter 6 assembler")
    parser.add_argument("filename")

    args = parser.parse_args()
    
    with Parser(args.filename) as parser:
        parser.parse()

