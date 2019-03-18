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
