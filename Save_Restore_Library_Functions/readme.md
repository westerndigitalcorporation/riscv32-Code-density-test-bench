# Save/Restore library functions
> \_\_riscv_restore_0 are been called **_~200_** times
> Those are not really needed to be called since we sometime don’t need to acutlly save registers

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
$ riscv64-unknown-elf-gcc -o output/save_restore.o @bld_args save_restore.c
$ riscv64-unknown-elf-gcc -o output/save_restore_file2.o @bld_args save_restore_file2.c
$ riscv64-unknown-elf-gcc -o output/main.elf @lnk_args output/save_restore.o output/save_restore_file2.o
$ riscv64-unknown-elf-objdump -D output/main.elf > output/main_dump 2>&1
```
