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

extern signed int f_get_zero(const int FirstArg, int SecondArg);
extern signed int f_get_one(const int FirstArg, int SecondArg);

int G_NONE_ONE, G_ONE;

signed int f_get_number(const int FirstArg, int SecondArg)
{

  if ((G_NONE_ONE != 1 ) || (G_ONE == 1))
  {
     return(f_get_zero(FirstArg, SecondArg));
  }

  return(f_get_one(FirstArg, SecondArg));
}

int main(int argc, char** argv)
{
	int arg1;
	int arg2;
  
	arg1 = (int)*argv[0];
	arg2 = (int)*argv[1];
  G_ONE = (int)*argv[2];
  G_NONE_ONE = (int)*argv[3];

	f_get_number(arg1, arg2);
}


void _start(int argc, char** argv)
{
	main(argc, argv);
}
