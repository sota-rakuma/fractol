/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 07:26:00 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/19 17:16:38 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(int x, int y, int k, t_data *img)
{
	int	red;
	int	green;
	int	blue;
	int	transparency;

	transparency = cos(0.2 * k) * 127 + 128;
	red = sin(k / 2 * img->graph->color_bias) * 127 + 128;
	green = sin(k / 2 + img->graph->color_bias + 2 * 3.14159265358 / 3) \
															* 127 + 128;
	blue = sin(k / 2 * img->graph->color_bias + 4 * 3.14159265358 / 3) \
															* 127 + 128;
	img->graph->color = (transparency << 24) + (red << 16) \
													+ (green << 8) + blue;
	my_mlx_pixel_put(img, x, y, img->graph->color);
}
