#include "main.h"

/**
* strlength - get a string's length
* @str: the string
* Return: length of string in integer
*/
int strlength(char *str)
{
  int len = 0;
  
  while (str[len])
  {
    len++;
  }
  
  return (len);
}
