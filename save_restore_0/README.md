# Compile
    riscv32-unknown-elf-gcc -c save_restore.c save_restore_file2.c @bld_args

# Link
    riscv32-unknown-elf-gcc -o out.elf save_restore.o save_restore_file2.o @lnk_args 

# Disassemble 
    riscv32-unknown-elf-objdump -D out.elf > dump.txt
