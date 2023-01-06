#include "fdf.h"
#include <string.h>

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

int get_height(char *file_name)
{
   int fd = open(file_name,O_RDONLY);
    int i = 0;
    while (get_next_line(fd,110))
    {
        i++;
    }
    close(fd);
    return (i);
}
int get_weight(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    int i = 0;
    i = ft_word_count(get_next_line(fd,5), ' ') - 1;
    close(fd);
    return (i);
}

int main(int argc,char *argv[])
{
    (void)argc;
        void *mlx_ptr;
    void *win_ptr;
    int fd = open(argv[1], O_RDONLY);
    int i = 0;
    int j = 0;
    
    int weight = get_weight(argv[1]);
    int height = get_height(argv[1]);
    // int col;
    char **line = ft_split(get_next_line(fd, 5), ' ');
    int nn[height][weight];
    // int color[height][weight];
    while (j < height)
    {
        while (line[i])
        {
        nn[j][i] = atoi(line[i]);
        // color[j][i] = ft_atoi_base(ft_strnstr(line[i],"0x"),16);
        i++;
        }
    i = 0;
    j++;
    line = ft_split(get_next_line(fd, 5), ' ');
    }
    
  
    i = 0;
    j = 0;
    int zoom = 2;
printf("%d",zoom);
    while (j < height)
    {
        while (i < weight)
        {
            printf("%3d",nn[j][i]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
    
    j = 0;
i = 0;

mlx_ptr =mlx_init();
win_ptr = mlx_new_window(mlx_ptr, 2000, 1550 , "test");


while (j < height)
{
    i = 0;
    while (i < weight)
    {
     
		   	// if (i < (weight -1) )
			// {
			// 	draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,nn[j][i]), x_isso(i+1 ,j), y_isso(i+1 ,j,nn[j][i+1]),color[i][j]);			
            //     }
			// if (j < (height -1) )
			// {
            //     draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,nn[j][i]), x_isso(i ,j+1), y_isso(i ,j+1,nn[j+1][i]),color[i][j]);
			// }
           
       
      
			if (i < (weight -1) )
			{
				 draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,nn[j][i]), x_isso(i+1 ,j), y_isso(i+1 ,j,nn[j][i+1]),0xFA5D2B,zoom);
			}
			if (j < (height -1) )
			{
				draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,nn[j][i]), x_isso(i ,j+1), y_isso(i ,j+1,nn[j+1][i]),0xFA5D2B,zoom);
			}
      
        i++;
    }
    j++;
} 
    

   mlx_loop(mlx_ptr);
    
    return (0);
}