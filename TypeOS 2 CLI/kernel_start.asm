[bits 32]
global _start
[global GetKB]
[extern Crash]
[extern main]
_start:
call main
call Crash
jmp $
GetKB:
    in al, 0x60
    mov ah, al
    and ah, 10000000b
    jnz GetKBRet
    mov byte [0xFFF], al
    or al, 10000000b
    out 0x60, al
    ret
    GetKBRet:
        mov byte [0xFFF], 0
        ret