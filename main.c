#include "main.h"

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
    char *argv[] = {NULL, NULL, NULL, NULL};
    char *strs[] = {NULL, NULL, NULL, NULL};
    int strpos = 0;
    int eachStrLength;
    
    while (1)
    {
        printf("OurShell $: ");

        getLineOutput = getline(&bufferText, &bufferTextSize, stdin);
        if(getLineOutput == -1)
        {
            free(bufferText);
            return (-1);
        }

        eachStr = strtok(bufferText, "\n");
        while (eachStr != NULL)
        {
            eachStrLength = strlength(eachStr);
            eachStr = removeSpaces(eachStr, eachStrLength);

            strs[strpos] = eachStr;
            strpos++;

            eachStr = strtok(NULL, "\n");
        }
    }

    for (int i = 0; i <= strpos, i++)
    {
        printf("%s\n", strs[i]);
    }


    return (0);
}
