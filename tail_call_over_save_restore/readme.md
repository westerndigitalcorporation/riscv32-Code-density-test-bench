# Tail call over save/restore

> The function **f_func_to_analyze** got tail called instead of using the ```-msave-restore```.


## Build
in order to build the test please run the following command/s using your **_LLVM RISCV_** compiler<br/>
first you need to build and link the source files then dump the assimbly of the executable binary to file

Build command pattern:
> &lt;PATH-TO-RV-LLVM&gt; -o &lt;OBJECT-FILENAME&gt; @&lt;COMPILER-FLAGS-FILENAME&gt; &lt;SOURCE-FILENAME&gt;

Dump assembly command pattern:
> &lt;PATH-TO-RV-OBJECT-DUMP&gt; -D &lt;OBJECT-FILENAME&gt; &gt; &lt;DUMP-FILENAME&gt; 2&gt;&amp;1

### Example

```sh
$ mkdir output
$ ./clang -o main.o @llvm_bld_args main.c
$ ./clang -o main.elf @llvm_lnk_args main.o
$ ./riscv32-unknown-elf-objdump -DS main.elf > main_dump 2>&1
```
