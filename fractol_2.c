/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 05:28:28 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 09:51:25 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//flag == 0 -> HORZ
//flag == 1 -> VERT
double	calc_pos(double cnt, double start, double end, int flag)
{
	double	res;

	if (!flag)
		res = cnt * (end - start) / HORZ - (-1) * start;
	else
		res = cnt * (end - start) / VERT - (-1) * start;
	return (res);
}

void	draw_m_3(t_data *img, t_fractol *ele, int x, int y)
{
	int		k;
	double	tmp;

	k = 0;
	while (k++ < CNT)
	{
		tmp = ele->zreal;
		ele->zreal = sin(ele->zreal) * (exp(ele->zimag) \
						+ exp((-1) * ele->zimag)) + ele->pos_real;
		ele->zimag = cos(tmp) * (exp((-1) * ele->zimag) \
						- exp(ele->zimag)) + ele->pos_imag;
		if (ele->zreal > 10)
		{
			put_color(x, y, k, img);
			break ;
		}
		if (k == CNT)
			my_mlx_pixel_put(img, x, y, 0);
	}
}

void	my_julia(t_data *img, t_fractol *ele, int x, int y)
{
	int		k;

	k = 0;
	while (k++ < CNT)
	{
		binomial_theorem(&ele->zreal, &ele->zimag, EXPO);
		ele->zreal += ele->pos_real;
		ele->zimag += ele->pos_imag;
		if ((ele->zreal * ele->zreal + ele->zimag * ele->zimag) > 4)
		{
			put_color(x, y, k, img);
			break ;
		}
		if (k == CNT)
			my_mlx_pixel_put(img, x, y, 0);
	}
}

void	julia(t_data *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HORZ)
	{
		j = -1;
		while (++j < VERT)
		{
			img->ele->zreal = calc_pos((double)i, img->graph->s_r,
					img->graph->e_r, 0);
			img->ele->zimag = calc_pos((double)j, img->graph->s_i,
					img->graph->e_i, 1);
			my_julia(img, img->ele, i, j);
		}
	}
}
