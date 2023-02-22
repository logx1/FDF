/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:14:38 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:23:34 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	effect(int key, t_point **matrix)
{
	if (key == 24)
		matrix[0][0].scale += 2;
	if (key == 27)
		matrix[0][0].scale -= 2;
	if (key == 28)
		matrix[0][0].z_scale += 1;
	if (key == 19)
		matrix[0][0].z_scale -= 1;
	if (key == 126)
		matrix[0][0].push_y -= 5;
	if (key == 125)
		matrix[0][0].push_y += 5;
	if (key == 123)
		matrix[0][0].push_x -= 5;
	if (key == 124)
		matrix[0][0].push_x += 5;
	if (key == 21)
		matrix[0][0].angle += 0.15;
	if (key == 22)
		matrix[0][0].angle -= 0.15;
}

int	click_key(int key, t_point **matrix)
{
	mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].img);
	matrix[0][0].img = mlx_new_image(matrix[0][0].mlx, matrix[0][0].win_weight,
			matrix[0][0].win_height);
	matrix[0][0].addr = mlx_get_data_addr(matrix[0][0].img,
			&matrix[0][0].bits_per_pixel, &matrix[0][0].line_length,
			&matrix[0][0].endian);
	effect(key, matrix);
	draw(matrix);
	if (key == 53)
	{
		mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].img);
		mlx_destroy_window(matrix[0][0].mlx, matrix[0][0].win);
		free(matrix);
		exit(0);
	}
	return (0);
}
