ENTRY(_start)

SECTIONS {
    .text.boot 0x8000 : { *(.text.boot) }
    .text : { *(.text*) }
    .data : { *(.data*) }
    .rodata : { *(.rodata*) },
    .bss : {
        __bss_start__ = .;
        *(.bss)
        __bss_end__ = .;
    },

    /DISCARD/ : { *(*) }
}