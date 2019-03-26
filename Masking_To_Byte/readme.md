# Masking to type
> When the function type is define as unsigned char while it return onlt 1 or 0, the **_GCC RISCV_** is not aware that it can strip the casting and still doing it for nothing

## Build
in order to build the test please run the following command/s using your **_GCC RISV_** compiler<br/>
first you need to build and link the source files then dump the assimbly of the executable binary to file

Build command pattern:
> &lt;PATH-TO-RV-GCC&gt; -o &lt;OBJECT-FILENAME&gt; @&lt;COMPILER-FLAGS-FILENAME&gt; &lt;SOURCE-FILENAME&gt;

Dump assembly command pattern:
> &lt;PATH-TO-RV-OBJECT-DUMP&gt; -D &lt;OBJECT-FILENAME&gt; &gt; &lt;DUMP-FILENAME&gt; 2&gt;&amp;1

### Example

```sh
$ mkdir output
$ riscv64-unknown-elf-gcc -o output/main.o @bld_args main.c
$ riscv64-unknown-elf-gcc -o output/main.elf @lnk_args output/main.o
$ riscv64-unknown-elf-objdump -D output/main.elf > output/main_dump 2>&1
```
