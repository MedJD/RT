
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cas;

	cas = (char*)malloc(sizeof(char) * len);
	ft_memcpy(cas, src, len);
	ft_memcpy(dst, cas, len);
	return ((void*)dst);
}
