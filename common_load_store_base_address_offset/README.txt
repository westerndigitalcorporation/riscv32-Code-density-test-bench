
to get the objdump and check the disassembl:

riscv32-unknown-elf-gcc -Os -march=rv32imc -mabi=ilp32 -o out.elf memaccess.c riscv32-unknown-elf-objdump -D out.elf > out.d
