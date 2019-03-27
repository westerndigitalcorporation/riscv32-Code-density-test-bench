# Small Constant Creation
> **_GCC RISCV_** poor choice of li with huge numbers instead of using a new register to offset the values then use

<pre>
&gt;&gt; 1006a:  07200793        li        a5,114
   1006e:  02f50863        beq       a0,a5,1009e &lt;f_switch+0x34&gt;
   10072:  00a7e863        bltu      a5,a0,10082 &lt;f_switch+0x18&gt;
&gt;&gt; 10076:  07100793        li        a5,113
   1007a:  02f50263        beq       a0,a5,1009e &lt;f_switch+0x34&gt;
   1007e:  4501            li        a0,0
   10080:  8082            ret
&gt;&gt; 10082:  07300793        li        a5,115
   10086:  00f50c63        beq       a0,a5,1009e &lt;f_switch+0x34&gt;
&gt;&gt; 1008a:  07400793        li        a5,116
   1008e:  fef518e3        bne       a0,a5,1007e &lt;f_switch+0x14&gt;
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
$ riscv64-unknown-elf-gcc -o output/andi_li.o @bld_args andi_li.c
$ riscv64-unknown-elf-gcc -o output/main.elf @lnk_args output/test.o output/andi_li.o
$ riscv64-unknown-elf-objdump -D output/main.elf > output/main_dump 2>&1
```
