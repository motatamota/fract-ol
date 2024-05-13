/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:00:53 by tashiget          #+#    #+#             */
/*   Updated: 2024/05/13 11:00:53 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checknum(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '-')
		str++;
	if (*str == '.')
		return (1);
	while (*str)
	{
		if (*str != '.' && (*str < '0' || *str > '9'))
			return (1);
		str++;
	}
	if (*(str - 1) == '.' || *(str - 1) == '-')
		return (1);
	return (0);
}

int	ft_strcmp(char *dest, char *src)
{
	while (*dest - *src == 0 && *dest && *src)
	{
		dest++;
		src++;
	}
	return (*dest - *src);
}

int	checker(int ac, char **av)
{
	(void)ac;
	if (ft_strcmp(*(av + 1), "b") && ft_strcmp("m", *(av + 1)) && ft_strcmp("j", *(av + 1)))
		return (1);
	if (!ft_strcmp("j", *(av + 1)) && checknum(*(av + 2)) && checknum(*(av + 3)))
		return (1);
	return (0);
}
