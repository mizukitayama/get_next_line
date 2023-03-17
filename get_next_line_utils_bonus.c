
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
	int	i;

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

char	*combine_strs(char *save, char *buf)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (save == NULL)
	{
		save = (char *)malloc(sizeof(char));
		save[0] = '\0';
	}
	if (save == NULL || buf == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buf) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (save != NULL)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buf[c] != '\0')
		str[i++] = buf[c++];
	str[ft_strlen(save) + ft_strlen(buf)] = '\0';
	free(save);
	return (str);
}