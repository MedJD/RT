
#include <rt.h>

t_color		ft_get_texture(t_texture *t, double *u, double *v)
{
	int		i;
	int		j;
	Uint8	c[3];

	i = *u * t->surface->w;
	j = (1.0 - *v) * t->surface->h - 0.001;
	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	i = (i > t->surface->w - 1) ? t->surface->w - 1 : i;
	j = (j > t->surface->h - 1) ? t->surface->h - 1 : j;
	SDL_GetRGB(t->data[j * t->surface->w + i], t->surface->format,
			&c[0], &c[1], &c[2]);
	return (COL(c[0] / 255.99, (double)c[1] / 255.99,
				(double)c[2] / 255.99));
}
