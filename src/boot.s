.section .text.boot

.global _start

_start:
    b main

.section .text

main:
    // set stack pointer
    ldr sp, =0x8000

    // zero bss section
    bl zero_bss

    // pass control to kernel
    bl kernel_main
