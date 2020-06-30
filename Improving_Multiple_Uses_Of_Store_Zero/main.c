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

typedef struct TAG_ST_CB1   
{
  const unsigned int* p_val;
  unsigned int val1;
  unsigned char val2;					
  unsigned char arr[3];
} ST_CB1;

typedef struct TAG_ST_CB
{
  ST_CB1 cb1;
  unsigned char val1;              
  unsigned char arr[3];
  unsigned int val2;
} ST_CB;

ST_CB g_cb;

#ifndef __clang__
   void *memset(void *dest, int c, unsigned int n)
   { 
      unsigned char* dest_ptr = (unsigned char*)dest;
      register char ch = (char)c;

      while (n--)
      {
        *dest_ptr++ = ch;
      }

      return dest;
   }

   void my_func(void)
   {
     memset(&g_cb, 0, sizeof(g_cb));
   }

   void main(void)
   {
      my_func();
   }
#else
   void my_func(unsigned int argOffset, unsigned int argValue)
   {
     *((unsigned int*)0x80000000 + argOffset) = argValue;
   }   

   int main(void)
   {
      my_func(0, 0);
      my_func(1, 0);
      my_func(2, 0);
      my_func(3, 0);
      my_func(4, 0);
      my_func(5, 0);
      my_func(6, 0);
      my_func(7, 0);
      my_func(8, 0);
      my_func(9, 0);
      my_func(10, 0);
      my_func(11, 0);
   }
#endif // #ifndef __clang__

void _start()
{
   main();
}
