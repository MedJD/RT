
#include <rt.h>

void	ft_cube_ijk(t_object *obj)
{
	ft_add_conts(obj, ft_pro_k(obj->rot, obj->weight), 0, obj);
	ft_add_conts(obj->cont, ft_pro_k(obj->rot, -obj->weight), 0, obj);
	ft_add_conts(obj->cont->cont, ft_pro_k(obj->j, obj->height), 1, obj);
	ft_add_conts(obj->cont->cont->cont, ft_pro_k(obj->j, -obj->height), 1, obj);
	ft_add_conts(obj->cont->cont->cont->cont,
			ft_pro_k(obj->i, obj->size), 2, obj);
	ft_add_conts(obj->cont->cont->cont->cont->cont,
			ft_pro_k(obj->i, -obj->size), 2, obj);
}
