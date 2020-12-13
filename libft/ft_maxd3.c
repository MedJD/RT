
#include "libft.h"

double	ft_maxd3(double a, double b, double c)
{
	double tmp;

	tmp = a < b ? b : a;
	return (tmp < c ? c : tmp);
}
