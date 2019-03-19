
to get the objdump and check the disassembl:

riscv32-unknown-elf-gcc -o out.elf memaccess.c riscv32-unknown-elf-objdump -D out.elf > out.d
