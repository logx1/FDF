/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:23 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/14 15:34:20 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	if (i < 0)
	{
		i = -i;
	}
	return (i);
}

float	maxx(float a, float b)
{
	if (a > b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

void	line(t_point a, t_point b, t_point *param)
{
	float	x_step;
	float	y_step;
	float	mx;
	int		i;

	i = 0;
	set_param(&a, &b, param);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	mx = maxx(fmodule(x_step), fmodule(y_step));
	x_step /= mx;
	y_step /= mx;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx, param->win, a.x, a.y,
			ffcolor((int)mx, a.color, b.color, i));
		a.x += x_step;
		a.y += y_step;
		i++;
		if (a.x > param->win_weight || a.y > param->win_height
			|| a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_point **matrix)
{
	int		y;
	int		x;

	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &seting);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], &seting);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
