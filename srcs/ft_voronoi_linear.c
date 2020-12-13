
#include <rt.h>


t_color	ft_lerp(t_color a, t_color b, float f)
{
	return (ft_add_c(a, ft_pro_kc(COL(b.r - a.r, b.g - a.g, b.b - a.b), f)));
}

double	ft_frac(double value)
{
	return (value - floor(value));
}

float	ft_step(float a, float x)
{
	return (x >= a);
}

float	ft_smoothstep(float a, float b, float x)
{
	float t;

	if (b != a)
		t = ft_clamping((x - a) / (b - a));
	else
		t = ft_clamping(a);
	return (t * t * (3.0 - 2.0 * t));
}
