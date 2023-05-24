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

printf("OurShell $ ");

bufferText = malloc(sizeof(char) * bufferTextSize);

getLineOutput = getline(&bufferText, &bufferTextSize, stdin);

size_t i;
size_t j;
char newLine = '\n';

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

char *argv[] = {bufferText, NULL, NULL, NULL};

free(bufferText);

if (execve(argv[0], argv, NULL) < 0)
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
