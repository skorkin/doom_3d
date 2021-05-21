/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:37:06 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:39:26 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec_int	sum_v_i(t_vec_int v1, char symb, t_vec_int v2)
{
	t_vec_int	result;

	if (symb == '+')
	{
		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;
		return (result);
	}
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	return (result);
}

t_vec_int	mult_v_i(t_vec_int vec, int coef)
{
	t_vec_int	result;

	result.x = vec.x * coef;
	result.y = vec.y * coef;
	return (result);
}

t_vec_int	construct_v_i(int x, int y)
{
	t_vec_int	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_vec_int	vec_d_into_i(t_vec_d vec_double)
{
	t_vec_int	result;

	result.x = (int)vec_double.x;
	result.y = (int)vec_double.y;
	return (result);
}

t_vec_int	vec_f_into_i(t_vec_d vec_float)
{
	t_vec_int	result;

	result.x = (int)vec_float.x;
	result.y = (int)vec_float.y;
	return (result);
}
