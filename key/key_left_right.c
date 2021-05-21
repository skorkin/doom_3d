/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_left_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:41:04 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 23:51:39 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_update_left(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	if (info->key.key_left)
	{
		oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(info->rot_speed) - info->dir.y
			* sin(info->rot_speed);
		info->dir.y = oldDirX * sin(info->rot_speed) + info->dir.y
			* cos(info->rot_speed);
		oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(info->rot_speed) - info->plane.y
			* sin(info->rot_speed);
		info->plane.y = oldPlaneX * sin(info->rot_speed) + info->plane.y
			* cos(info->rot_speed);
	}
}

void	key_update_right(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	if (info->key.key_right)
	{
		oldDirX = info->dir.x;
		info->dir.x = info->dir.x * cos(-info->rot_speed)
			- info->dir.y * sin(-info->rot_speed);
		info->dir.y = oldDirX * sin(-info->rot_speed)
			+ info->dir.y * cos(-info->rot_speed);
		oldPlaneX = info->plane.x;
		info->plane.x = info->plane.x * cos(-info->rot_speed) - info->plane.y
			* sin(-info->rot_speed);
		info->plane.y = oldPlaneX * sin(-info->rot_speed) + info->plane.y
			* cos(-info->rot_speed);
	}
}
