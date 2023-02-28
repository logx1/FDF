/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:44 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/26 19:52:35 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_pra(t_point *s, t_point **a)
{
s->z_scale = 3;
s->angle = 0.523599;
s->win_weight = 1800;
s->win_height = 1000;
s->scale = 2;
s->push_x = s->win_weight / 3;
s->push_y = s->win_height / 3;
	responsiv(a, s);
s->mlx = mlx_init();
s->win = mlx_new_window(s->mlx, s->win_weight, s->win_height, "Fdf");
s->img = mlx_new_image(s->mlx, s->win_weight, s->win_height);
s->addr = mlx_get_data_addr(s->img, &s->bits_per_pixel, &s->line_length,
			&s->endian);
}

int	key_exit(t_point **matrix)
{
	mlx_destroy_image(matrix[0][0].mlx, matrix[0][0].img);
	mlx_destroy_window(matrix[0][0].mlx, matrix[0][0].win);
	free(matrix);
	exit(0);
	return (0);
}

int	ft_strlrn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_point	**matrix;
	int		l;

	l = ft_strlen(argv[1]);
	if (argc == 2 && argv[1][l -1] == 'f' && argv[1][l -2] == 'd'
		&& argv[1][l -3] == 'f' && argv[1][l -4] == '.')
	{	
		matrix = read_map(argv[1]);
		start_pra(&matrix[0][0], matrix);
		draw(matrix);
		mlx_key_hook(matrix[0][0].win, click_key, matrix);
		mlx_hook(matrix[0][0].win, 17, 0, key_exit, matrix);
		mlx_loop(matrix[0][0].mlx);
	}
	else
	{
		write(1, "please check your parameter or argc!!", 37);
	}
	return (0);
}
