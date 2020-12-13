
#include <rt.h>

int			ft_hit(t_scene *s, t_ray r, t_interval t, t_hit *rec)
{
	double		closest_so_far;
	int			hit_anything;
	t_object	*obj;

	hit_anything = 0;
	closest_so_far = t.t_max;
	obj = s->object;
	rec->surface = NOT_PLANE;
	while (obj)
	{
		if (obj->hit(obj, &r, I(t.t_min, closest_so_far), rec))
		{
			hit_anything = 1;
			closest_so_far = rec->t;
			rec->col = obj->col;
			rec->hit = obj->hit;
			rec->curr_obj = obj;
			rec->ray = r;
		}
		obj = obj->next;
	}
	return (hit_anything);
}
