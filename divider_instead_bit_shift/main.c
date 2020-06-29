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
unsigned int global_var_1;
unsigned int global_var_2;
unsigned int global_var_3;
unsigned int global_var_4;
unsigned int global_var_5;
unsigned int global_var_6;
unsigned int global_var_7;

#define DEF_1 0
#define DEF_2 1
#define DEF_3 2
#define DEF_4 3
#define DEF_5 4
#define DEF_6 5

void f_func_to_analyze(unsigned int* arg)
{
   unsigned short* locOffsets_p = (unsigned short*)arg;

   locOffsets_p[DEF_1] = (unsigned short)(&global_var_1 - &global_var_7);
   locOffsets_p[DEF_2] = (unsigned short)(&global_var_2 - &global_var_7);
   locOffsets_p[DEF_3] = (unsigned short)(&global_var_3 - &global_var_7);
   locOffsets_p[DEF_4] = (unsigned short)(&global_var_4 - &global_var_7);
   locOffsets_p[DEF_5] = (unsigned short)(&global_var_5 - &global_var_7);
   locOffsets_p[DEF_6] = (unsigned short)(&global_var_6 - &global_var_7);
}

int main(int argc, char* argv[])
{
  f_func_to_analyze((unsigned int*)argv);
}

void _start(int argc, char* argv[])
{
   main(argc, argv);
}
