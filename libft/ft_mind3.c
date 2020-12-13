
#include "libft.h"

double		ft_mind3(double a, double b, double c)
{
	double	tmp;

	tmp = a < b ? a : b;
	return (tmp < c ? tmp : c);
}
