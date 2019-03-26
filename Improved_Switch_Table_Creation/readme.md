# Improve switch table creation

> Switch case: flat/merge to addi… **_GCC RISCV_** created a switch table, since the code is a switch case for inderact calls.<br/>
> it failed to see that all of those functions can be access by short cmp

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
