/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:32:16 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 10:01:00 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_to_array(t_graph *graph, double tmp_i, double tmp_r, int keycode)
{
	if (keycode == 65362)
	{
		graph->s_i += tmp_i / 10;
		graph->e_i += tmp_i / 10;
	}
	else if (keycode == 65363)
	{
		graph->s_r -= tmp_r / 10;
		graph->e_r -= tmp_r / 10;
	}
	else if (keycode == 65364)
	{
		graph->s_i -= tmp_i / 10;
		graph->e_i -= tmp_i / 10;
	}
	else if (keycode == 65361)
	{
		graph->s_r += tmp_r / 10;
		graph->e_r += tmp_r / 10;
	}
}

int	key_hook(int keycode, t_data *img)
{
	double	tmp_r;
	double	tmp_i;

	if (keycode == 65307)
		close_window(img);
	tmp_r = img->graph->s_r;
	if (tmp_r < 0)
		tmp_r *= -1;
	tmp_i = img->graph->s_i;
	if (tmp_i < 0)
		tmp_i *= -1;
	move_to_array(img->graph, tmp_i, tmp_r, keycode);
	return (0);
}

void	reset_xy(double r, int x, int y, t_data *img)
{
	t_edge	edge;
	double	tmp_sr;
	double	tmp_si;

	edge.x_0 = (1 - r) * x;
	edge.x_1 = r * HORZ + (1 - r) * x;
	edge.y_0 = (1 - r) * y;
	edge.y_1 = r * VERT + (1 - r) * y;
	tmp_sr = img->graph->s_r;
	img->graph->s_r = calc_pos(edge.x_0, img->graph->s_r, img->graph->e_r, 0);
	img->graph->e_r = calc_pos(edge.x_1, tmp_sr, img->graph->e_r, 0);
	tmp_si = img->graph->s_i;
	img->graph->s_i = calc_pos(edge.y_0, img->graph->s_i, img->graph->e_i, 1);
	img->graph->e_i = calc_pos(edge.y_1, tmp_si, img->graph->e_i, 1);
}

int	zoom(int button, int x, int y, t_data *img)
{
	if (button == 4)
		reset_xy(0.999, x, y, img);
	else if (button == 5)
		reset_xy(1.001, x, y, img);
	return (0);
}
