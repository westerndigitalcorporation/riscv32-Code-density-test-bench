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

/*
* @file     save_restore.h
*
*
******************************************************************************/

#ifndef _SAV_RST
#define _SAV_RST



typedef struct
{
  unsigned int a : 13;
  unsigned int b : 1;
  unsigned int c : 2;
  unsigned int d : 12;
  unsigned int e : 4;
}S_ABCD;


typedef struct
{
  unsigned int  aa;
  unsigned int  bb;
  unsigned short  cc;
  unsigned short   dd;
  unsigned short   ee;
  unsigned short   ff;
}S_SEC_ARG;



void foo(const S_ABCD*   argAdd_p,  const S_SEC_ARG* argCmnIn_p);




#endif
