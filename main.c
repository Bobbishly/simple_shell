#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
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
size_t getLineOutput;
size_t bufferTextSize = 32;
size_t i;
size_t j;
char newLine = '\n';
char *argv[] = {NULL, NULL, NULL, NULL};

printf("OurShell $ ");

bufferText = malloc(sizeof(char) * bufferTextSize);

getLineOutput = getline(&bufferText, &bufferTextSize, stdin);

for (i = 0; i < getLineOutput; i++)
{
if (bufferText[i] == newLine)
{
for (j = i; j < getLineOutput; j++)
{
bufferText[j] = bufferText[j + 1];
}
getLineOutput--;
i--;
}
}

argv[0] = bufferText;
  
free(bufferText);

if (execve(argv[0], argv, environ) < 0)
{
perror("");
exit(1);
}
sleep(2);
}

if (childProcessBatch > 1)
{
wait(&childProcessStatus);
}

counter++;
}

return (0);
}
