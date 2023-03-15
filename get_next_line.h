#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 4

#include <stdlib.h>
#include <unistd.h>

char	*combine_strs(char *dep, char *buff);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif