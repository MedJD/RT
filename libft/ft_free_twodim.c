
#include "libft.h"

void	ft_free_twodim(char ***to)
{
	char	**to_free;
	int		i;

	i = 0;
	to_free = *to;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}
