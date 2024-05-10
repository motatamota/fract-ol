#include "fractol.h"

void	cir(t_viwinfo *viw)
{
	int		p;
	double	x;

	p = 0;
	viw->x = 0;
	viw->y = 0;
	while (p < ACC)
	{
		if (viw->x * viw->x + viw->y * viw->y > 2)
		{
			mlx_pixel_put(viw->mlx, viw->win, viw->n, viw->m, 100000);
			return ;
		}
		x = viw->x;
		viw->x = viw->x * viw->x - viw->y * viw->y + ((viw->a + viw->pos[0]) * viw->math - 2);
		viw->y = 2 * x * viw->y + ((viw->b + viw->pos[1]) * viw->math - 2);
		p++;
	}
	mlx_pixel_put(viw->mlx, viw->win, viw->n, viw->m, 0);
}

void	initialize(t_viwinfo *viw)
{
	viw->pos[0] = 0;
	viw->pos[1] = 0;
	viw->scal = 0;
	viw->x = 0;
	viw->y = 0;
}

void	mandel(t_viwinfo *viw)
{
	viw->n = 0;
	while (viw->n < SIZE)
	{
		viw->m = 0;
		while (viw->m < SIZE)
		{
			viw->a = (double)viw->n;
			viw->b = (double)viw->m;
			cir(viw);
			viw->m += 1;
		}
		viw->n += 1;
	}
	mlx_hook(viw->win, 2, 1L<<0, keymove, viw);
	mlx_hook(viw->win, 4, 1L<<2, mousemove, viw);
}

int main()
{
	t_viwinfo viw;

	initialize(&viw);
	viw.mlx = mlx_init();
	viw.win = mlx_new_window(viw.mlx, SIZE, SIZE, "fract-ol");
	viw.math = (double)4 / SIZE;
	if (1)
		mandel(&viw);
	mlx_loop(viw.mlx);
	return 0;
}
