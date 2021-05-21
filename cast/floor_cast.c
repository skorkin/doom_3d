/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:02:58 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 02:30:29 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_cast_init(int y, t_info *info, t_vec_d
*floor_step, t_vec_d *floor)
{
	int		p;
	double	pos_z;
	double	row_distance;
	t_vec_d	ray_dir_left;
	t_vec_d	ray_dir_right;

	p = y - info->resol.heigth / 2;
	pos_z = 0.5 * info->resol.heigth;
	row_distance = pos_z / p;
	ray_dir_left = dif_v_d(info->dir, info->plane);
	ray_dir_right = sum_v_d(info->dir, info->plane);
	*floor_step = mult_v_d(dif_v_d(ray_dir_right, ray_dir_left),
			(row_distance / info->resol.width));
	*floor = sum_v_d(info->pos, mult_v_d(ray_dir_left, row_distance));
}

void	floor_cast_get_pos(t_info *info, t_vec_d *floor, t_vec_d
*floor_step, t_vec_int cord)
{
	t_vec_int	cell;
	int			tx;
	int			ty;
	int			floorTexture;
	int			color;

	cell.x = (int)(floor->x);
	cell.y = (int)(floor->y);
	tx = (int)(64 * (floor->x - cell.x)) & (64 - 1);
	ty = (int)(64 * (floor->y - cell.y)) & (64 - 1);
	floor->x += floor_step->x;
	floor->y += floor_step->y;
	floorTexture = 4;
	color = info->texture[5][64 * ty + tx];
	info->buf[cord.y][cord.x] = color;
	color = info->texture[5][64 * ty + tx];
	info->buf[info->resol.heigth - cord.y - 1][cord.x] = color;
}

void	floor_cast(t_info *info)
{
	t_vec_int	cord;
	t_vec_d		floor_step;
	t_vec_d		floor;

	cord.y = info->resol.heigth / 2;
	while (++cord.y < info->resol.heigth)
	{
		floor_cast_init(cord.y, info, &floor_step, &floor);
		cord.x = -1;
		while (++cord.x < info->resol.width)
			floor_cast_get_pos(info, &floor, &floor_step, cord);
	}
}
