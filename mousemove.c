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

void	upscroll(t_viwinfo *viw)
{
	viw->scal++;
	viw->math = viw->math / 1.5;
	printf("%f\n", viw->math);
	viw->a = 0;
	while (viw->a < SIZE)
	{
		viw->b = 0;
		while (viw->b < SIZE)
		{
			cir(viw);
			viw->b++;
		}
		viw->a++;
	}
}

void	downscroll(t_viwinfo *viw)
{
	if (viw->scal == 0)
		return ;
	viw->scal--;
	viw->math = viw->math * 1.5;
	viw->a = 0;
	while (viw->a < SIZE)
	{
		viw->b = 0;
		while (viw->b < SIZE)
		{
			cir(viw);
			viw->b++;
		}
		viw->a++;
	}
}

int	mousemove(int mouse, int x, int y, t_viwinfo *viw)
{
	(void)x;
	(void)y;
	if (mouse == 4)
		upscroll(viw);
	else if (mouse == 5)
		downscroll(viw);
	printf("position: x=%d, y=%d\nscale: %d\n", viw->pos[0], viw->pos[1], viw->scal);
	return (0);
}
