
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;

	i = 0;
	while (i < (int)n)
	{
		*((char*)dst + i) = *((char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
