/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:32:18 by srakuma           #+#    #+#             */
/*   Updated: 2021/07/19 17:25:39 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	add_and_sub(t_bt *ele, int cnt)
{
	if (cnt == 0 || !(cnt % 4))
		ele->a += ele->coefficient * ele->tmp_a * ele->tmp_b;
	else if (!(cnt % 2))
		ele->a -= ele->coefficient * ele->tmp_a * ele->tmp_b;
	else if (cnt % 4 == 3)
		ele->b -= ele->coefficient * ele->tmp_a * ele->tmp_b;
	else
		ele->b += ele->coefficient * ele->tmp_a * ele->tmp_b;
}

void	binomial_theorem(double *zr, double *zi, int expo)
{
	t_bt	ele;
	int		i;
	int		j;

	ele.a = 0.0;
	ele.b = 0.0;
	i = -1;
	ele.coefficient = 1.0;
	while (i++ < expo)
	{
		ele.tmp_a = 1.0;
		ele.tmp_b = 1.0;
		if (0 < i)
			ele.coefficient *= ((expo - (double)i + 1) / (double)i);
		j = -1;
		while (++j < i)
			ele.tmp_b *= *zi;
		while (j++ < expo)
			ele.tmp_a *= *zr;
		add_and_sub(&ele, i);
	}
	*zr = ele.a;
	*zi = ele.b;
}

int	is_num(char *str)
{
	while (*str == ' ' || *str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '.')
			return (0);
		str++;
	}
	return (1);
}
