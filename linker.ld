ENTRY(reset_handler)

MEMORY
{
    FLASH (rx): ORIGIN = 0x08000000, LENGTH = 512k
    RAM (rwx): ORIGIN = 0x20000000, LENGTH = 112k
}

SECTIONS 
{
    .vector_table :
    {
        . = ALIGN(4);

        KEEP(*(.vector_table))

        . = ALIGN(4);
    } > FLASH

    .text :
    {
        . = ALIGN(4);

        *(.text)
        *(.rodata)

        . = ALIGN(4);
    } > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        . = ALIGN(4);
        _ebss = .;
    } > RAM
}