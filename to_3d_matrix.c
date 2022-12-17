#include "test.h"


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
int fd = open("./test_maps/42.fdf",O_RDONLY);
int **matrix;
point **new_3d_matrix;
int i = 0;
int j = 0;
int y_linght = 0;
int x_linght = number_count(get_next_line(fd));
while (get_next_line(fd))
    y_linght++;
    y_linght++;
    close(fd);
matrix = (int **)malloc(sizeof(int) * ((x_linght * y_linght) + 1));
new_3d_matrix = (point **)malloc(sizeof(point *) * ((x_linght * y_linght) + 1));
fd = open("./test_maps/42.fdf",O_RDONLY);
while (i < y_linght)
{
    matrix[i] = new(get_next_line(fd));
    i++;
}
j = 0;
i = 0;
// while (j < y_linght)
// {
//     i = 0;
//     while (i < x_linght)
//     {
        // new_3d_matrix[j][i].x = i;
        // new_3d_matrix[j][i].y = j;
        // new_3d_matrix[j][i].z = matrix[j][i];
//         i++;
//     }
    
//     j++;
// }


// new_3d_matrix[0][0].x = 1;
// new_3d_matrix[0]->y = 1;
// new_3d_matrix[0]->z = 1;

    return (0);
}