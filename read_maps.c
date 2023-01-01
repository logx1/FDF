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

char	*ft_print_line(const char *s1, int *index, char c)
{
	char	*copy;
	size_t	word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
	i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c )
		copy[i++] = s1[(*index)++];
	
	return (copy);
}

char	**free_err(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	*ft_split(char const *s, char c)
{
	int	*arr;
	int		index;
	int		word_count;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	arr = malloc(sizeof(int) * (word_count +1));
	
	while (i < word_count)
	{
		if (i == 0)
		{
			ft_print_line(s, &index, c);
		}
		
		arr[i] = atoi(ft_print_line(s, &index, c));
		// if (!arr[i])
		// 	return (free_err(arr));
		i++;
	}
	return (arr);
}

// int	ft_word_count(const char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c)
// 			i++;
// 		else
// 		{
// 			count++;
// 			while (str[i] != c && str[i])
// 				i++;
// 		}
// 	}
// 	return (count);
// }

// int get_height(char *file_name)
// {
//    int fd = open(file_name,O_RDONLY);
//     int i = 0;
//     while (get_next_line(fd,110))
//     {
//         i++;
//     }
//     close(fd);
//     return (i);
// }
int get_weight(char *file_name)
{
    int fd = open(file_name, O_RDONLY);
    int i = 0;
    i = ft_word_count(get_next_line(fd,5), ' ');
    close(fd);
    return (i);
}

int main(int argc,char *argv[])
{
    (void)argc;
    int *nn;
    int i = 0;
    int end ;
    end = get_weight(argv[1]);
    int fd = open(argv[1],O_RDONLY);
    nn = ft_split(get_next_line(fd, 5), ' ');
    while (i < end)
    {
		printf("%d === %d \n",i,nn[i]);  
        i++;
    }
    return (0);
}