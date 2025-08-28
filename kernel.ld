ENTRY(_start)

SECTIONS {
    .text.boot 0x80000 : { *(.text.boot) }
    .text : { *(.text*) }
    .data : { *(.data*) }
    .rodata : { *(.rodata*) },

    /DISCARD/ : { *(*) }
}