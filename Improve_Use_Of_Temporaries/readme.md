# Improve use of temporaries
> **_GCC RISCV_** poor rsgister allocation ability, it allocated two registers for the function params while the function didn't used these registers at all costing 4 unnecessary move instructions

<pre>
&gt;&gt;  100c0:        872a            mv        a4,a0
&gt;&gt;  100c2:        86ae            mv        a3,a1
    100c4:        00c79963        bne       a5,a2,100d6 &lt;f_get_number+0x26&gt;
    100c8:        00001617        auipc     a2,0x1
    100cc:        1dc60613        addi      a2,a2,476 # 112a4 &lt;G_ONE&gt;
    100d0:        4210            lw        a2,0(a2)
    100d2:        00f61663        bne       a2,a5,100de &lt;f_get_number+0x2e&gt;
&gt;&gt;  100d6:        85b6            mv        a1,a3
&gt;&gt;  100d8:        853a            mv        a0,a4
</pre>

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
$ riscv64-unknown-elf-gcc -o output/test.o @bld_args test.c
$ riscv64-unknown-elf-gcc -o output/funcs.o @bld_args funcs.c
$ riscv64-unknown-elf-gcc -o output/main.elf @lnk_args output/test.o output/funcs.o
$ riscv64-unknown-elf-objdump -D output/main.elf > output/main_dump 2>&1
```
