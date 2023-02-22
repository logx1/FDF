/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:32:48 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:24:01 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_word_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

int	fill_line(char *line, t_point **matrix, int y)
{
	char	**points;
	int		x;

	points = ft_split(line, ' ');
	x = 0;
	while (points[x])
	{
		matrix[y][x].z = ft_atoi(points[x]);
		matrix[y][x].color = ft_atoi_base(ft_strnstr(points[x], "0x"), 16);
		matrix[y][x].x = x;
		matrix[y][x].y = y;
		matrix[y][x].is_last = 0;
		free(points[x++]);
	}
	free(points);
	free(line);
	matrix[y][--x].is_last = 1;
	return (x);
}

t_point	**memory_allocete(char *file_name)
{
	t_point	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd, 50);
	x = ft_word_count(line, ' ');
	y = 0;
	while (line > 0)
	{
		y++;
		free(line);
		line = get_next_line(fd, 50);
	}
	new = (t_point **)malloc(sizeof(t_point *) * (y + 1));
	while (y > 0)
		new[--y] = (t_point *)malloc(sizeof(t_point) * (x + 1));
	close(fd);
	return (new);
}

t_point	**read_map(char *file_name)
{
	t_point	**matrix;
	int		y;
	int		fd;
	char	*line;

	matrix = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	line = get_next_line(fd, 5);
	matrix[0][0].weight = ft_word_count(line, ' ');
	while (line > 0)
	{
		fill_line(line, matrix, y++);
		line = get_next_line(fd, 5);
		matrix[0][0].height = y;
	}
	free(line);
	matrix[y] = NULL;
	close(fd);
	return (matrix);
}
