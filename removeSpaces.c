#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeSpaces(char *str, int no)
{
  int isSpace = 0;
  int isSpace2 = 0;
  
  int aCount = 0;
  
  while (aCount < no)
  {
    for (isSpace = 0; isSpace < no; isSpace++)
    {
      if (str[isSpace] == ' ')
      {
        isSpace2 = isSpace;
        
        while (str[isSpace2])
        {
          str[isSpace2] = str[isSpace2 + 1];
          isSpace++;
        }
      }
    }
    aCount++;
  }
  return str;
}