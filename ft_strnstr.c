/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:31:41 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/01/06 16:18:40 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strnstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
	j = 0;
		while (haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i +2));
		i++;
	}
	return (NULL);
}
