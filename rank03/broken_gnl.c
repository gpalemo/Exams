#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# define BUFFER_SIZE 42

char *ft_strdup(char *str)
{
    char *dup;
    int i;
    i = 0;

    while (str[i])
        i++;
    dup = malloc((sizeof(char) * i) + 1);
    if (!dup)
        return NULL;
    i = 0;
    while (str[i])
    {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buff_read;
    static int buff_pos;
    char line[70000];
    int i;
    i = 0;

    while (1)
    {
        if (buff_pos == buff_read)
        {
            buff_read = read(fd, buffer, BUFFER_SIZE);
            buff_pos = 0;
            if (buff_read < 0)
                return NULL;
        }
        line[i++] = buffer[buff_pos++];
        if (line[i - 1] == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
        return NULL;
    return ft_strdup(line);
}

int main()
{
    char *line;
    int fd;
    fd = open("file.txt", O_RDWR, 0644);
    line = get_next_line(fd);
    printf("%s", line);
}
