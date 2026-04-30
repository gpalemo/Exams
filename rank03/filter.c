#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*appendbuffer(char *buffer, char *line, int bytes_read)
{
	int i = 0;
	int j = 0;

	while (line[i])
		i++;
	line = realloc(line, i + bytes_read);
	while (j < bytes_read)
	{
		line[i] = buffer[j];
		i++;
		j++;
	}
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

	if (ac != 2)
		return (1);
	line = malloc(2);
	if (!line)
	{
		perror ("Error :");
		return (1);
	}
	line[1] = '\0';
	bytes_read = read(0, buffer, 1);
	while (bytes_read > 0)
	{
		line = appendbuffer(buffer, line, bytes_read);
		bytes_read = read(0,buffer, 1);
		if (bytes_read < 0)
		{
			perror("Error : ");
			free(line);
			return (1);
		}
	}
	if (av[1][0] == '\0')
	{
		free (line);
		return (1);
	}
	while (line[i])
	{
		while (line[i + j] == av[1][j])
			j++;
		if (av[1][j] == '\0')
		{
			while (k < j)
			{
				line [i + k] = '*';
				k++;
			}
		}
		i++;
		k = 0;
		j = 0;
	}
	printf("%s\n", line);
	free (line);
	return (0);
}

