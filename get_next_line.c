
#include "get_next_line.h"



#include <stdio.h>

char	*save_line(char *buf)
{
	size_t	i;
	size_t	j;
	char	*save;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (NULL);
	save = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (save == NULL)
		return (NULL);
	j = 0;
	i++;
	while (i < ft_strlen(buf))
		save[j++] = buf[i++];
	save[j] = '\0';
	return (save);
}

char	*get_line(char *buf, char *save)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (save == NULL && (buf == NULL || ft_strlen(buf) == 0))
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = buf[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_file(int fd, char *buf)
{
	ssize_t	r_size;
	char	*read_str;

	buf = NULL;
	while (1)
	{
		read_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (read_str == NULL)
			return (NULL);
		r_size = read(fd, read_str, BUFFER_SIZE);
		if (r_size == 0)
		{
			free(read_str);
			break;
		}
		read_str[r_size] = '\0';
		buf = combine_strs(buf, read_str);
		if (ft_strchr(buf, '\n') != NULL)
			break;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*save;
	buf = read_file(fd, buf);
	line = get_line(buf, save);
	save = save_line(buf);
	if (buf != NULL)
		free(buf);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
	char *test = "";
	int fd = open("./text.txt", O_RDONLY);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);
	test = get_next_line(fd);
	printf("%s\n", test);
	free(test);

}