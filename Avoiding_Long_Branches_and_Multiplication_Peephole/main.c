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

#define ZERO   0
#define ONE    1
#define TWO    2
#define THREE  3
#define MAX    15
#define M_GET(index)  (g_table.arr[index].fieldb)

typedef struct
{
  unsigned char  f_1;
  unsigned char  f_2;
  unsigned char  f_3;
  unsigned char  f_4;
  unsigned char  f_5;
  unsigned char  f_6;
  unsigned short f_7;
  unsigned short f_8;
} ST_1;

typedef struct
{
  unsigned int a[513];
  unsigned int st2_tbl[THREE][THREE][THREE];
} ST_2;

typedef struct
{
  unsigned char fielda;
  unsigned char fieldb;
  unsigned char fieldc;
  unsigned char fieldd;
} ST_4;

typedef struct
{
  ST_4 arr[THREE];
}ST_3;

ST_3  g_table;
ST_2* g_st2_p = (void*)0x80010000;
ST_1  task;

unsigned char foo(const ST_1* st_1_p)
{
  unsigned int a;
  unsigned int d;
  ST_2 *st2_p = g_st2_p;

  a = st_1_p->f_6;

  if (a == MAX)
  {
     return ONE;
  }

  d = M_GET(st_1_p->f_3);

  if (st_1_p->f_8 == st2_p->st2_tbl[d][ZERO][ONE])
  {
     return ((st_1_p->f_6 == ZERO) || (st_1_p->f_7 == st2_p->st2_tbl[TWO][a][ONE]));
  }

  return ZERO;
}

void main(void)
{
   if (foo(&task) == ZERO)
   {
      task.f_3++;
   }
}

void _start()
{
   main();
}
