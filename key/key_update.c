/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 05:15:11 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/27 01:01:14 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_update_w(t_info *info)
{
	if (info->key.key_w)
	{
		if (info->map.map[(int)(info->pos.x + info->dir.x
				* info->move_speed)][(int)(info->pos.y)] == '0')
			info->pos.x += info->dir.x * info->move_speed;
		if (info->map.map[(int)(info->pos.x)][(int)(info->pos.y + info->dir.y
			* info->move_speed)] == '0')
			info->pos.y += info->dir.y * info->move_speed;
	}
}

void	key_update_s(t_info *info)
{
	if (info->key.key_s)
	{
		if (info->map.map[(int)(info->pos.x - info->dir.x
				* info->move_speed)][(int)(info->pos.y)] == '0')
			info->pos.x -= info->dir.x * info->move_speed;
		if (info->map.map[(int)(info->pos.x)][(int)(info->pos.y - info->dir.y
			* info->move_speed)] == '0')
			info->pos.y -= info->dir.y * info->move_speed;
	}
}

void	key_update_d(t_info *info)
{
	if (info->key.key_d)
	{
		if (info->map.map[(int)info->pos.x]
			[(int)(info->pos.y + info->plane.y * info->move_speed)] == '0')
			info->pos.y += info->plane.y * info->move_speed;
		if (info->map.map[(int)(info->pos.x
				+ info->plane.x * info->move_speed)][(int)info->pos.y] == '0')
			info->pos.x += info->plane.x * info->move_speed;
	}
}

void	key_update_a(t_info *info)
{
	if (info->key.key_a)
	{
		if (info->map.map[(int)info->pos.x]
			[(int)(info->pos.y - info->plane.y * info->move_speed)] == '0')
			info->pos.y -= info->plane.y
				* info->move_speed;
		if (info->map.map[(int)(info->pos.x
				- info->plane.x * info->move_speed)][(int)info->pos.y] == '0')
			info->pos.x -= info->plane.x * info->move_speed;
	}
}

void	key_update(t_info *info)
{
	key_update_w(info);
	key_update_a(info);
	key_update_s(info);
	key_update_d(info);
	key_update_left(info);
	key_update_right(info);
	if (info->key.key_esc)
		exit(0);
}
