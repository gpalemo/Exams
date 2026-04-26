#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int ac, char **av)
{
    char *line;
    int i = 0;
    int j = 0;
    int k = 0;
    int bytes_read;

    if (ac != 2)
        return 1;
    line = malloc(70000);
    if (!line)
    {
        perror("Error: ");
        return 1;
    }
    bytes_read = read(0, line, 70000 - 1);
    if (bytes_read < 0)
    {
        perror("Error: ");
        free(line);
        return 1;
    }
    line[bytes_read] = '\0';
    if (av[1][0] == '\0')
    {
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
    printf("%s",line);
    free(line);
    return(0);
}
