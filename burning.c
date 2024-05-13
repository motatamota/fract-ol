/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:41:45 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/13 10:41:45 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	b_cir(t_viwinfo *viw)
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
		x = fabs(viw->x);
		viw->x = x * x - fabs(viw->y) * fabs(viw->y) + a;
		viw->y = 2 * x * fabs(viw->y) + b;
	}
	my_mlx_pixel_put(&(viw->img), viw->n, viw->m, 0);
}

void	b_calculation(t_viwinfo *viw)
{
	viw->n = 0;
	while (viw->n < SIZE)
	{
		viw->m = 0;
		while (viw->m < SIZE)
		{
			b_cir(viw);
			viw->m += 1;
		}
		viw->n += 1;
	}
}

void	burning(t_viwinfo *viw)
{
	b_calculation(viw);
	mlx_hook(viw->win, 2, 1L << 0, b_keymove, viw);
	mlx_hook(viw->win, 4, 1L << 2, b_mousemove, viw);
}
