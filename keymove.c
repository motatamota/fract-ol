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

int	keymove(int keycode, t_viwinfo *viw)
{
	if (keycode == 123)
		viw->pos[0] -= 1 / pow(SCALE, viw->scal);
	else if (keycode == 126)
		viw->pos[1] -= 1 / pow(SCALE, viw->scal);
	else if (keycode == 124)
		viw->pos[0] += 1 / pow(SCALE, viw->scal);
	else if (keycode == 125)
		viw->pos[1] += 1 / pow(SCALE, viw->scal);
	else if (keycode == 53)
	{
		mlx_destroy_window(viw->mlx, viw->win);
		exit(0);
	}
	viw->arg += 20;
	calculation(viw);
	mlx_put_image_to_window(viw->mlx, viw->win, (viw->img).img, 0, 0);
	printf("position: x=%f, y=%f\nscale: %d\n",
		viw->pos[0], viw->pos[1], viw->scal);
	return (0);
}
