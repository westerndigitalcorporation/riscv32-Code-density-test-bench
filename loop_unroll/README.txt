

# for compilation:

riscv32-unknown-elf-gcc -mabi=ilp32 -march=rv32imc -mcmodel=medany -DNOVSIM -fdata-sections -ffunction-sections -Wl,--gc-sections -Wl,--gc-keep-exported -fno-unroll-loops -fno-builtin -nostdlib -fno-inline-small-functions -Os -o loop_unroll_new loop_unroll_new.c

to get the objdump and check the disassemble (case sensitive):

riscv32-unknown-elf-objdump -d -S loop_unroll_new > loop_unroll_new_dump.txt

