/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:38:04 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/19 16:56:13 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	print_error(void)
{
	printf("\n1	mandelbrot\n\n");
	printf("2	mandelbrot ver.2\n\n");
	printf("3	mandelbrot ver.3\n\n");
	printf("j	1.julia		2.real		3.image\n\n");
	printf("		default		-0.4		0.6\n\n");
	printf("b	burning ship\n\n");
	printf("g	gumowski mira map\n\n");
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

double	get_double(char *str)
{
	double	digit;
	double	num;

	num = 0.0;
	while (str && ft_isdigit(*str))
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (*str == '.')
		str++;
	digit = 0.1;
	while (str && ft_isdigit(*str))
	{
		num += (*str - '0') * digit;
		digit /= 10;
		str++;
	}
	return (num);
}

double	ft_atof(char *str)
{
	double	flag;

	flag = 1.0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		flag = -1.0;
	if (*str == '-' || *str == '+')
		str++;
	return (get_double(str) * flag);
}
