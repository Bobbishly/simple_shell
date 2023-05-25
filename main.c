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
