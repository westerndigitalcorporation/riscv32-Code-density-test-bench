
/* 
* SPDX-License-Identifier: Apache-2.0
* Copyright 2019 Western Digital Corporation or its affiliates.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http:*www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
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


