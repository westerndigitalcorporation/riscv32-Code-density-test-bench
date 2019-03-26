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

#include<stdio.h>
#include <stdint.h>
#include <string.h>


typedef struct TAG_S_StructB
{
   unsigned int var1 : 12;
   unsigned int var2 : 2;
   unsigned int var3 : 2;
   unsigned int var4 : 12;
   unsigned int var5 : 4;
}S_StructB;

typedef struct TAG_S_StructInfo
{
   int x;					        
   S_StructB s_arr[2];    
   int a;                  
} S_StructInfo;

typedef struct TAG_CMN_PARAMS
{
   unsigned int data1;
   unsigned int data2;
   unsigned int data3;

}S_CMN_PARAMS;

typedef struct TAG_S_StructA
{
   int a;
   S_StructB* p_List;
   int x;
}S_StructA;

int  my_memcpy(S_StructA* params_p)
{
  S_StructInfo Info;
  //info("1"); 
  memcpy(&Info.s_arr[0],&params_p->p_List[0],sizeof(Info.s_arr[0]));
  //info("2");
  //end_tst_print(0);
  return Info.s_arr[0].var5;

}


int main(int argc, char* argv[])
{
   S_StructA params_p;
   return my_memcpy(&params_p);
}
