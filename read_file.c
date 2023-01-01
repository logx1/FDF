#include "test.h"
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

int get_h(char *file_name)
{
   int fd = open(file_name,O_RDONLY);
    int i = 0;
    while (get_next_line(fd))
    {
        i++;
    }
    close(fd);
    return (i);
}
int get_w(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    int i = 0;
    i = ft_word_count(get_next_line(fd), ' ');
    close(fd);
    return (i);
}


int main(int argc,char *argv[])
{
    
    
    printf("%d ==== %d",get_h(argv[1]),get_w(argv[1]));
    return (0);
}