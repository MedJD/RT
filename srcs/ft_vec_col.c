
#include <rt.h>

t_vector	ft_coltovec(t_color c)
{
	return (VEC(c.r, c.g, c.b));
}

t_color		ft_vectocol(t_vector v)
{
	return (COL(v.v1, v.v2, v.v3));
}
