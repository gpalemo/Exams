#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *appendbuffer(char *buffer, char *line, int bytes_read)
{
	int i = 0;
	int j = 0;

	while (line[i])
		i++;
	line = realloc(line, i + bytes_read + 1); // ATTENTION !!!!!!!!!!!!!
	while (j < bytes_read)
		line[i++] = buffer[j++];
	line[i] = '\0';
	return (line);
}

int main(int ac, char **av)
{
	char *line;
	char buffer[70000];
	int i = 0;
	int j = 0;
	int k = 0;
	int bytes_read;

	if (ac != 2 || av[1][0] == '\0')
		return (1);
	line = malloc(1);
	if (!line)
		return (perror("Error"), 1);
	line[0] = '\0'; // ATTENTION !!!!!!!!!!!!!!
	bytes_read = read(0, buffer, 1);
	while (bytes_read > 0)
	{
		line = appendbuffer(buffer, line, bytes_read);
		if (!line)
			return (perror("Error"), 1);
		bytes_read = read(0, buffer, 1);
	}
	if (bytes_read < 0)
		return (perror("Error"), free(line), 1);
	while (line[i])
	{
		while (av[1][j] && line[i + j] == av[1][j])
			j++;
		if (av[1][j] == '\0')
		{
			while (k < j)
				line[i + k++] = '*';
			i += j;
		}
		else
			i++;
		j = 0;
		k = 0;
	}
	printf("%s", line);
	free(line);
	return (0);
}

