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

int get_height(char *file_name)
{
    int fd = open(file_name ,O_RDONLY);
    int i = 0;
    char *line = get_next_line(fd, 10);
    while (line)
    {
        i++;
        free(line);
        line = get_next_line(fd, 10);
    }
    free(line);
    close(fd);
    return (i);
}

int get_weight(char *file_name)
{
    int fd = open(file_name , O_RDONLY);
    char *line = get_next_line(fd, 1);
    int i = ft_word_count(line, ' ');
    free(line);
    close(fd);
    return (i);
}


void dig_line(int *dig_line , char *line)
{
    char **line_splited;
    int i = 0 ;
    line_splited = ft_split(line, ' ');
    while (line_splited[i])
    {
        dig_line[i] = atoi(line_splited[i]);
        free(line_splited[i]);
        i++;
    }
    free(line_splited);

}
int main(int argc, char *argv[])
{
    (void)argc;
    int height = get_height(argv[1]);
    int weight = get_weight(argv[1]);
    int fd = open(argv[1],O_RDONLY);
    int **matrix;
    int i = 0;
    int j = 0;
    matrix = (int **)malloc(sizeof(int *) * (height + 1));
        
        while (i < height)
        {
            matrix[i] = (int *)malloc(sizeof(int) * (weight + 1));
            dig_line(matrix[i], get_next_line(fd, 1));
            i++;
        }
        
    i = 0;
    j = 0;
    while (j < height)
    {
        while (i < weight)
        {
            printf("%3d",matrix[j][i]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }   

        return (0);
}
