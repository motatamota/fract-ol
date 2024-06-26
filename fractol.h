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
# include <math.h>
# include <limits.h>
// #include <stdio.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"

# define SIZE 1000
# define ACC 150
# define DIV 10
# define MOVE 100
# define SCALE 1.8
# define ARG 240

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_viwinfo
{
	void	*mlx;
	void	*win;
	int		scal;
	double	pos[2];
	int		n;
	int		m;
	double	x;
	double	y;
	double	j_a;
	double	j_b;
	double	math;
	int		arg;
	t_data	img;
}				t_viwinfo;

int				keymove(int keycode, t_viwinfo *viw);
int				mousemove(int mouse, int x, int y, t_viwinfo *viw);
void			cir(t_viwinfo *viw);
void			calculation(t_viwinfo *viw);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	colorset(double n, t_viwinfo *viw);
void			julia(t_viwinfo *viw, int ac, char **av);
void			j_calculation(t_viwinfo *viw, double a, double b);
int				j_keymove(int keycode, t_viwinfo *viw);
int				j_mousemove(int mouse, int x, int y, t_viwinfo *viw);
void			b_calculation(t_viwinfo *viw);
void			burning(t_viwinfo *viw);
int				b_mousemove(int mouse, int x, int y, t_viwinfo *viw);
int				b_keymove(int keycode, t_viwinfo *viw);
int				ft_strcmp(char *dest, char *src);
int				checker(int ac, char **av);
void			puterror(void);
int				breakwin(void);

#endif
