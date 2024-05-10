/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:06:02 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/25 13:06:02 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rmove(t_viwinfo *viw)
{
	viw->pos[0] += 10;
	viw->a = 0;
	while (viw->a < SIZE)
	{
		viw->b = 0;
		while (viw->b < SIZE)
		{
			if (viw->a < SIZE - 10)
			{
				mlx_pixel_put(viw->mlx, viw->win, viw->a, viw->b, viw->buf[viw->a + 10][viw->b]);
				viw->buf[viw->a][viw->b] = viw->buf[viw->a + 10][viw->b];
			}
			else
				cir(viw);
			viw->b++;
		}
		viw->a++;
	}
}

void	dmove(t_viwinfo *viw)
{
	viw->pos[1] += 10;
	viw->a = 0;
	while (viw->a < SIZE)
	{
		viw->b = 0;
		while (viw->b < SIZE)
		{
			if (viw->b < SIZE - 10)
			{
				mlx_pixel_put(viw->mlx, viw->win, viw->a, viw->b, viw->buf[viw->a][viw->b + 10]);
				viw->buf[viw->a][viw->b] = viw->buf[viw->a][viw->b + 10];
			}
			else
				cir(viw);
			viw->b++;
		}
		viw->a++;
	}
}

void	lmove(t_viwinfo *viw)
{
	viw->pos[0] -= 10;
	viw->a = SIZE - 1;
	while (viw->a >= 0)
	{
		viw->b = SIZE - 1;
		while (viw->b >= 0)
		{
			if (viw->a >= 10)
			{
				mlx_pixel_put(viw->mlx, viw->win, viw->a, viw->b, viw->buf[viw->a - 10][viw->b]);
				viw->buf[viw->a][viw->b] = viw->buf[viw->a - 10][viw->b];
			}
			else
				cir(viw);
			viw->b--;
		}
		viw->a--;
	}
}

void	umove(t_viwinfo *viw)
{
	viw->pos[1] -= 10;
	viw->a = SIZE - 1;
	while (viw->a >= 0)
	{
		viw->b = SIZE - 1;
		while (viw->b >= 0)
		{
			if (viw->b >= 10)
			{
				mlx_pixel_put(viw->mlx, viw->win, viw->a, viw->b, viw->buf[viw->a][viw->b - 10]);
				viw->buf[viw->a][viw->b] = viw->buf[viw->a][viw->b - 10];
			}
			else
				cir(viw);
			viw->b--;
		}
		viw->a--;
	}
}

int	keymove(int	keycode, t_viwinfo *viw)
{
	if (keycode == 65361)
		lmove(viw);
	else if (keycode == 65362)
		umove(viw);
	else if (keycode == 65363)
		rmove(viw);
	else if (keycode == 65364)
		dmove(viw);
	printf("position: x=%d, y=%d\nscale: %d\n", viw->pos[0], viw->pos[1], viw->scal);
	return (0);
}
