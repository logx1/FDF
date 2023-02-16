/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:04:10 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/14 15:11:29 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int	ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
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
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	if (str == NULL)
	{
		return (16777215);
	}
	while (ft_iswhitespace(str[i]))
		i++;
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	return (nb);
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
