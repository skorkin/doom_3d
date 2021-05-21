/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:08:21 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 18:56:11 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key.key_w = 1;
	else if (key == A)
		info->key.key_a = 1;
	else if (key == S)
		info->key.key_s = 1;
	else if (key == D)
		info->key.key_d = 1;
	else if (key == LEFT)
		info->key.key_left = 1;
	else if (key == RIGHT)
		info->key.key_right = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == ESC)
		exit(0);
	else if (key == W)
		info->key.key_w = 0;
	else if (key == A)
		info->key.key_a = 0;
	else if (key == S)
		info->key.key_s = 0;
	else if (key == D)
		info->key.key_d = 0;
	else if (key == LEFT)
		info->key.key_left = 0;
	else if (key == RIGHT)
		info->key.key_right = 0;
	return (0);
}
