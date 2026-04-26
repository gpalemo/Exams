#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main (int ac, char **av)
{
    char *line;
    int i = 0;
    int j = 0;
    int k = 0;

    if (ac != 2)
        return 1;
    line = malloc(70000);
    if (!line)
    {
        perror("Error: ");
        return 1;
    }
    read(0,line,70000);
    if (!line)
    {
        perror("Error: ");
        free(line);
        return 1;
    }
    while (line[i])
    {
        while (line[i + j] == av[1][j])
            j++;
        if (av[1][j] == '\0')
        {
            while (k < j)
            {
                line[i + k] = '*';
                k++;
            }
        }
        i++;
        j = 0;
        k = 0;
    }
    printf("%s\n",line);
    free(line);
    return(0);
}