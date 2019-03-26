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

#include <stdio.h>

int foo(void);
int getStart(int pivot);
int getEnd(int pivot);
int getLCM(int a, int b);

int foo(void)
{
	int i=0;
	int j=100;
	int x=0;

	i=getStart(i);
	j=getEnd(j);
	j=getLCM(i, j);
	for(i; i< j; i++)
		x += i;
	return 0;
}

int getStart(int pivot)
{
	int start = 0;
	if (pivot > 0)
		start = pivot;
	else
		start = 100;
	return start;
}

int getEnd(int pivot)
{
	int end = 0;
	if (pivot > 0)
		end = pivot;
	else
		end = 100;
	return end;
}

int getLCM(int a, int b)
{
   int num1, num2, maxValue, result;

   num1 = a;
   num2 = b;
   maxValue = (num1 > num2) ? num1 : num2;

   while(1)  
   {
      if ((maxValue % num1 == 0) && (maxValue % num2 == 0))
      {
         result = maxValue;
         break;
      }
      ++maxValue;
   }
   return result;
}
