# 
# SPDX-License-Identifier: Apache-2.0
# Copyright 2019 Western Digital Corporation or its affiliates.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http:*www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
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
