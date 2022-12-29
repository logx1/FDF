#ifndef TEST_H
# define TEST_H
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 5

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
int		check_new_line(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *s, int start, size_t len);
char	*buckup_finder(char *line);
void draw(void *mlx_ptr,void *win_ptr,float x0, float y0, float x1, float y1, int color);
float x_isso(float x,float y);
float y_isso(float x,float y,int z);

typedef struct point
{
    int x;
    int y;
    int z;
}point;


#endif