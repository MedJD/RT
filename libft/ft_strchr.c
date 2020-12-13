
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (*((char*)s + i) == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
