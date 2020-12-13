
#include "../headers/rt.h"

void			ft_plane_mapping(t_hit *rec, t_object *o)
{
	rec->u = ft_dot(ft_div_k(ft_sub(rec->p, o->pos), o->txt.scale * 10.0),
			o->j);
	rec->v = ft_dot(ft_div_k(ft_sub(rec->p, o->pos), o->txt.scale * 10.0),
			o->i);
	rec->u = rec->u - floor(rec->u);
	rec->v = rec->v - floor(rec->v);
}
