
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

