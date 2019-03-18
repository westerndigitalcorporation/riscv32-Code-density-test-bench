/* 
* SPDX-License-Identifier: Apache-2.0
* Copyright 2019 Western Digital Corporation or its affiliates.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http:*www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
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
