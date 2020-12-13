
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*dest;
	int		i;

	dest = (char*)b;
	i = 0;
	while (i < (int)len)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	b = (void*)dest;
	return (b);
}
