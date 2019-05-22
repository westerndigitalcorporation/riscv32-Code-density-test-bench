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

#define D_THREE                         (3)
#define D_ERR_1                         (0xFF)
#define D_ERR_2                         (0)
#define D_MASK                          (0xFF00FF00)
#define D_FIXED_ADDRESS                 (0xF0007400)
#define D_INLINE                        static inline

typedef struct 
{
  unsigned int st1_field1;
  unsigned int st1_field2;
  unsigned int st1_field3;
  
}ST_1;

typedef struct 
{
  unsigned char st2_field1;
  unsigned char st2_field2; 
} ST_2;

typedef union 
{
  unsigned short un1_field1;
  ST_2 un1_field2;
} UN_1;

unsigned int helper_function_3(unsigned int arg1, unsigned int arg2)
{
  UN_1 un1;

  un1.un1_field2.st2_field1 = (unsigned char)arg1;
  un1.un1_field2.st2_field2 = (unsigned char)arg2;

  un1.un1_field2.st2_field2 &= (arg1 == D_ERR_1) - 1;

  return un1.un1_field1;
}

D_INLINE unsigned int helper_func_1(unsigned int arg1, unsigned int arg2)
{
  return helper_function_3(arg1, arg2);
}

D_INLINE unsigned int helper_func_4(unsigned int arg1)
{
  return ((arg1 & D_MASK) != 0);
}

D_INLINE unsigned int helper_func_2(unsigned int arg1)
{
  if (helper_func_4(arg1))
  {
    return *((unsigned int*)D_FIXED_ADDRESS);
  }

  return D_ERR_2;
}

void helper_func_3(ST_1* st1_p, unsigned int arg1, unsigned int arg2)
{
   unsigned int i;
   for (i = 0 ; i < arg1 ; i++)
   {
      st1_p->st1_field3 += arg2;
   }
}

void my_func(ST_1* st1_p)
{
  unsigned int var1;
  unsigned int var2;

  if (st1_p->st1_field2 != D_ERR_1)
  {
    var1 = helper_func_1(st1_p->st1_field2, D_THREE);
    var2 = helper_func_2(var1);

    helper_func_3(st1_p, var1, var2);
  }
}

void main(int argc, char* argv[])
{
   ST_1** var1_pp;
   *var1_pp = (ST_1*)argv[0];
   ST_1* st1_p = var1_pp[*argv[1]];
   my_func(st1_p);
}

void _start(int argc, char* argv[])
{
  main(argc, argv);
}
