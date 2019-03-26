#  
# SPDX-License-Identifier: MIT
# MIT License
# 
# Copyright (c) 2019 Western Digital Corporation or its affiliates.
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice (including the next paragraph) shall be included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

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
  
strMain = "%s -o %s @bld.args %s %s" % (GCC_PATH, os.path.join("output", "main.o"), str_build_flag, os.path.join("code", "src", "main.c"))
print strMain
os.system(strMain)

strCrt = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "crt.o"), os.path.join("code", "src", "crt.s"))
print strCrt
os.system(strCrt)

if strFlag == "big_code":
  strFoo = "%s -o %s @bld.args %s" % (GCC_PATH, os.path.join("output", "foo.o"), os.path.join("code", "src", "foo.c"))
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
