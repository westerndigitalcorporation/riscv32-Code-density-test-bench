
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
