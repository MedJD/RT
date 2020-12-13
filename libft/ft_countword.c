
#include "libft.h"

int		ft_countword(const char *str, char c)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			size++;
		}
	}
	return (size);
}
