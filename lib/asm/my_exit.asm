global my_exit

section .text

my_exit:
    mov rax, 0x3c
    mov rdx, rdi
    syscall
