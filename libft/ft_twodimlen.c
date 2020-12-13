
#include "libft.h"

int		ft_twodimlen(char **twodim)
{
	int		s;

	s = 0;
	while (*twodim++)
		s++;
	return (s);
}
