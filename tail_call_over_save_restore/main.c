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
#include "string.h"

#define DEF_1     255
#define DEF_2     0
#define DEF_3     0xFF00FF00
#define DEF_4     0x10 
#define DEF_5     0
#define MAC_1(x)  (&(((unsigned int*)0xF0007400)[x]))

typedef struct
{
  unsigned char field_1;
  unsigned char field_2;
} S_STRUCT_1;

typedef union
{
  unsigned short value;
  S_STRUCT_1     fields;
} U_UNION_1;

typedef enum
{
  ENUM_1_VAL_1,
  ENUM_1_VAL_2,
  ENUM_1_VAL_3,
  ENUM_1_VAL_4,
  ENUM_1_VAL_5,
  ENUM_1_VAL_6 = 0xFFFFFFFF
} ENUM_1;

typedef struct
{
  unsigned int s_2_f_1 : 13;
  unsigned int s_2_f_2 : 3;
  unsigned int s_2_f_4 : 12;
  unsigned int s_2_f_5 : 4;
}S_STRUCT_2;

typedef struct
{
  unsigned int   s_3_f_1;
  S_STRUCT_2     s_3_f_2;      
  unsigned int   s_3_f_3; 
} S_STRUCT_3;

typedef struct
{
  unsigned char s_7_f_1;      
  S_STRUCT_3    s_7_f_2;
} S_STRUCT_7;

typedef struct
{
  unsigned int    s_8_f_1;
  unsigned int    s_8_f_2;   
  unsigned short  s_8_f_3;
  unsigned short  s_8_f_4;
}S_STRUCT_8;

__attribute__((noinline)) void f_ext_func_1(const S_STRUCT_2* p_f_1_arg_1,
                  unsigned char f_1_arg_2,
                  unsigned int  f_1_arg_3,
                  S_STRUCT_8*   p_f_1_arg_4)
{
  *((unsigned int*)0x80000000 + f_1_arg_2) = (f_1_arg_3 + p_f_1_arg_1->s_2_f_4) |  p_f_1_arg_4->s_8_f_3;
}

__attribute__((noinline))void f_ext_func_2(const S_STRUCT_2* p_f_2_arg_1,
                  const S_STRUCT_8* p_f_2_arg_2)
{
  *((unsigned int*)0x80008004) = (p_f_2_arg_1->s_2_f_4 &  p_f_2_arg_2->s_8_f_3);
}

__attribute__((noinline))void f_ext_func_3(const S_STRUCT_2* p_f_3_arg_1, 
                  const S_STRUCT_8* p_f_3_arg_2)
{
  *((unsigned int*)0x80008008) = (p_f_3_arg_1->s_2_f_1 |  p_f_3_arg_2->s_8_f_4);
}

static __inline unsigned int f_func_7(unsigned int f_7_arg_1, ENUM_1 f_7_arg_2)
{
  U_UNION_1 loc_var_1;

  loc_var_1.fields.field_1 = (unsigned char)f_7_arg_1;
  loc_var_1.fields.field_2 = (unsigned char)f_7_arg_2;

  loc_var_1.fields.field_2 &= (f_7_arg_1 == DEF_1) - 1;

  return loc_var_1.value;
}

static __inline unsigned int f_func_4(unsigned int f_4_arg_1, ENUM_1 f_4_arg_2)
{
  return f_func_7(f_4_arg_1, f_4_arg_2);
}

static __inline unsigned int f_func_6(unsigned int f_6_arg_1)
{
  return ((f_6_arg_1 & DEF_3) != 0);
}

static __inline unsigned int f_func_5(unsigned int f_5_arg_1)
{
  if (f_func_6(f_5_arg_1))
  {
    return (unsigned int)(MAC_1(DEF_5));
  }

  return DEF_2;
}

void f_func_2(unsigned char f_2_arg_1, unsigned char f_2_arg_2, unsigned int f_2_arg_3, unsigned int f_2_arg_4)
{
  const unsigned int loc_var_1 = f_func_4(f_2_arg_4, ENUM_1_VAL_4);
  const unsigned int loc_var_2 = f_func_5(loc_var_1);
  S_STRUCT_2         loc_var_3 = {0};
  S_STRUCT_8         loc_var_4;

  memset(&loc_var_4, 0, sizeof(loc_var_4));
  loc_var_3.s_2_f_5 = f_2_arg_1;
  loc_var_4.s_8_f_1 = loc_var_2;
  loc_var_4.s_8_f_2 = loc_var_1;
  f_ext_func_1(&loc_var_3, f_2_arg_2, f_2_arg_3, &loc_var_4);
}

static __inline void f_func_3(unsigned int f_3_arg_1, unsigned short f_3_arg_2)
{
  *((unsigned int*)0x70000000) = f_3_arg_1;
  *((unsigned int*)0x70000004) = f_3_arg_2;
}

void f_func_1(unsigned int f_1_arg_1, unsigned short f_1_arg_2)
{
  S_STRUCT_2 loc_var_1 = {0};
  S_STRUCT_8 loc_var_2;

  memset(&loc_var_2, 0, sizeof(loc_var_2));

  loc_var_2.s_8_f_4 = f_1_arg_2;
  loc_var_1.s_2_f_5 = f_1_arg_1;
  
  f_func_3(f_1_arg_1, f_1_arg_2);

  if (f_1_arg_2 & DEF_4)
  {
    f_ext_func_3(&loc_var_1, &loc_var_2); 
  }
  else
  {
    f_ext_func_2(&loc_var_1, &loc_var_2); 
  }
}

void f_func_to_analyze(const S_STRUCT_7* p_arg_1)
{
  const unsigned short loc_var_1   = 0;
  const unsigned int   loc_var_2   = p_arg_1->s_7_f_1;
  const S_STRUCT_3*    p_loc_var_3 = (void*)&(p_arg_1->s_7_f_2);
  const unsigned int   loc_var_4   = (unsigned int)(p_loc_var_3->s_3_f_1);

  f_func_1(p_loc_var_3->s_3_f_2.s_2_f_5, loc_var_1);
  f_func_2((unsigned char)p_loc_var_3->s_3_f_2.s_2_f_5, (unsigned char) p_loc_var_3->s_3_f_3, loc_var_4, loc_var_2);
}

int main(int argc, char* argv[])
{
  f_func_to_analyze((const S_STRUCT_7*)argv);
}

void _start(int argc, char* argv[])
{
   main(argc, argv);
}
