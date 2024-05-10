/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:07:41 by tashiget          #+#    #+#             */
/*   Updated: 2024/04/23 14:07:41 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# define SIZE 1000
# define ACC 100
# define DIV 10

typedef struct	s_viwinfo {
	void	*mlx;
	void	*win;
	int		scal;
	int		pos[2];
	int		n;
	int		m;
	double	x;
	double	y;
	double	a;
	double	b;
	double	math;
}				t_viwinfo;

int		keymove(int	keycode, t_viwinfo *viw);
int		mousemove(int mouse, int x, int y, t_viwinfo *viw);
void	cir(t_viwinfo *viw);

#endif
