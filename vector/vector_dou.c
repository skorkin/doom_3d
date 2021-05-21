/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dou.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:37:04 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:38:24 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec_d	sum_v_d(t_vec_d v1, t_vec_d v2)
{
	t_vec_d	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	return (result);
}

t_vec_d	dif_v_d(t_vec_d v1, t_vec_d v2)
{
	t_vec_d	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return (result);
}

t_vec_d	mult_v_d(t_vec_d vec, double coef)
{
	t_vec_d	result;

	result.x = vec.x * coef;
	result.y = vec.y * coef;
	return (result);
}

t_vec_d	construct_v_d(double x, double y)
{
	t_vec_d	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_vec_d	copy_v_d(t_vec_d v1)
{
	t_vec_d	result;

	result = construct_v_d(v1.x, v1.y);
	return (result);
}
