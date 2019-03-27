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

typedef volatile unsigned int ADDRESS;

#define ADDRESS_1  0x01000000
#define ADDRESS_2  0x01000004
#define ADDRESS_3  0x01000008
#define ADDRESS_4  0x0100000C
#define ADDRESS_5  0x01000010
#define ADDRESS_6  0x01000014
#define ADDRESS_7  0x01000018
#define ADDRESS_8  0x0100001C
#define ADDRESS_9  0x01000020
#define ADDRESS_10 0x01000024
#define ADDRESS_11 0x01000028
#define ADDRESS_12 0x0100002C
#define ADDRESS_13 0x01000030
#define ADDRESS_14 0x01000034
#define ADDRESS_15 0x01000038
#define ADDRESS_16 0x0100003C
#define ADDRESS_17 0x01000040
#define ADDRESS_18 0x01000044

#define SET_ADDRESS(reg, value)  ((*(ADDRESS*)(void*)(reg)) = (value))

unsigned int *my_array;

unsigned int func_get_val(unsigned int index)
{
  return my_array[index];
}

void short_func(unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
  SET_ADDRESS(func_get_val(arg1) + arg2, arg3);
}   

void my_func(unsigned int arg1)
{
  short_func(arg1, ADDRESS_1,  0);
  short_func(arg1, ADDRESS_2,  0);
  short_func(arg1, ADDRESS_3,  0);
  short_func(arg1, ADDRESS_4,  0);
  short_func(arg1, ADDRESS_5,  0);
  short_func(arg1, ADDRESS_6,  0);
  short_func(arg1, ADDRESS_7,  0);
  short_func(arg1, ADDRESS_8,  0);
  short_func(arg1, ADDRESS_9,  0);
  short_func(arg1, ADDRESS_10, 0);
  short_func(arg1, ADDRESS_11, 0);
  short_func(arg1, ADDRESS_12, 0);
  short_func(arg1, ADDRESS_13, 0);
  short_func(arg1, ADDRESS_14, 0);
  short_func(arg1, ADDRESS_15, 0);
  short_func(arg1, ADDRESS_16, 0);
  short_func(arg1, ADDRESS_17, 0);
  short_func(arg1, ADDRESS_18, 0); 
}             

void main(int argc, char* argv[])
{
   my_array = (unsigned int*)argv[0];
   my_func(*((unsigned int*)&argv[1]));
}

void _start(int argc, char* argv[])
{
  main(argc, argv);
}
