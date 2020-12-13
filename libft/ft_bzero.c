
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*dest;

	i = 0;
	if (n)
	{
		dest = (char*)s;
		while (i < (int)n)
		{
			dest[i] = 0;
			i++;
		}
		s = (void*)dest;
	}
}
