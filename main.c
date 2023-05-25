#include "main.h"

/**
* main - main function: where everything starts
* Return: integer
*/
int main()
{
pid_t childProcessBatch;
int counter = 7;
int childProcessStatus;
extern char **environ;

while (counter > 5)
{
childProcessBatch = fork();
if (childProcessBatch < 0)
{
perror("");
exit(1);
}

if (childProcessBatch == 0)
{

char *bufferText;
ssize_t getLineOutput;
size_t bufferTextSize = 32;
char *eachStr;
char *argv[] = {NULL, NULL, NULL, NULL};

while (1)
{
printf("OurShell $ ");

getLineOutput = getline(&bufferText, &bufferTextSize, stdin);
if (getLineOutput == -1)
{
    free(bufferText);
    return (-1);
}

eachStr = strtok(bufferText, "\n");
while (eachStr != NULL)
{

    int strLength = strlength(eachStr);

    eachStr = removeSpaces(eachStr, strLength);

    argv[0] = eachStr;

    if (execve(argv[0], argv, environ) < 0)
    {
    perror("");
    exit(1);
    }
    sleep(2);

    eachStr = strtok(NULL, "\n");
}


}

}

if (childProcessBatch > 1)
{
wait(&childProcessStatus);
}

counter++;
}

return (0);
}



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

/**
* removeSpaces - function to remove spaces in a string
* @str: the string
* @no: length of string
* Return: formatted string
*/
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
