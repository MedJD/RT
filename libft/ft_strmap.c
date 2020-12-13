
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fraiche;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i])
		i++;
	if (!(fraiche = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	fraiche[i] = '\0';
	i--;
	while (i >= 0)
	{
		fraiche[i] = f(s[i]);
		i--;
	}
	return (fraiche);
}
