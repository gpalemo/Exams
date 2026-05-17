#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_read;
	static int buffer_pos;
	int i = 0;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(70000);
	if (!line)
		return (NULL);
	while (1)
	{
		
	}
}
int main()
{
    char *line;
    int fd;
    fd = open("file.txt", O_RDWR, 0644);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
    	line = get_next_line(fd);
	}
}
