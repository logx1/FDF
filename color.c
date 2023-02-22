/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:04:15 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:24:33 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ffcolor(int leaght, int color1, int color2, int p)
{
	int			final;
	t_color		color_1;
	t_color		color_2;

	color_1.color_r = (float)(get_r(color1) * (leaght - p)) / leaght;
	color_1.color_g = (float)(get_g(color1) * (leaght - p)) / leaght;
	color_1.color_b = (float)(get_b(color1) * (leaght - p)) / leaght;
	color_2.color_r = (float)(get_r(color2) * p) / leaght;
	color_2.color_g = (float)(get_g(color2) * p) / leaght;
	color_2.color_b = (float)(get_b(color2) * p) / leaght;
	final = create_trgb((int)(color_1.color_r + color_2.color_r),
			(int)(color_1.color_g + color_2.color_g),
			(int)(color_1.color_b + color_2.color_b));
	return (final);
}
// int main()
// {
//     void *mlx;
//     void *win;
//     int i = 1;
//     mlx = mlx_init();
//     win = mlx_new_window(mlx,500,500,"fdf");
//     int color1 = 0x00ff0000; // red
//     int color2 = 0x000000ff; // green
// while (i < 500)
// {
//     mlx_pixel_put(mlx, win, i, 50, ffcolor(500,color1,color2,i));
//     mlx_pixel_put(mlx, win, i, 100, color1);
//     mlx_pixel_put(mlx, win, i, 150, color2);
// i++;
// }

// mlx_loop(mlx);
//     return (0);
// }