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

typedef struct
{
  unsigned char field1;
  unsigned char field1_;
  unsigned int field2;

} ST_1;

unsigned char handler_func_1(ST_1* st1_p);
unsigned char handler_func_2(ST_1* st1_p);

typedef unsigned char (*FUNC_PTR)(ST_1*);

ST_1* list[10];
ST_1* list1[10];

#ifndef __clang__

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

#else

typedef enum TAG_E_VAL
{
  D_VAL_0,
  D_VAL_1,
  D_VAL_2,
  D_VAL_3,
  D_VAL_4,
  D_VAL_5,
  D_VAL_6,
  D_VAL_7,
  D_VAL_8,
  D_VAL_9,
  D_VAL_10,
} E_VAL;

FUNC_PTR func_ptr_table[] =
{
  handler_func_2,
  handler_func_1,
  handler_func_2,
  handler_func_1,
  handler_func_2,
  handler_func_1,
  handler_func_1,
  handler_func_2,
};

FUNC_PTR* list2;

int my_func(unsigned int die, void* pAddr)
{
  int amount = 0;
  *list2 = pAddr;

  switch (die)
  {
    case D_VAL_1:
    {
      list2[amount] = func_ptr_table[die];
      amount++;
      break;
    }

    case D_VAL_2:
    {
       list2[amount + die] = func_ptr_table[die];
      amount++;
      break;
    }

    case D_VAL_3:
    {
      list2[amount] = func_ptr_table[die];
      amount++;
      list2[amount + die] = func_ptr_table[die + 1];
      amount++;
      break;
    }

    case D_VAL_4:
    {
      list2[amount + die] = func_ptr_table[die + 1];
      amount++;
      list2[amount + die] = func_ptr_table[die + 2];
      amount++;
      break;
    }

    case D_VAL_5:
    {
      list2[amount + die] = func_ptr_table[die - 2];
      amount++;
      list2[amount + die] = func_ptr_table[die + 1];
      amount++;
      break;
    }

    case D_VAL_6:
    {
      list2[amount + die] = func_ptr_table[die + 3];
      amount++;
      break;
    }

    case D_VAL_7:
    {
      list2[amount] = func_ptr_table[die];
      amount++;
      list2[amount + die] = func_ptr_table[die + 4];
      amount++;
      break;
    }

    case D_VAL_8:
    {
      list2[amount + die] = func_ptr_table[die + 6];
      amount++;
      list2[amount + die] = func_ptr_table[die + 3];
      amount++;
      break;
    }

    case D_VAL_9:
    {
      list2[amount + die] = func_ptr_table[die - 5];
      amount++;
      break;
    }

    case D_VAL_10:
    {
      list2[amount + die] = func_ptr_table[die - 5];
      amount++;
      break;
    }
 
    default: 
      break;
  }

  return amount;
}
#endif /* #ifndef __clang__ */

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

int main(int argc, char* argv[])
{
#ifndef __clang__
   ST_1** var1_pp;
   *var1_pp = (ST_1*)argv[0];
   ST_1* st1_p = var1_pp[*argv[1]];

   if (my_func(st1_p))
   {
      st1_p->field2++;
   }
#else
   return my_func(*argv[0], argv[1]);
#endif /* __clang__ */
}

void _start(int argc, char* argv[])
{
  main(argc, argv);
}
