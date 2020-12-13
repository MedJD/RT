
#include "libft.h"

char			*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if ((str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+' ||
					str[i - 1] == '\0' || str[i - 1] == '\t' ||
					str[i - 1] == '\n') && (str[i] > 96 && str[i] < 123))
			str[i] -= 32;
		i++;
	}
	return (str);
}
