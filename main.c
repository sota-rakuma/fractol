/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 05:27:53 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/22 09:53:40 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_window(t_data *img)
{
	if (img->param == '1')
		mandelbrot(img, 1);
	else if (img->param == '2')
		mandelbrot(img, 2);
	else if (img->param == '3')
		mandelbrot(img, 3);
	else if (img->param == 'b')
		mandelbrot(img, 4);
	else if (img->param == 'j')
		julia(img);
	else if (img->param == 'g')
		gmo_mira(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}

t_graph	*init_graph(void)
{
	t_graph	*graph;

	graph = (t_graph *)malloc(sizeof(t_graph));
	if (!graph)
	{
		write(2, "MEMORY ALLOCATE ERROR\n", 22);
		exit(EXIT_FAILURE);
	}
	graph->s_r = -2.0;
	graph->s_i = -2.0;
	graph->e_r = 2.0;
	graph->e_i = 2.0;
	graph->color = 0xffffffff;
	graph->color_bias = 0.0;
	return (graph);
}

t_fractol	*init_fractol(int ac, char **ar)
{
	t_fractol	*ele;

	ele = (t_fractol *)malloc(sizeof(t_fractol));
	if (!ele)
	{
		write(2, "MEMORY ALLOCATE ERROR\n", 22);
		exit(EXIT_FAILURE);
	}
	if (**ar == 'j')
	{
		if (ac == 4 && is_num(ar[1]))
			ele->pos_real = ft_atof(ar[1]);
		else
			ele->pos_real = -0.4;
		if (ac == 4 && is_num(ar[2]))
			ele->pos_imag = ft_atof(ar[2]);
		else
			ele->pos_imag = 0.6;
	}
	else
	{
		ele->pos_real = 0.0;
		ele->pos_imag = 0.0;
	}
	return (ele);
}

int	main(int ac, char **ar)
{
	t_data	img;

	if (ac < 2)
		print_error();
	if (!(*ar[1] == '1' || *ar[1] == '2' || *ar[1] == '3' || *ar[1] == 'j'
			|| *ar[1] == 'g' || *ar[1] == 'b'))
		print_error();
	img.mlx = mlx_init();
	img.graph = init_graph();
	img.param = **(++ar);
	img.ele = init_fractol(ac, ar);
	img.win = mlx_new_window(img.mlx, HORZ, VERT, "fract-ol");
	img.img = mlx_new_image(img.mlx, HORZ, VERT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	all_hook(&img);
	mlx_loop_hook(img.mlx, render_window, &img);
	mlx_loop(img.mlx);
	return (0);
}
