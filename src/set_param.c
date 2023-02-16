/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:32:53 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/07 16:48:53 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_param(t_point *a, t_point *b, t_point *param)
{
	a->x *= param->scale;
	a->y *= param->scale;
	b->x *= param->scale;
	b->y *= param->scale;
	a->z *= param->z_scale;
	b->z *= param->z_scale;
	isometric(a, param->angle);
	isometric(b, param->angle);
	a->x += param->push_x;
	a->y += param->push_y;
	b->x += param->push_x;
	b->y += param->push_y;
}
