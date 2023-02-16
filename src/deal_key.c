/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:14:38 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/14 15:30:58 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	effect(int key, t_point **matrix)
{
	if (key == 24)
		seting.scale += 2;
	if (key == 27)
		seting.scale -= 2;
	if (key == 28)
		seting.z_scale += 1;
	if (key == 19)
		seting.z_scale -= 1;
	if (key == 126)
		seting.push_y -= 5;
	if (key == 125)
		seting.push_y += 5;
	if (key == 123)
		seting.push_x -= 5;
	if (key == 124)
		seting.push_x += 5;
	if (key == 21)
		seting.angle += 0.05;
	if (key == 22)
		seting.angle -= 0.05;
}

int	deal_key(int key, t_point **matrix)
{
	mlx_clear_window(seting.mlx, seting.win);
	effect(key, matrix);
	draw(matrix);
	if (key == 53)
	{
		mlx_destroy_window(seting.mlx, seting.win);
		free(matrix);
		exit(0);
	}
	return (0);
}
