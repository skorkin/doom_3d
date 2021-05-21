/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:56:39 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 04:01:27 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->path.east_path, &img);
	load_image(info, info->texture[1], info->path.north_path, &img);
	load_image(info, info->texture[2], info->path.south_path, &img);
	load_image(info, info->texture[3], info->path.west_path, &img);
	load_image(info, info->texture[4], info->path.sprite_path, &img);
	load_image(info, info->texture[5], "textures/wood.xpm", &img);
}

int	set_texture(t_info *info)
{
	t_vec_int	cord;

	cord.x = -1;
	info->texture = (int **)malloc(sizeof(int *) * 7);
	if (info->texture == NULL)
		return (-1);
	while (++cord.x < 7)
	{
		info->texture[cord.x] = (int *)malloc(sizeof(int) * (64 * 64));
		if (info->texture[cord.x] == NULL)
			return (-1);
	}
	cord.x = -1;
	while (++cord.x < 7)
	{
		cord.y = -1;
		while (++cord.y < 64 * 64)
			info->texture[cord.x][cord.y] = 0;
	}
	return (1);
}
