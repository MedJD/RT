
#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = *((char*)src + i);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
