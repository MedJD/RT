
#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] > 96 && str[i] < 123) && !(str[i] > 64 && str[i] < 91))
		{
			return (0);
			str[i] = '\0';
		}
		i++;
	}
	return (1);
}
