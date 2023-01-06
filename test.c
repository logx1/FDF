#include <unistd.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}


int main(int argc,char* argv[])
{
    (void)argc;
    int len = ft_strlen(argv[1]);
    
printf("%d",ft_strlen(argv[1]));

    return (0);
}