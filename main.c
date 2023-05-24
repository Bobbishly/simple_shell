#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include "simpleshell.h"

int main()
{
    

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

            bufferText = malloc(sizeof(char) * bufferTextSize);

            getLineOutput = getline(&bufferText, &bufferTextSize, stdin);

            size_t i, j;
            char newLine = '\n';

            

            char *argv[] = {bufferText, NULL, NULL, NULL};

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

    
}
