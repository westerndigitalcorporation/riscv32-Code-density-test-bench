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

typedef enum
{
  D_VALUE_0,
  D_VALUE_1,
  D_VALUE_2,
  D_VALUE_3,
  D_VALUE_4,
  D_VALUE_5
} E_VALUE;

typedef enum
{
  D_CASE_0,
  D_CASE_1,
  D_CASE_2,
} E_CASE;

typedef struct
{
  unsigned char field1;
  unsigned char field1_;
  unsigned int field2;

} ST_1;

unsigned char handler_func_1(ST_1* st1_p);
unsigned char handler_func_2(ST_1* st1_p);

typedef unsigned char (*FUNC_PTR)(ST_1*);

FUNC_PTR func_ptr_table[D_VALUE_5] =
{
  handler_func_2,
  handler_func_1,
  handler_func_2,
  handler_func_2,
};

static inline E_VALUE get_index(const ST_1* st1_p)
{
  switch (st1_p->field1)
  {
    case D_CASE_0:
      return  D_VALUE_1;

    case D_CASE_1:
      return D_VALUE_2;

    case D_CASE_2:
      return D_VALUE_3;
  }

  return D_VALUE_4;
}

ST_1* list[100];
ST_1* list1[100];

unsigned char handler_func_2(ST_1* st1_p)
{
   if (list[st1_p->field2] != 0)
   {
     list[st1_p->field2] = st1_p;
     return 0;
   }
   return 1;
}

unsigned char handler_func_1(ST_1* st1_p)
{
   if (list1[st1_p->field2] != 0)
   {
     list1[st1_p->field2] = st1_p;
     return 1;
   }
   return 0;
}

unsigned int my_func(ST_1* st1_p)
{
   E_VALUE index;
   FUNC_PTR func_p;
   unsigned int res;

   index = get_index(st1_p);
   func_p = func_ptr_table[index];
   res = func_p(st1_p);

   return res;
}

void main(int argc, char* argv[])
{
   ST_1** var1_pp;
   *var1_pp = (ST_1*)argv[0];
   ST_1* st1_p = var1_pp[*argv[1]];

   if (my_func(st1_p))
   {
      st1_p->field2++;
   }
}

void _start(int argc, char* argv[])
{
  main(argc, argv);
}
