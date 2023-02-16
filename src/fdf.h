/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:32 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/16 12:21:40 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# define seting matrix[0][0]

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int		color;
	int			scale;
	int			z_scale;
	int			push_x;
	int			push_y;
	int			is_isometric;
	double		angle;
	int			win_weight;
	int			weight;
	int			height;
	int			win_height;
	void		*mlx;
	void		*win;
}				t_point;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_color
{
	float	color_r;
	float	color_g;
	float	color_b;
}t_color;


t_point			**read_map(char *file_name);
void			isometric(t_point *dot, double angle);
void			draw(t_point **matrix);
void			set_param(t_point *a, t_point *b, t_point *param);
int				deal_key(int key, t_point **matrix);
char	*get_next_line(int fd, int BUFFER_SIZE);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
int		check_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, size_t len);
char	*buckup_finder(char *line);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle);
int ft_atoi_base(const char *str, int str_base);
int ffcolor(int leaght, int color1, int color2, int p);
#endif
