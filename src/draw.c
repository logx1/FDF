/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:23 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/22 16:40:29 by abdel-ou         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_point *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	line(t_point a, t_point b, t_point *p)
{
	float	x_step;
	float	y_step;
	float	mx;
	int		i;

	i = 0;
	set_param(&a, &b, p);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	mx = maxx(fmodule(x_step), fmodule(y_step));
	x_step /= mx;
	y_step /= mx;
	if (a.x < p->win_weight && a.y < p->win_height && a.x > 0 && a.y > 0)
	{
		while ((int)(a.x - b.x) || (int)(a.y - b.y))
		{
			my_mlx_pixel_put(p, a.x, a.y,
				ffcolor((int)mx, a.color, b.color, i++));
		a.x += x_step;
		a.y += y_step;
			if (a.x > p->win_weight || a.y > p->win_height
				|| a.y < 0 || a.x < 0)
				break ;
		}
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
				line(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (matrix[y][x].is_last == 0)
				line(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].is_last == 1)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(matrix[0][0].mlx, matrix[0][0].win,
		matrix[0][0].img, 0, 0);
}
