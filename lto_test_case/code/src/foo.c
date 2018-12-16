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