
#include <rt.h>

void		ft_move_triangle(t_object *o)
{
	o->i = ft_add(o->i, o->pos);
	o->j = ft_add(o->j, o->pos);
	o->k = ft_add(o->k, o->pos);
}

void		ft_pos_cylinder(t_object *o)
{
	if (o->weight == 1.0)
	{
		o->cont->pos = o->pos;
		o->cont->cont->pos = o->pos;
	}
	if (o->weight == 2.0)
	{
		o->cont->pos = o->pos;
		o->cont->cont->pos = ft_add(o->pos, ft_pro_k(o->i, -o->size / 2.0));
		o->cont->cont->cont->pos =
			ft_add(o->pos, ft_pro_k(o->j, -o->size / 2.0));
	}
}

void		ft_pos(t_object *o)
{
	if (strcmp(o->name, "CYLINDER") == 0)
	{
		ft_pos_cylinder(o);
		return ;
	}
	o->cont->pos.v1 = o->pos.v1 + o->weight * o->rot.v1;
	o->cont->pos.v2 = o->pos.v2 + o->weight * o->rot.v2;
	o->cont->pos.v3 = o->pos.v3 + o->weight * o->rot.v3;
	o->cont->cont->pos.v1 = o->pos.v1 - o->weight * o->rot.v1;
	o->cont->cont->pos.v2 = o->pos.v2 - o->weight * o->rot.v2;
	o->cont->cont->pos.v3 = o->pos.v3 - o->weight * o->rot.v3;
	o->cont->cont->cont->pos.v1 = o->pos.v1 + o->height * o->j.v1;
	o->cont->cont->cont->pos.v2 = o->pos.v2 + o->height * o->j.v2;
	o->cont->cont->cont->pos.v3 = o->pos.v3 + o->height * o->j.v3;
	o->cont->cont->cont->cont->pos.v1 = o->pos.v1 - o->height * o->j.v1;
	o->cont->cont->cont->cont->pos.v2 = o->pos.v2 - o->height * o->j.v2;
	o->cont->cont->cont->cont->pos.v3 = o->pos.v3 - o->height * o->j.v3;
	o->cont->cont->cont->cont->cont->pos.v1 = o->pos.v1 + o->size * o->i.v1;
	o->cont->cont->cont->cont->cont->pos.v2 = o->pos.v2 + o->size * o->i.v2;
	o->cont->cont->cont->cont->cont->pos.v3 = o->pos.v3 + o->size * o->i.v3;
	FC->pos.v1 = o->pos.v1 - o->size * o->i.v1;
	FC->pos.v2 = o->pos.v2 - o->size * o->i.v2;
	FC->pos.v3 = o->pos.v3 - o->size * o->i.v3;
}

int			ft_rot_obj(t_ptr *p, t_vector (*ft_rot)(t_vector, double))
{
	t_object	*tt;

	tt = PSC;
	while (PSC)
	{
		PSC->rot = ft_rot(PSC->rot, p->inc_dec * DEG_TO_RAD(THA));
		PSC->i = ft_rot(PSC->i, p->inc_dec * DEG_TO_RAD(THA));
		PSC->j = ft_rot(PSC->j, p->inc_dec * DEG_TO_RAD(THA));
		PSC->k = ft_rot(PSC->k, p->inc_dec * DEG_TO_RAD(THA));
		PSC = PSC->cont;
	}
	PSC = tt;
	if (strcmp(tt->name, "CUBE") == 0 || strcmp(tt->name, "CYLINDER") == 0)
		ft_pos(tt);
	return (1);
}
