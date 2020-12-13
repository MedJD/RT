
#include "../headers/rt.h"

void		ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
	if (x >= 0 && x < IMG_WIDTH
			&& y >= 0 && y < IMG_HEIGHT)
	{
		p->data[y * (int)IMG_WIDTH + x] = color;
	}
}
