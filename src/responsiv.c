/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responsiv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:14:03 by abdel-ou          #+#    #+#             */
/*   Updated: 2023/02/22 16:36:00 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	real_position(t_point a, t_point *param)
{
	a.x *= param->scale;
	a.y *= param->scale;
	a.z *= param->z_scale;
	isometric(&a, param->angle);
	a.x += param->push_x;
	a.y += param->push_y;
	return (a);
}

void	responsiv(t_point **a, t_point *param)
{
	t_point	xa;
	t_point	xb;
	t_point	xc;

	xa = a[0][0];
	xb = a[0][param->weight -1];
	xc = a[param->height - 1][0];
	while (real_position(a[0][param->weight -1], param).x < param->win_weight &&
		real_position(xc, param).x > 0)
	{
	param->scale++;
	}
	if (param->scale != 2)
	{
		param->scale--;
	}
}
