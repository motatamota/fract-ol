/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:04:23 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/10 12:04:23 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	colorset(double n, t_viwinfo *viw)
{
	unsigned int	color;
	int				red;
	int				green;
	int				blue;

	n = (ACC - n) * 360 / ACC;
	red = 128 * (cos((n + ARG + viw->arg) * M_PI / 180) * n / 360 + 1);
	green = 128 * (sin((n - 30 + ARG + viw->arg) * M_PI / 180) * n / 360 + 1);
	blue = 128 * (sin((n + 210 + ARG + viw->arg) * M_PI / 180) * n / 360 + 1);
	color = 256 * 256 * (unsigned int)red + 256 * (unsigned int)green + (unsigned int)blue;
	return (color);
}
