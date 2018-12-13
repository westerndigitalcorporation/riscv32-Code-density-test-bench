import os
import sys

BASE_DIR = "COMPILER_PATH"
GCC_PATH = BASE_DIR + "\\bin\\riscv64-unknown-elf-gcc.exe"
ARC_PATH = BASE_DIR + "\\bin\\riscv64-unknown-elf-ar.exe"
PLUG_ARG = "--plugin " + BASE_DIR + "\\libexec\\gcc\\riscv64-unknown-elf\\8.2.0\\liblto_plugin-0.dll"

##### LINUX #####

#GCC_PATH = BASE_DIR + "/bin/riscv32-unknown-elf-gcc"
#ARC_PATH = BASE_DIR + "/bin/riscv32-unknown-elf-ar"
#PLUG_ARG = "--plugin " + BASE_DIR + "/libexec/gcc/riscv32-unknown-elf/8.2.0/liblto_plugin.so"

strFlag = ""
if len(sys.argv) >= 2:
  strFlag = sys.argv[1]

str_build_flag = ""
if strFlag == "big_code":
  str_build_flag = "-DBIG_CODE"
  
strMain = "%s -o %s @bld.args %s %s" % (GCC_PATH, os.path.join("output", "main.o"), str_build_flag, os.path.join("src", "main.c"))
print strMain
os.system(strMain)

strCrt = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "crt.o"), os.path.join("src", "crt.s"))
print strCrt
os.system(strCrt)

if strFlag == "big_code":
  strFoo = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "foo.o"), os.path.join("src", "foo.c"))
  print strFoo
  os.system(strFoo)
  
  strArc = "%s rc %s %s %s %s %s" % (ARC_PATH, PLUG_ARG, os.path.join("output", "lib.a"), os.path.join("output", "main.o"), os.path.join("output", "crt.o"), os.path.join("output", "foo.o"))
else:
  strArc = "%s rc %s %s %s %s" % (ARC_PATH, PLUG_ARG, os.path.join("output", "lib.a"), os.path.join("output", "main.o"), os.path.join("output", "crt.o"))
 


print strArc
os.system(strArc)

strLink = "%s -o %s @lnk.args %s" % (GCC_PATH, os.path.join("output", "out.elf"), os.path.join("output", "lib.a"))
print strLink
os.system(strLink)
