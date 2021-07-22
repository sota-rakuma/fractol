/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:27:59 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 09:55:01 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_m_1(t_data *img, t_fractol *ele, int x, int y)
{
	int	k;

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

void	draw_m_2(t_data *img, t_fractol *ele, int x, int y)
{
	int		k;
	double	tmp;

	k = 0;
	while (k++ < CNT)
	{
		tmp = ele->zreal;
		ele->zreal = cos(ele->zimag) * exp(ele->zreal) + ele->pos_real;
		ele->zimag = sin(ele->zimag) * exp(tmp) + ele->pos_imag;
		if (ele->zreal > 10)
		{
			put_color(x, y, k, img);
			break ;
		}
		if (k == CNT)
			my_mlx_pixel_put(img, x, y, 0);
	}
}

void	mandelbrot(t_data *img, int spec)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HORZ)
	{
		j = -1;
		while (++j < VERT)
		{
			img->ele->pos_real = calc_pos((double)i, img->graph->s_r,
					img->graph->e_r, 0);
			img->ele->pos_imag = calc_pos((double)j, img->graph->s_i,
					img->graph->e_i, 1);
			img->ele->zimag = 0.0;
			img->ele->zreal = 0.0;
			if (spec == 1)
				draw_m_1(img, img->ele, i, j);
			else if (spec == 2)
				draw_m_2(img, img->ele, i, j);
			else if (spec == 3)
				draw_m_3(img, img->ele, i, j);
			else
				draw_b(img, img->ele, i, j);
		}
	}
}
