[org 0x7C00]
[bits 16]
mov ax, cs
mov ds, ax
mov es, ax
xor ax, ax
mov ss, ax
mov si, ax
mov ax, 0x7C00
mov bp, ax
mov sp, bp

mov ah, 2
mov al, 5           ; 2.5kb for TypeOS 2 boot shell
mov ch, 0
mov cl, 2
mov bx, 0x7E00
int 0x13

mov ah, 2
mov al, 20          ; 10kb for 32-bit kerne;
mov ch, 0
mov cl, 7
mov bx, 0x1000
int 13h

mov bx, _MSG
call print

NOTE_E1 equ 1193182 / 41
NOTE_G1 equ 1193182 / 49
NOTE_E2 equ 1193182 / 82
NOTE_Eb3 equ 1193182 / 155
NOTE_E3 equ 1193182 / 164
NOTE_F3 equ 1193182 / 174
NOTE_G3 equ 1193182 / 196
NOTE_Ab3 equ 1193181 / 208
NOTE_A3 equ 1193182 / 220
NOTE_Bb3 equ 1193182 / 233
NOTE_B3 equ 1193182 / 247
NOTE_C4 equ 1193182 / 262
NOTE_D4 equ 1193182 / 294
NOTE_E4 equ 1193182 / 330
NOTE_F4 equ 1193182 / 350
NOTE_G4 equ 1193182 / 392
NOTE_A4 equ 1193182 / 440
NOTE_B4 equ 1193182 / 494
NOTE_C5 equ 1193182 / 523
NOTE_D5 equ 1193182 / 554

main:
    mov bx, _KeybBuff
    mov dx, bx
    times 3 inc dx
    mov ah, 0Eh
    mov al, 0x0D
    int 10h
    mov al, 0x0A
    int 10h
    mov al, '>'
    int 10h
    loop1:
        mov ah, 0
        int 16h
        mov ah, 0Eh
        int 10h
        mov byte [bx], al
        cmp bx, dx
        je Process
        inc bx
        jmp loop1

jmp $           ; prevent functions from executing when they aren't supposed to

_KeybBuff:
    times 4 db 0

_br:
    db 0x0D, 0x0A, 0

_MSG:
    db "TypeOS 2 v0.4.7", 0x0D, 0x0A, 0

Process:
    mov bx, _br
    call print
    cmp dword [_KeybBuff], "test"
    je _test
    cmp dword [_KeybBuff], "klar"
    je _klar
    cmp dword [_KeybBuff], "code"
    je _code
    jmp main

print:
    mov ah, 0Eh
    cmp byte [bx], 0
    je _printret
    mov al, [bx]
    int 10h
    inc bx
    jmp print
    _printret:
    ret

; built in command functions

_test:
    mov bx, _testMSG
    call print
    jmp main
    _testMSG:
        ; the date is in UK dates DD/MM/YYYY
        db "OS tech test version 0.4.7 08/01/2022 is working as intended ", 2, 0

_klar:
    mov ah, 0
    mov al, 3
    int 10h
    jmp main

_code:
    mov bx, _codeMSG
    call print
    mov bx, _br
    call print
    mov ah, 0
    int 16h
    cmp al, 'p'
    je _32bitSwitch
    cmp al, 's'
    je _makeNoise
    jmp main
    _codeMSG:
        db "advanced commands", 0
times 510-($-$$) db 0           ; pad remainder of bootloader with 0
dw 0xAA55                       ; BIOS boot signature

