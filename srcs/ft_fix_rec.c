
#include "../headers/rt.h"

int		ft_fix_rec(t_hit *old, t_hit *new)
{
	old->p = new->p;
	old->t = new->t;
	old->n = new->n;
	old->u = new->u;
	old->v = new->v;
	old->surface = new->surface;
	old->i = new->i;
	old->j = new->j;
	return (1);
}
