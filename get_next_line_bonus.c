/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:56:00 by mtayama           #+#    #+#             */
/*   Updated: 2024/06/04 21:13:31 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*free_and_null(char **save)
{
	free(*save);
	*save = NULL;
	return (NULL);
}

static char	*save_line(char *save)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (free_and_null(&save));
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (s == NULL)
		return (free_and_null(&save));
	i++;
	while (save[i] != '\0')
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

static char	*get_line(char *save)
{
	size_t	i;
	char	*s;

	i = 0;
	if (save[0] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*read_file(int fd, char *save)
{
	char	*buf;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
		{
			free(buf);
			return (free_and_null(&save));
		}
		buf[read_size] = '\0';
		save = combine_strs(save, buf);
		if (save == NULL || ft_strchr(save, '\n') != NULL)
			break ;
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[MAX_FD + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_file(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = get_line(save[fd]);
	if (line == NULL)
		return (free_and_null(&save[fd]));
	save[fd] = save_line(save[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	char *test = "";
// 	int fd = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	while (test)
// 	{
// 		test = get_next_line(fd);
// 		printf("%s", test);
// 		free(test);
// 		test = get_next_line(fd2);
// 		printf("%s", test);
// 		free(test);
// 	}
// 	close(fd);
// 	close(fd2);
// }