_makeNoise:
    mov al, 182
    out 0x43, al

    mov ax, NOTE_E1
    call _semiLoopCMDs
    mov ax, NOTE_E2
    call _semiLoopCMDs
    mov ax, NOTE_G1
    call _semiLoopCMDs
    mov ax, NOTE_E2
    call _semiLoopCMDs
    mov ax, NOTE_E1
    call _semiLoopCMDs
    mov ax, NOTE_E2
    call _semiLoopCMDs
    mov ax, NOTE_G1
    call _semiLoopCMDs
    mov ax, NOTE_E2
    call _semiLoopCMDs
    times 20 call __E3_LOOP
    mov ax, NOTE_E3
    call _semiLoopCMDs
    mov ax, NOTE_F3
    call _semiLoopCMDs
    mov ax, NOTE_E3
    call _semiLoopCMDs
    mov ax, NOTE_Eb3
    call _semiLoopCMDs
    mov ax, NOTE_E3
    call _semiLoopCMDs
    mov ax, NOTE_A3
    call _semiLoopCMDs
    mov ax, NOTE_C4
    call _semiLoopCMDs
    times 5 call __D4_LOOP
    mov ax, NOTE_C4
    call _semiLoopCMDs
    mov ax, NOTE_B3
    call _semiLoopCMDs
    mov ax, NOTE_D4
    call _semiLoopCMDs
    times 5 call __C4_LOOP
    mov ax, NOTE_B3
    call _semiLoopCMDs
    mov ax, NOTE_A3
    call _semiLoopCMDs
    call __C4_LOOP
    times 4 call __B3_LOOP
    mov ax, NOTE_Ab3
    call _semiLoopCMDs
    call __B3_LOOP
    mov ax, NOTE_Bb3
    call _semiLoopCMDs
    mov ax, NOTE_E2
    call _semiLoopCMDs

    times 18 call __E3_LOOP
    mov ax, NOTE_F3
    call _semiLoopCMDs
    call __E3_LOOP
    mov ax, NOTE_Eb3
    call _semiLoopCMDs
    mov ax, NOTE_E3
    call _semiLoopCMDs
    mov ax, NOTE_A3
    call _semiLoopCMDs
    mov ax, NOTE_C4
    call _semiLoopCMDs
    mov ax, NOTE_E4
    call _semiLoopCMDs
    mov ax, NOTE_A4
    call _semiLoopCMDs
    mov ax, NOTE_C5
    call _semiLoopCMDs
    mov ax, NOTE_D5
    call _semiLoopCMDs
    mov ax, NOTE_C5
    call _semiLoopCMDs
    mov ax, NOTE_B4
    call _semiLoopCMDs
    mov ax, NOTE_D5
    call _semiLoopCMDs
    mov ax, NOTE_C5
    call _semiLoopCMDs
    mov ax, NOTE_B4
    call _semiLoopCMDs
    mov ax, NOTE_A4
    call _semiLoopCMDs
    jmp main
__E3_LOOP:
    mov ax, NOTE_E3
    call _semiLoopCMDs
    ret
__D4_LOOP:
    mov ax, NOTE_D4
    call _semiLoopCMDs
    ret
__C4_LOOP:
    mov ax, NOTE_C4
    call _semiLoopCMDs
    ret
__B3_LOOP:
    mov ax, NOTE_B3
    call _semiLoopCMDs
    ret
_semiLoopCMDs:
        call _startsound
        mov ah, 0x86
        mov cx, 0x0003
        mov dx, 0xD090
        int 0x15
        call _stopsound
        mov cx, 0x0001
        mov dx, 0xA585
        int 0x15
        ret
_startsound:
        mov al, 182
        out 0x43, al
        out 0x42, al
        mov al, ah
        out 0x42, al
        in al, 0x61
        or al, 00000011b
        out 0x61, al
        ret
_stopsound:
        in al, 0x61
        and al, 11111100b
        out 0x61, al
        ret
_32bitSwitch:
    mov bx, _32bitSwitchMSG
    call print
    mov bx, _br
    call print
    mov ah, 00h
    mov al, 03h
    int 10h
    mov ah, 01h
    mov ch, 0x3F
    int 10h
    cli
    lgdt [cs:gdt32_desc]
    mov eax, cr0
    or eax, 00000001b
    mov cr0, eax    ; protected mode enabled
    jmp CODE_SEG32:start_PM
    start_PM:
        [bits 32]
        mov ax, DATA_SEG32
        mov ds, ax
        mov ss, ax
        mov es, ax
        mov fs, ax
        mov gs, ax
        mov ebp, 0x90000
        mov esp, ebp
        jmp 0x1000
        jmp $
    _32bitSwitchMSG:
        db "Switching to i386 protected mode", 0
    gdt32:
    gdt32_start:
        gdt32_null:
            dq 0
        gdt32_code:
            dw 0xFFFF
            dw 0
            db 0
            db 10011010b
            db 11001111b
            db 0
        gdt32_data:
            dw 0xFFFF
            dw 0
            db 0
            db 10010010b
            db 11001111b
            db 0
        gdt32_end:
            gdt32_desc:
                dw gdt32_end - gdt32_start - 1
                dd gdt32_start
                CODE_SEG32 equ gdt32_code - gdt32_start
                DATA_SEG32 equ gdt32_data - gdt32_start
times 3072-($-$$) db 0          ; pad remainder of boot shell space with 0