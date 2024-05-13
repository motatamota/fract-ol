/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:49:58 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/10 19:49:58 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cir(t_viwinfo *viw)
{
	int		p;
	double	x;
	double	a;
	double	b;

	p = -1;
	viw->x = 0;
	viw->y = 0;
	a = ((viw->n - SIZE / 2) / pow(SCALE, viw->scal) + (double)viw->pos[0] * \
			(double)MOVE + (double)SIZE / 2) * viw->math - 2.5;
	b = ((viw->m - SIZE / 2) / pow(SCALE, viw->scal) + (double)viw->pos[1] * \
			(double)MOVE + (double)SIZE / 2) * viw->math - 2.0;
	while (++p < ACC)
	{
		if (viw->x * viw->x + viw->y * viw->y >= 6)
		{
			my_mlx_pixel_put(&(viw->img), viw->n, viw->m,
				colorset((double)p, viw));
			return ;
		}
		x = viw->x;
		viw->x = viw->x * viw->x - viw->y * viw->y + a;
		viw->y = 2 * x * viw->y + b;
	}
	my_mlx_pixel_put(&(viw->img), viw->n, viw->m, 0);
}

void	calculation(t_viwinfo *viw)
{
	viw->n = 0;
	while (viw->n < SIZE)
	{
		viw->m = 0;
		while (viw->m < SIZE)
		{
			cir(viw);
			viw->m += 1;
		}
		viw->n += 1;
	}
}

void	initialize(t_viwinfo *viw)
{
	viw->pos[0] = 0;
	viw->pos[1] = 0;
	viw->scal = 0;
	viw->x = 0;
	viw->y = 0;
	viw->arg = 0;
}

void	mandel(t_viwinfo *viw)
{
	calculation(viw);
	mlx_hook(viw->win, 2, 1L << 0, keymove, viw);
	mlx_hook(viw->win, 4, 1L << 2, mousemove, viw);
}

int	main(int ac, char **av)
{
	t_viwinfo	viw;
	t_data		img;

	if (ac == 1 || ac == 3 || ac > 4 || checker(ac, av))
	{
		ft_printf("Check the arguments...\n");
		return (1);
	}
	initialize(&viw);
	viw.mlx = mlx_init();
	viw.win = mlx_new_window(viw.mlx, SIZE, SIZE, "fract-ol");
	img.img = mlx_new_image(viw.mlx, SIZE, SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	viw.math = (double)4 / SIZE;
	viw.img = img;
	if (!ft_strcmp("m", *(av + 1)) && ac == 2)
		mandel(&viw);
	else if (!ft_strcmp("j", *(av + 1)))
		julia(&viw, ac, av);
	else if (!ft_strcmp("b", *(av + 1)) && ac == 2)
		burning(&viw);
	mlx_put_image_to_window(viw.mlx, viw.win, img.img, 0, 0);
	mlx_loop(viw.mlx);
	return (0);
}
