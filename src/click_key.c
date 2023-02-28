/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:14:38 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:23:38 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	click_key(int key, t_point **matrix)
{
	if (key == 53)
	{
		mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].img);
		mlx_destroy_window(matrix[0][0].mlx, matrix[0][0].win);
		free(matrix);
		exit(0);
	}
	return (0);
}
