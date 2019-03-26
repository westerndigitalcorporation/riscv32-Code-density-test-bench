
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

/* Defines */
#define D_MAX                (2)
#define TEST_DATA_BASE_ADDR  (0xC00A8000)

/* typedef */
typedef unsigned char  U_08 ;
typedef unsigned short U_16 ;
typedef unsigned int   U_32 ;


typedef struct  
{
  U_32 one : 1;
  U_32 two : 1;
  U_32 res : 30;
} S_FLAGS;

typedef struct 
{
  S_FLAGS flag;
  U_32    res;
}S_FIRST, *S_FIRST_P;

typedef struct  
{
  S_FIRST   Array[4]; 
  S_FIRST_P Array_p[4]; 
  U_32      var1;
  U_08      var2;
  U_08      var3;
} S_ENTRY;


typedef struct 
{
  S_ENTRY entries[0xff];
  U_32    res;
}S_SECOND;







/* Globals */
S_SECOND G_For_test;

void *G_headerBuffers = (void*)TEST_DATA_BASE_ADDR;


static void * f_TestUnroll(unsigned outer, unsigned inner);


//Main 
void main(int argc, char** argv)
{
  void * ptr;

  ptr = f_TestUnroll(2, 4);
  ptr = f_TestUnroll(3, 4);
  

  // checkpoint 1
  // checkpoint 2
  // checkpoint 3

}



__attribute__((noinline))
static void * f_TestUnroll(unsigned outer, unsigned inner)
{
  U_32    index = 7;
  U_32    i;
  S_ENTRY *entry_p;
  U_08    *headers_p;
  U_32    k;
  void    *returnPtr;
  
  headers_p = (U_08*)&G_headerBuffers;


  for(i=0;i<outer;i++)
  {    
    entry_p = &G_For_test.entries[index+i];
    entry_p->var1 = 4;
    entry_p->var2 = 0;
    entry_p->var3 = 0x10;

    for(k=0;k<inner;k++)
    {
      entry_p->Array_p[k] = (S_FIRST_P)(headers_p + sizeof(int)*(i*4+k));
      entry_p->Array_p[k]->flag.one = 0;
    }
  }

  return returnPtr;
}


