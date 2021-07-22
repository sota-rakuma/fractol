/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:35:23 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/20 14:34:06 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	map_output(int x, int y, t_data *img)
{
	static int	buff[4];
	double		rad;
	int			d_x;
	int			d_y;

	buff[2] = x;
	buff[3] = y;
	if (x < buff[0])
		d_x = buff[0] - x;
	else
		d_x = x - buff[0];
	d_y = y - buff[1];
	rad = atan2(d_y, d_x);
	if (3.14159265358979 / 6 < rad)
		img->graph->color_bias += 0.02;
	else if (rad < -3.14159265358979 / 6)
		img->graph->color_bias -= 0.02;
	buff[0] = x;
	buff[1] = y;
	return (0);
}

int	close_window(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	free(img->graph);
	free(img->ele);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

void	all_hook(t_data *img)
{
	mlx_hook(img->win, 2, 1L << 0, key_hook, img);
	mlx_hook(img->win, 4, 1L << 2, zoom, img);
	mlx_hook(img->win, 5, 1L << 3, zoom, img);
	mlx_hook(img->win, 6, 1L << 6, map_output, img);
	mlx_hook(img->win, 33, 0, close_window, img);
}
