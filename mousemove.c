/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:06:56 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/25 13:06:56 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousemove(int mouse, int x, int y, t_viwinfo *viw)
{
	(void)x;
	(void)y;
	if (mouse == 4)
		viw->scal += 1;
	else if (mouse == 5)
		viw->scal -= 1;
	viw->arg += 10;
	calculation(viw);
	mlx_put_image_to_window(viw->mlx, viw->win, (viw->img).img, 0, 0);
	return (0);
}

int	j_mousemove(int mouse, int x, int y, t_viwinfo *viw)
{
	(void)x;
	(void)y;
	if (mouse == 4)
		viw->scal += 1;
	else if (mouse == 5)
		viw->scal -= 1;
	viw->arg += 10;
	j_calculation(viw, viw->j_a, viw->j_b);
	mlx_put_image_to_window(viw->mlx, viw->win, (viw->img).img, 0, 0);
	return (0);
}

int	b_mousemove(int mouse, int x, int y, t_viwinfo *viw)
{
	(void)x;
	(void)y;
	if (mouse == 4)
		viw->scal += 1;
	else if (mouse == 5)
		viw->scal -= 1;
	viw->arg += 10;
	b_calculation(viw);
	mlx_put_image_to_window(viw->mlx, viw->win, (viw->img).img, 0, 0);
	return (0);
}
