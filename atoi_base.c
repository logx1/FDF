/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:10 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:24:18 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int	ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (str == NULL)
	{
		return (16777215);
	}
	while (ft_iswhitespace(str[i]))
		i++;
	while (base(str[i], str_base) != -1)
	{
		n = n * str_base;
		n = n + base(str[i], str_base);
		i++;
	}
	return (n);
}

// int	main(int ac, char **av)
// {
// 	int		nb;
// 	if (ac >= 3)
// 	{
// 		nb = ft_atoi_base(av[1], atoi(av[2]));
// 		printf("%d\n", nb);
// 	}
// 	return (0);
// }
