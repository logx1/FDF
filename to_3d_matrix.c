#include "fdf.h"


int number_count(char *str)
{
    int i ;
    int j ;
    int l ;
    j = 0;
    i = 0;

    while (str[i])
    {
        l = i + 1;
        if (str[i] >= '0' && str[i]<= '9' && str[l] == ' ')
            j++;
        i++;
    }
    return (j + 1);
}


int *new(char *str)
{
    int i = 0; 
    int j = 0;
    int l = 0;
    int lenght;
    lenght = number_count(str);
    int *new;
    new = malloc(sizeof(int) * (lenght + 1));
	while (str[l])
	{
		if (str[l] >= '0' && str[l] <= '9')
        {
            new[j] = new[j] * 10;
            new[j] = new[j] + (str[l] - 48);
        }
		if (str[l + 1] == ' ' && str[l] != ' ')
		{
			j++;
		}
		l++;
	}
    return(new);
}
int main()
{
    void *mlx_ptr;
    void *win_ptr;
   
int fd = open("./test_maps/mars.fdf",O_RDONLY);
int **matrix;

int i = 0;
int j = 0;
    int l = 50;
    int c = 50;
int y_linght = 0;
int x_linght = number_count(get_next_line(fd,5));
while (get_next_line(fd,5))
    y_linght++;
    y_linght++;
    close(fd);
matrix = (int **)malloc(sizeof(int) * ((x_linght * y_linght) + 1));

fd = open("./test_maps/mars.fdf",O_RDONLY);
while (i < y_linght)
{
    matrix[i] = new(get_next_line(fd,5));
    i++;
}
j = 0;
i = 0;
mlx_ptr =mlx_init();
win_ptr = mlx_new_window(mlx_ptr, 1250, 850 , "test");

while (j < y_linght)
{
    i = 0;
    while (i < x_linght)
    {
        if (matrix[j][i] == 10)
        {
		   	if (i < (x_linght -1) )
			{
				draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,matrix[j][i]), x_isso(i+1 ,j), y_isso(i+1 ,j,matrix[j][i+1]),0x75d36e);			
                }
			if (j < (y_linght -1) )
			{
                draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,matrix[j][i]), x_isso(i ,j+1), y_isso(i ,j+1,matrix[j+1][i]),0x75d36e);
			}
           
        } else
        {
			if (i < (x_linght -1) )
			{
				 draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,matrix[j][i]), x_isso(i+1 ,j), y_isso(i+1 ,j,matrix[j][i+1]),0xFA5D2B);
			}
			if (j < (y_linght -1) )
			{
				draw(mlx_ptr,win_ptr,x_isso(i,j), y_isso(i,j,matrix[j][i]), x_isso(i ,j+1), y_isso(i ,j+1,matrix[j+1][i]),0xFA5D2B);
			}
        }
        i++;
    }
    j++;
} 
// while (j < y_linght)
// {
//     i = 0;
//     while (i < x_linght)
//     {
//         if (matrix[j][i] == 10)
//         {
// 		   	if (i < (x_linght -1) )
// 			{
// 				draw(mlx_ptr,win_ptr,c, l, c+20, l,0x75d36e);			
//                 }
// 			if (j < (y_linght) )
// 			{
// 				draw(mlx_ptr,win_ptr,c, l, c, l+50,0x75d36e);
// 			}
           
//         } else
//         {
// 			if (i < (x_linght -1) )
// 			{
// 				 draw(mlx_ptr,win_ptr,c, l, c+20, l,0xFFFFFF);
// 			}
// 			if (j < (y_linght ) )
// 			{
// 				 draw(mlx_ptr,win_ptr,c, l, c, l+50,0xFFFFFF);
// 			}
           
           

//         }
//         c = c + 20;
//         i++;
//     }
//     l = l +25;
//     c = 50;
//     j++;
// } 

// while (j < y_linght)
// {
//     i = 0;
//     while (i < x_linght)
//     {
//         printf("%2d ",matrix[j][i]);
//         i++;
//     }
//     printf("\n");
//     j++;
// }
// draw(mlx_ptr,win_ptr,350, 350, 50, 50);


mlx_loop(mlx_ptr);
    return (0);
}