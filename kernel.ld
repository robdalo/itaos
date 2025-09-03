MEMORY
{
   ram : ORIGIN = 0x8000, LENGTH = 0x2000
}

SECTIONS
{
   .text.boot : { *(.text.boot*) } > ram
   .text : { *(.text*) } > ram
   .rodata : { *(.rodata*) } > ram
   .data : { *(.data*) } > ram
}