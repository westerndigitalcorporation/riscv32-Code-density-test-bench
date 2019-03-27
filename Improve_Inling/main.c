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

#include "bad_inline.h"


unsigned long G_MyGlobalArr[5];


/* prototypes */
static void f_myStatic(unsigned short usArg1,
                       unsigned short usArg2,
                       unsigned long  ulArg3,
                       unsigned long *ulArg4_p,
                       S_MY_STRUCT   *sArg5_p);


/* functions */
void f_caller_master(unsigned short fileCode, unsigned short line, unsigned long resetCause, unsigned long *resetParams_p)
{

  S_MY_STRUCT *p = (void *)(unsigned long)(void*)(0xF000F000);

  f_myStatic(fileCode,line, resetCause, resetParams_p, p);


  for (;;){}

}

void f_my_caller(unsigned short argChar1, unsigned short argChar2, unsigned long argInt1, unsigned long *arr, S_MY_STRUCT *ptr)
{
  f_myStatic(argChar1, argChar2, argInt1, arr, ptr);
}


void f_my_caller2(unsigned short argChar1, unsigned short argChar2, unsigned long argInt1, unsigned long *arr, S_MY_STRUCT *ptr)
{
  f_myStatic(argChar1, argChar2, argInt1, arr, ptr);
}

#if D_CALLER_NUM_3
void f_my_caller3(unsigned short argChar1, unsigned short argChar2, unsigned long argInt1, unsigned long *arr, S_MY_STRUCT *ptr)
{
  f_myStatic(argChar1, argChar2, argInt1, arr, ptr);
}
#endif


static void f_myStatic(unsigned short usArg1,
                       unsigned short usArg2,
                       unsigned long  ulArg3,
                       unsigned long *ulArg4_p,
                       S_MY_STRUCT   *sArg5_p)
{
  unsigned long i;

  sArg5_p->sSecond.cc = usArg1;
  sArg5_p->sSecond.dd = usArg2;
  sArg5_p->sSecond.aa = 1;
  sArg5_p->sSecond.bb = 0xF;
  sArg5_p->ulArg2   = ulArg3;
  sArg5_p->ulArg4   = 0x2;


  if (sArg5_p == NULL)
  {
    ulArg4_p = G_MyGlobalArr;
  }


  for (i = 0 ; i < 5 ; i++)
  {
    sArg5_p->ulParamArr[i] = ulArg4_p[i];
  }

}



int main(int argc, char** argv)
{

	unsigned char argChar1 = (unsigned int)argv[0] + 10;
	unsigned char argChar2 = (unsigned int)argv[1] + 10;
	unsigned long argInt1   = (unsigned int)argv[2] + 20;
	unsigned long argInt2   = (unsigned int)argv[3] + 30;
	unsigned long i;
	unsigned long *arr = (unsigned long *)(unsigned long)(void*)(0xF000A000);

  //S_FA_RESET_AREA * resetArea_p = (S_FA_RESET_AREA *)(void *)M_RAM_FIXED_ADDRESS(0xF000F000);
  S_MY_STRUCT *p = (void *)(unsigned long)(void*)(0xF000F000);


  G_MyGlobalArr[0] = (unsigned int)argv[0];
  G_MyGlobalArr[1] = (unsigned int)argv[1];
  G_MyGlobalArr[2] = (unsigned int)argv[2];
  G_MyGlobalArr[3] = (unsigned int)argv[3];
  G_MyGlobalArr[4] = (unsigned int)argv[4];

	if (argc > 0)
	{
	  /* use the function more then once */
	  for(i=0; i<argc+40; i++)
	  {
	    f_myStatic(argChar1+i, argChar2+i, argInt1+i, arr, p);
	  }

		/* call depend on unknown*/
	  f_caller_master(argChar1, argChar2, argInt1, arr);
	}

}


void _start(int argc, char** argv)
{
	main(argc, argv);
}

