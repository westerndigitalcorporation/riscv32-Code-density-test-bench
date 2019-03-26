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

#define D_SHIFT_BITS_1  (24)
#define D_MASK_1        (0x07000000)
#define D_SHIFT_BITS_2  (9)
#define D_MASK_2        (0x0001FE00)
#define D_SHIFT_BITS_3  (0)
#define D_MASK_3        (0x0000000F)

#define   M_SET(reg, val)  *((unsigned int*)(reg)) = (val);

void bar(unsigned int val1, unsigned int val2, unsigned char index)
{
  M_SET(0x80001000+index, ((val2  << D_SHIFT_BITS_1) & D_MASK_1) |
                          ((index << D_SHIFT_BITS_2) & D_MASK_2) |
                          ((val1  << D_SHIFT_BITS_3) & D_MASK_3));
}

void foo(unsigned int val1, unsigned int val2, unsigned char index)
{
  bar(val1, val2, index);
}

void main(void)
{
  unsigned int idx;

  for(idx = 0; idx < 63; idx++)
  {
    foo(3, 0, (unsigned char)idx);
  }
}

void _start()
{
   main();
}
