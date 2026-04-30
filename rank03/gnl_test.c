#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 42
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_read;
	char *line;
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(70000);
	if (!line)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read (fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		line[i++] = buffer[buffer_pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (free(line), NULL);
	return (line);
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
