/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:36:34 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/26 23:32:39 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	j_cir(t_viwinfo *viw, double a, double b)
{
	int		p;
	double	x;
	double	y;
	double	d_x;

	p = -1;
	x = ((viw->n - SIZE / 2) / pow(SCALE, viw->scal) + (double)viw->pos[0] * \
			(double)MOVE + (double)SIZE / 2) * viw->math - 2.0;
	y = ((viw->m - SIZE / 2) / pow(SCALE, viw->scal) + (double)viw->pos[1] * \
			(double)MOVE + (double)SIZE / 2) * viw->math - 2.0;
	while (++p < ACC)
	{
		if (x * x + y * y >= 6)
		{
			my_mlx_pixel_put(&(viw->img), viw->n, viw->m,
				colorset((double)p, viw));
			return ;
		}
		d_x = x;
		x = x * x - y * y + a;
		y = 2 * d_x * y + b;
	}
	my_mlx_pixel_put(&(viw->img), viw->n, viw->m, 0);
}

void	j_calculation(t_viwinfo *viw, double a, double b)
{
	viw->n = 0;
	while (viw->n < SIZE)
	{
		viw->m = 0;
		while (viw->m < SIZE)
		{
			j_cir(viw, a, b);
			viw->m += 1;
		}
		viw->n += 1;
	}
}

void	juliaset(t_viwinfo *viw)
{
	j_calculation(viw, viw->j_a, viw->j_b);
	mlx_hook(viw->win, 2, 1L << 0, j_keymove, viw);
	mlx_hook(viw->win, 17, 0, breakwin, NULL);
	mlx_hook(viw->win, 4, 1L << 2, j_mousemove, viw);
}

void	julia(t_viwinfo *viw, int ac, char **av)
{
	if (ac == 4)
	{
		viw->j_a = atof(*(av + 2));
		viw->j_b = atof(*(av + 3));
	}
	juliaset(viw);
}
