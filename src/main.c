/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:44 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/14 13:08:41 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_pra(t_point *s)
{
s->scale = 20;
s->z_scale = 1;
s->is_isometric = 1;
s->angle = 0.523599;
s->win_weight = 2000;
s->win_height = 1000;
s->push_x = s->win_weight / 3;
s->push_y = s->win_height / 3;
s->mlx = mlx_init();
s->win = mlx_new_window(s->mlx, s->win_weight, s->win_height, "Fdf");
}

int	key_exit(t_point **matrix)
{
	(void)matrix;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_point	**matrix;

	(void)argc;
	matrix = read_map(argv[1]);
	start_pra(&seting);
	draw(matrix);
	mlx_key_hook(seting.win, deal_key, matrix);
	mlx_hook(seting.win, 17, 0, key_exit, &seting);
	mlx_loop(seting.mlx);
	return (0);
}
