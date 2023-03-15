
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
		return ((char *)s);
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*combine_strs(char *buf, char *read_str)
{
	char	*combined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (buf == NULL && read_str != NULL)
	{
		combined = (char *)malloc(sizeof(char) * (ft_strlen(read_str) + 1));
		if (combined == NULL)
			return (NULL);
		while (read_str[i] != '\0')
		{
			combined[i] = read_str[i];
			i++;
		}
		return (combined);
	}
	combined = (char *)malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(read_str) + 1));
	if (combined == NULL)
		return (NULL);
	while (buf[i] != '\0')
	{
		combined[i] = buf[i];
		i++;
	}
	while (read_str[j] != '\0')
	{
		combined[i] = read_str[j];
		i++;
		j++;
	}
	combined[i] = '\0';
	free(read_str);
	return (combined);
}