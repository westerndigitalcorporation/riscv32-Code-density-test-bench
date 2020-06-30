
/* 
* SPDX-License-Identifier: MIT
* MIT License
* 
* Copyright (c) 2019 Western Digital Corporation or its affiliates.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice (including the next paragraph) shall be included in all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>

//unsigned long TEMP;
#define TEMP 0xF0000000
#define BASE (TEMP + 0x80000)

#define SRC1 (BASE + 0x000000F0)
#define SRC2 (BASE + 0x000000F4)
#define SRC3 (BASE + 0x000000F8)
#define SRC4 (BASE + 0x000000Fc)
#define SRC5 (BASE + 0x00000100)
#define SRC6 (BASE + 0x00000104)
#define SRC7 (BASE + 0x00000108)
#define SRC8 (BASE + 0x0000010C)

#define DEST (TEMP + 0x18F14)

int test()
{
	//TEMP = 0xF0000000;
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC3);
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC4);
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC5);
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC6);
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC7);
	*(volatile unsigned int*)(DEST) = *(volatile unsigned int*)(SRC8);
	return 0;
}


int main(int argc, char** argv)
{
	test();
}

#ifdef __clang__
void _start(int argc, char* argv[])
{
  main(argc, argv);
}
#endif

