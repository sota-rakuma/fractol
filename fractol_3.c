/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:29:52 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 09:53:16 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_b(t_data *img, t_fractol *ele, int x, int y)
{
	int		k;

	k = 0;
	while (k++ < CNT)
	{
		ele->zreal = fabs(ele->zreal);
		ele->zimag = fabs(ele->zimag);
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

double	math_func(double x)
{
	double	m;
	double	fx;

	m = -0.496;
	fx = m * x + (2 * (1 - m) * x * x) / (1 + x * x);
	return (fx);
}

void	gmo_mira(t_data *img)
{
	double	alpha;
	double	delta;
	double	tmp;
	int		i;

	alpha = 0.008;
	delta = 0.05;
	img->graph->s_r = 0.1;
	img->graph->s_i = 0.1;
	i = 0;
	while (i++ < 1000000)
	{
		tmp = img->graph->s_r;
		img->graph->s_r = img->graph->s_i \
			+ (alpha * (1 - delta * img->graph->s_i * img->graph->s_i) \
			* img->graph->s_i) \
			+ math_func(img->graph->s_r);
		img->graph->s_i = (-1) * tmp + math_func(img->graph->s_r);
		if (2000 < i)
			put_color(VERT / 2 - (-1) * img->graph->s_r * 15, \
							HORZ / 2 - img->graph->s_i * 15, i, img);
	}
}
