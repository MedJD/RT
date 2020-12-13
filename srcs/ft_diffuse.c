
#include <rt.h>

t_color			diffuse(t_scene *s, t_light *l)
{
	t_vector	light_vec;
	t_color		c;
	double		dn;

	if (l->type == P_LIGHT)
		light_vec = ft_normalize(ft_sub(l->pos, s->record.p));
	else
		light_vec = ft_pro_k(l->dir, -1);
	dn = ffmax(ft_dot(light_vec, s->record.n), 0.0);
	c = ft_pro_kc(ft_pro_c(s->record.col, l->col), dn);
	return (c);
}
