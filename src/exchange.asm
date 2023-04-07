segment .data

segment .bss

segment .text
    global asm_exchange
    
;params: cripto, divisa
asm_exchange:
    push ebp                ;guardar ebp
    mov ebp, esp            ;nuevo ebp

    fld qword [ebp + 8]     ;st0 = cripto
    fmul qword [ebp + 12]   ;st0 = cripto * divisa

    mov esp, ebp            ;restaurar esp
    pop ebp                 ;restaurar ebp
    ret                     ;retornar