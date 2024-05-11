/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:36:34 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/11 14:47:24 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_viwinfo *viw, int ac, char **av)
{
	if (ac == 3)
	{
		ft_printf("Error: number of unauthorized arguments\n");
		return ;
	}
	if (ac == 2)
		juliaset(viw, -0.2, 0.7);
	if (ac == 4)
		juliaset(viw, ft_atoi(*(av + 2)), ft_atoi(*(av + 3)));
}