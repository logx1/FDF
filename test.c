#include "test.h"



int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    int fd = open("./test_maps/42.fdf",O_RDONLY);
    char *line ;
    int j = 0;
    int i = 50;
    int l = 50;
    line = get_next_line(fd);
    printf("%s",line);
    
    
    mlx_ptr =mlx_init();
     win_ptr = mlx_new_window(mlx_ptr, 500, 500 , "test");

    while (line != NULL)
    {
        
    while (line[j] != '\n')
    {

       if(line[j] == '0')
        mlx_pixel_put(mlx_ptr, win_ptr,i,l, 0xFFFFFF);
        if (line[j] == '1')
         mlx_pixel_put(mlx_ptr, win_ptr,i,l, 0x75d36e);
        
        i = i + 7;
        j++;
    }
    line = get_next_line(fd);
    j = 0;
    l = l +25;
    i = 50;
    }
    
     mlx_loop(mlx_ptr);
    return (0);
       
}