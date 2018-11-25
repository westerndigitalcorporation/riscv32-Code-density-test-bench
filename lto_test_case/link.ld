/*======================================================================*/
/* dcp processor linker script (CPU : riscv32imc)                       */
/*======================================================================*/
/* This is the linker script used when building dcp processor code. */

/*----------------------------------------------------------------------*/
/* Setup                                                                */
/*----------------------------------------------------------------------*/

/* The OUTPUT_ARCH command specifies the machine architecture where the
   argument is one of the names used in the BFD library. More
   specifically one of the entires in bfd/cpu-mips.c */

OUTPUT_ARCH( "riscv" )
ENTRY(_start)

/* attributes
  - ‘r’ : Read-only section
  - ‘w’ : Read/write section
  - ‘x’ : Executable section
  - ‘a’ : Allocatable section
  - ‘i’ : Initialized section
  - ‘l’ : Same as ‘I’
  - ‘!’ : Invert the sense of any of the attributes that follow
 */
 
MEMORY
{
  ROM (rxai!w) : ORIGIN = 0x00010000, LENGTH = 71K
  DCCM (wxa!ri) : ORIGIN = 0xE0000000, LENGTH = 40K
}

/*----------------------------------------------------------------------*/
/* Sections                                                             */
/*----------------------------------------------------------------------*/

SECTIONS
{
  __stack_size = DEFINED(__stack_size) ? __stack_size : 4K;

  .text.init :
  {
    *(.text.init)
  } > ROM

  .text :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    *(.text .text.*)
    *(.gnu.linkonce.t.*)
  } > ROM

  .rodata :
  {
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
  } > ROM

  .data :
  {
    *(.data .data.*)
    *(.gnu.linkonce.d.*)
  } > DCCM

  .sdata :
  {
    . = ALIGN(8);
    __global_pointer$ = . + 0x800;
    *(.sdata .sdata.*)
    *(.gnu.linkonce.s.*)
    . = ALIGN(8);
    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
  } > DCCM

  .sbss :
  {
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
  } > DCCM

  .bss :
  { 
    *(.bss)
  } > DCCM
  
  .tdata :
  {
    _tls_data = .;
    *(.tdata.begin)
    *(.tdata)
    *(.tdata.end)
  } > DCCM
  
  .tbss :
  {
    *(.tbss)
    *(.tbss.end)
  } > DCCM
  . = ALIGN(8);

  .stack :
  {
    _heap_end = .;
    . = . + __stack_size;
    _sp = .;
  } > DCCM

}
