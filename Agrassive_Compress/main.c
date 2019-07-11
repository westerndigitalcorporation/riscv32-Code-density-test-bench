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

typedef struct TAG_S_ST_0
{
   unsigned int st_0_field_1;
   unsigned int st_0_field_2;
   unsigned int st_0_field_3; 
}S_ST_0;

typedef enum TAG_E_0
{
   E_0_V_1,
   E_0_V_2,
   E_0_V_3,
   E_0_V_4,
   E_0_V_5,
   E_0_V_LAST = 0xFFFFFFFF
} E_0;

typedef struct TAG_S_ST_1
{
   unsigned char st_1_field_0;
   unsigned char st_1_field_1;
} S_ST_1;

typedef union TAG_U_UN_0
{
   unsigned short value;
   S_ST_1 fields;
} U_UN_0;

#define D_INVALID         (255)
#define D_MASK           (0xFF00FF00)
#define D_FIXED_ADDRESS  (0xF0007400)

static inline unsigned int func_4(unsigned int arg1, E_0 arg2)
{
   U_UN_0 loc_1;

   loc_1.fields.st_1_field_0 = (unsigned char)arg1;
   loc_1.fields.st_1_field_1 = (unsigned char)arg2;

   loc_1.fields.st_1_field_1 &= (arg1 == D_INVALID) - 1;

   return loc_1.value;
}

static inline unsigned int func_1(unsigned int arg1, E_0 arg2)
{
   return func_4(arg1, arg2);
}

static inline unsigned int func_5(unsigned int arg1)
{
   return ((arg1 & D_MASK) != 0);
}

static inline unsigned int func_2(unsigned int arg1)
{
   if (func_5(arg1))
   {
      return *((unsigned int*)D_FIXED_ADDRESS);
   }

   return 0;
}

void func_3(S_ST_0* p_st_0, unsigned int arg1, unsigned int arg2)
{
   unsigned int i;
   for (i = 0 ; i < arg1 ; i++)
   {
      p_st_0->st_0_field_3 += arg2;
   }   
}

void func_code_density(S_ST_0* p_st_0)
{
   unsigned int loc_1;
   unsigned int loc_2;

   if (p_st_0->st_0_field_2 != D_INVALID)
   {
      loc_1 = func_1(p_st_0->st_0_field_2, E_0_V_4);
      loc_2 = func_2(loc_1);

      func_3(p_st_0, loc_1, loc_2);
   }
}

void helper_fumc_1(S_ST_0* p_st_0)
{
   unsigned int loc_1;
   unsigned int loc_2;

   loc_1 = func_1(p_st_0->st_0_field_2 + *((unsigned int*)0x80000010), E_0_V_4);
   loc_2 = func_2(loc_1);

   func_3(p_st_0, loc_1, loc_2);
}

void helper_fumc_2(S_ST_0* p_st_0)
{
   unsigned int loc_1;
   unsigned int loc_2;

   loc_1 = func_1(p_st_0->st_0_field_2 + *((unsigned int*)0x80000020), E_0_V_4);
   loc_2 = func_2(loc_1);

   func_3(p_st_0, loc_1, loc_2);
}

void helper_fumc_3(S_ST_0* p_st_0)
{
   unsigned int loc_1;
   unsigned int loc_2;

   loc_1 = func_1(p_st_0->st_0_field_2 + *((unsigned int*)0x80000050), E_0_V_4);
   loc_2 = func_2(loc_1);

   *((unsigned int*)0x80000000) = loc_1;
   *((unsigned int*)0x80000020) = loc_2;
}

void helper_fumc_4(S_ST_0* p_st_0)
{
   unsigned int loc_1;
   unsigned int loc_2;

   loc_1 = func_1(p_st_0->st_0_field_2 + *((unsigned int*)0x80000050), E_0_V_4);
   loc_2 = func_2(loc_1);

   *((unsigned int*)0x8000001A) = loc_1;
   *((unsigned int*)0x8000002A) = loc_2;
}

void main(int argc, char* argv[])
{
   func_code_density((S_ST_0*)argv[0]);
   helper_fumc_1((S_ST_0*)argv[1]);
   helper_fumc_2((S_ST_0*)argv[2]);
   helper_fumc_3((S_ST_0*)argv[3]);
   helper_fumc_4((S_ST_0*)argv[4]);
}

void _start(int argc, char* argv[])
{
   main(argc, argv);
}
