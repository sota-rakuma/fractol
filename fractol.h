/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 05:26:30 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 09:52:13 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef VERT
#  define VERT 600.0
# endif

# ifndef HORZ
#  define HORZ 600.0
# endif

# ifndef SIZE
#  define SIZE 4.0
# endif

# ifndef EXPO
#  define EXPO 2
# endif

# ifndef CNT
#  define CNT 100
# endif

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_graph
{
	double	s_r;
	double	e_r;
	double	s_i;
	double	e_i;
	double	color_bias;
	int		color;
}				t_graph;

typedef struct s_fractol
{
	double	zreal;
	double	zimag;
	double	pos_real;
	double	pos_imag;
}				t_fractol;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_graph		*graph;
	t_fractol	*ele;
	char		param;
	void		*mlx;
	void		*win;
}				t_data;

typedef struct s_bt
{
	double	coefficient;
	double	tmp_a;
	double	tmp_b;
	double	a;
	double	b;
}				t_bt;

typedef struct s_edge
{
	double	x_0;
	double	x_1;
	double	y_0;
	double	y_1;
}				t_edge;

void	mandelbrot(t_data *img, int spec);
void	julia(t_data *img);
void	burning_ship(t_data *img);
void	gmo_mira(t_data *img);
void	binomial_theorem(double *zr, double *zi, int expo);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_color(int x, int y, int k, t_data *img);
double	calc_pos(double cnt, double start, double end, int flag);
int		close_window(t_data *img);
int		key_hook(int keycode, t_data *img);
int		zoom(int button, int x, int y, t_data *img);
void	draw_m_3(t_data *img, t_fractol *ele, int x, int y);
void	draw_b(t_data *img, t_fractol *ele, int x, int y);
void	all_hook(t_data *img);
void	print_error(void);
int		ft_isdigit(int c);
int		is_num(char *str);
double	ft_atof(char *str);

#endif