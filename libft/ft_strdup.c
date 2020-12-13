
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;
	int		size;

	i = 0;
	size = 0;
	while (s1[size] != '\0')
		size++;
	cpy = (char*)malloc(sizeof(char) * (size + 1));
	if (!(cpy))
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = *(s1 + i);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
