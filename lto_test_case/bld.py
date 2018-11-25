import os

GCC_PATH = "MY_PATH\\bin\\riscv64-unknown-elf-gcc.exe"
ARC_PATH = "MY_PATH\\bin\\riscv64-unknown-elf-ar.exe"
PLUG_ARG = "--plugin MY_PATH\\libexec\\gcc\\riscv64-unknown-elf\\8.2.0\\liblto_plugin-0.dll"

##### LINUX #####

#GCC_PATH = "MY_PATH/bin/riscv32-unknown-elf-gcc"
#ARC_PATH = "MY_PATH/bin/riscv32-unknown-elf-ar"
#PLUG_ARG = "--plugin MY_PATH/libexec/gcc/riscv32-unknown-elf/8.2.0/liblto_plugin.so"

strMain = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "main.o"), os.path.join("src", "main.c"))
print strMain
os.system(strMain)

strCrt = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "crt.o"), os.path.join("src", "crt.s"))
print strCrt
os.system(strCrt)

strArc = "%s rc %s %s %s %s" % (ARC_PATH, PLUG_ARG, os.path.join("output", "lib.a"), os.path.join("output", "main.o"), os.path.join("output", "crt.o"))
print strArc
os.system(strArc)

strLink = "%s -o %s @lnk.args %s" % (GCC_PATH, os.path.join("output", "out.elf"), os.path.join("output", "lib.a"))
print strLink
os.system(strLink)
