/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayama <mtayama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:57:32 by mtayama           #+#    #+#             */
/*   Updated: 2024/05/25 14:47:35 by mtayama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (str == NULL)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static char	*execute_combine_strs(char *save, char *buf, char *str)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (save != NULL)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(save) + ft_strlen(buf)] = '\0';
	free(save);
	return (str);
}

char	*combine_strs(char *save, char *buf)
{
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char));
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
	}
	if (buf == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buf) + 1));
	if (str == NULL)
		return (NULL);
	return (execute_combine_strs(save, buf, str));
}
