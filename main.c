#include "main.h"

char *removeSpaces(char *str, int no);
int strlength(char *str);

/**
* main - main function: where everything starts
* Return: integer
*/
int main()
{
    char *bufferText;
    ssize_t getLineOutput;
    size_t bufferTextSize = 0;
    char *eachStr;
    int eachStrLength;
    
    pid_t childProcess;
    int childProcessStatus;
    
    while (1)
    {
        char *strs[] = {NULL, NULL, NULL, NULL};
        int i;
        int strpos;
        
        int processCount;

        printf("OurShell $: ");

        getLineOutput = getline(&bufferText, &bufferTextSize, stdin);
        if(getLineOutput == -1)
        {
            free(bufferText);
            return (-1);
        }
        strpos = 0;
        eachStr = strtok(bufferText, "\n");
        while (eachStr != NULL)
        {
             eachStrLength = strlength(eachStr);
             eachStr = removeSpaces(eachStr, eachStrLength);

            strs[strpos] = eachStr;
            strpos++;

            eachStr = strtok(NULL, "\n");
        }

        for (i = 0; i <= strpos; i++)
        {
            if (strs[i] == NULL)
            {
                break;
            }
            printf("%s\n", strs[i]);
        }
        
        
        while (processCount < strpos)
        {
            childProcess = fork();
            if (childProcess < 0)
            {
                perror("");
                exit(1);
            }
            
            if (childProcess == 0)
            {
                char *argv[] = {NULL, NULL, NULL, NULL};
                argv[0] = strs[processCount];
                
                if (execve(argv[0], argv, NULL) < 0)
                {
                    perror("");
                    exit(1);
                }
                sleep(2);
            }
            
            if (childProcess > 1)
            {
                wait(&childProcessStatus);
            }
            
            processCount++;
        }
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
          isSpace2++;
        }
      }
    }
    aCount++;
  }
  return str;
}

