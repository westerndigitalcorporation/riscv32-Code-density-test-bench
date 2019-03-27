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

char f_switch(char switch_type, char case_type);

char f_switch(char switch_type, char case_type)
{
  char ret = 0;
  char index = 0;
  
  switch (switch_type)
  {
  case 0x71:
    if ((case_type & 0x02) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    if ((case_type & 0x04) != 0)
    {
      ret |= 1 << index;
    }
    index++;
    break; 

  case 0x72:
    if ((case_type & 0x02) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    if ((case_type & 0x04) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    break;

  case 0x73:
    if ((case_type & 0x02) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    if ((case_type & 0x04) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    break;

  case 0x74:
    if ((case_type & 0x02) != 0)
    {
      ret |= 1 << index;
    }
    index++;

    if ((switch_type & 0x04) != 0)
    {
      ret |= 1 << index;
    }
    index++;
    break;
  default:
    break;
  }

  return ret;
}
