
## Build
in order to build the test please run the following command/s using your **_LLVM RISCV_** compiler<br/>
first you need to build and link the source files then dump the assimbly of the executable binary to file

Build command pattern:
> &lt;PATH-TO-RV-LLVM&gt; -o &lt;OBJECT-FILENAME&gt; @&lt;COMPILER-FLAGS-FILENAME&gt; &lt;SOURCE-FILENAME&gt;

Dump assembly command pattern:
> &lt;PATH-TO-RV-OBJECT-DUMP&gt; -D &lt;OBJECT-FILENAME&gt; &gt; &lt;DUMP-FILENAME&gt; 2&gt;&amp;1

### Example llvm

```sh
$ ./clang -o memaccess.o @llvm_bld_args memaccess.c
$ ./clang -o memaccess.elf @llvm_lnk_args memaccess.o
$ ./riscv32-unknown-elf-objdump -DS memaccess.elf > memaccess_dump 2>&1
```

### Build with LLVM
Please update ```--sysroot=``` and ```--gcc-toolchain=``` under llvm_bld_args/llvm_lnk_args

### Build with gcc

```
riscv32-unknown-elf-gcc -Os -march=rv32imc -mabi=ilp32 -o out.elf memaccess.c riscv32-unknown-elf-objdump -D out.elf > out.d
```
