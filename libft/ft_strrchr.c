
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (*(char*)s == '\0' && size == 1)
		return ((char*)s);
	while (size)
	{
		if (*((char*)s + size) == (char)c)
			return ((char*)s + size);
		size--;
	}
	if (*((char*)s + size) == (char)c)
		return ((char*)s + size);
	return (NULL);
}
