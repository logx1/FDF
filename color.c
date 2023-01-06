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
    char **line = ft_split(get_next_line(fd, 5), ' ');
    int nn[height][weight];
    // while (j < height)
    // {
    //     while (line[i])
    //     {
    //     nn[j][i] = atoi(line[i]);
    //     i++;
    //     }
    // i = 0;
    // j++;
    // line = ft_split(get_next_line(fd, 5), ' ');
    // }
    
  
    // i = 0;
    // j = 0;
    // while (j < height)
    // {
    //     while (i < weight)
    //     {
    //         printf("%3d",nn[j][i]);
    //         i++;
    //     }
    //     printf("\n");
    //     i = 0;
    //     j++;
    // }
    printf("%d",ft_atoi_base(ft_strnstr(line[0],"0x"),16));

    return (0);
}