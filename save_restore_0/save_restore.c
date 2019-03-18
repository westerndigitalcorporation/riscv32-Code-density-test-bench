
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

#include "save_restore.h"




void bar(unsigned int arg1, unsigned int arg2)
{


  S_SEC_ARG Input;
  S_ABCD pAbcd = {0};

  Input.aa = arg2;
  pAbcd.a = arg1;

  foo(&pAbcd, &Input);
}




int main(int argc, char** argv)
{
	unsigned int arg1;
	unsigned int arg2;
	arg1 = (unsigned int)argv[0] + 10;
	arg2 = (unsigned int)argv[1] + 10;

	bar(arg1, arg2);
}


void _start(int argc, char** argv)
{
	main(argc, argv);
}

