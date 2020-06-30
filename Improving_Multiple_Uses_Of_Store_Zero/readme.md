# Improving uses of store Zero
> When using multiple Zero store, **_GCC RISCV_** does it all in 32Bit instructions instead of setting 0 in lower register and use commpressed instructions
> This is a usage of dummy Memset function (not from RT lib), the compiler choose to "flat" the dummy memset as an inline.

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

### Build with LLVM
Please update ```--sysroot=``` and ```--gcc-toolchain=``` under llvm_bld_args/llvm_lnk_args
