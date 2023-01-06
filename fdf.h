#ifndef FDF_H
# define FDF_H
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
// #define BUFFER_SIZE 5
// cc -I /usr/local/include get_next_line.c get_next_line_utils.c draw.c to_3d_matrix.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

char	*get_next_line(int fd, int BUFFER_SIZE);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
int		check_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, size_t len);
char	*buckup_finder(char *line);
void draw(void *mlx_ptr,void *win_ptr,float x0, float y0, float x1, float y1, int color,int zoom);
float x_isso(float x,float y);
float y_isso(float x,float y,int z);
char	**ft_split(char const *s, char c);
int ft_atoi_base(const char *str, int str_base);
char	*ft_strnstr(const char *haystack, const char *needle);

typedef struct point
{
    int x;
    int y;
    int z;
}point;


#endif