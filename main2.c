/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:58:48 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/26 22:58:48 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	puterror(void)
{
	ft_printf("Argument Error. Use (m, j(x, y), b)\n\
m:Mandelbrot set\nj:Julia set\nb:Burning Ship fractal\n\
if you chose 'j', should two more arguments that above -2,\
 below 2.(ex. ./fractol j -0.2 0.7)\n");
}

int	breakwin(void)
{
	exit(0);
	return (1);
}
