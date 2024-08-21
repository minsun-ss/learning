// zero out results, loops, 
    @0
    D=A
    @R2
    M=D
// zero out looping
    @R4
    M=D
// now start !!
    @R0
    D=M
    @R4
    M=D
    @TOTAL
(TOTAL)
    @R4
    D=M
    @END
    D;JEQ
    @R1
    D=M
    @R2
    M=D+M
    @R4
    M=M-1
    D=M
    @TOTAL
    D;JMP
(END)
    @END
    0;JMP
