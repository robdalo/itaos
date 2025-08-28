.section .text.boot

.global _start

_start:
    b main

.section .text

main:
    // set stack pointer
    ldr sp, =0x80000

    // pass control to kernel
    bl kernel_main
