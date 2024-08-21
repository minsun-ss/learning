from parser import Parser, CmdType, Code, SymbolTable
import pytest

@pytest.mark.parametrize(
        "line,expected",
        [("Blah//whatever", "Blah"),
         ("Blah ", "Blah"),
         ])
def test_stripline(line, expected):
    parser = Parser("Test.asm")
    result = parser.stripline(line)
    assert result==expected, f"{result} should have been {expected}"

@pytest.mark.parametrize(
        "line,expected",
        [("blah=whatever;jmp", CmdType.C_COMMAND),
         ("0;JMP", CmdType.C_COMMAND),
         ("(BLAH)", CmdType.L_COMMAND),
         ("@whatever", CmdType.A_COMMAND),
         ]
        )
def test_commandtype(line, expected):
    parser = Parser("Test.asm")
    parser.current_line=line
    result = parser.commandType()
    assert result==expected, f"{line} should have resulted in {expected} type commands"

@pytest.mark.parametrize(
        "line,expected",
        [("(BLAH)", "BLAH"),
         ("(BLAH )", "BLAH "),
         ("@whatever", "whatever"),
         ("@103", "103"),
         ("@whatever ", "whatever")
         ])
def test_symbol(line, expected):
    with Parser("Test.asm") as parser:
        parser.current_line=line
        result = parser.symbol()
        assert result==expected, f"{line} should have resulted in {expected} symbols"

@pytest.mark.parametrize(
        "line,expected",
        [("0;JGT", "000"),
         ("M=M+1", "001"),
         ("D=M", "010"),
        ])
def test_dest(line, expected):
    with Parser("Test.asm") as parser:
        parser.current_line=line
        result = parser.dest()
        assert result==expected, f"{line} should have resulted in {expected} destination"

@pytest.mark.parametrize(
        "line,expected",
        [("0;JGT", "0101010"),
         ("M=M+1", "1110111")
            ])
def test_comp(line, expected):
    with Parser("Test.asm") as parser:
        parser.current_line = line
        result = parser.comp()
        assert result==expected, f"{line} should have resulted in {expected} comp"

@pytest.mark.parametrize(
        "line,expected",
        [("0;JGT", "001"),
         ("M=M+1", "000")
         ])
def test_jump(line, expected):
    with Parser("Test.asm") as parser:
        parser.current_line = line
        result = parser.jump()
        assert result==expected, f"{line} should have resulted in {expected} comp"

def test_codedest():
    dest = Code.dest("MD")
    ans = "011"
    assert dest == ans, f"Destination {dest} should be {ans}"

def test_codebinary():
    val = Code.memoryaddress(16)
    assert val == "0000000000010000", "binary should be 16 bits long"

