/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cast_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:40:31 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/23 19:40:32 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_wich_dir(t_wall_cast *wall, t_info *info)
{	
	if (wall->ray_dir.x < 0)
	{
		wall->step.x = -1;
		wall->side_dist.x = (info->pos.x - wall->map.x) * wall->delta_dist.x;
	}
	else
	{
		wall->step.x = 1;
		wall->side_dist.x = (wall->map.x + 1.0
				- info->pos.x) * wall->delta_dist.x;
	}
	if (wall->ray_dir.y < 0)
	{
		wall->step.y = -1;
		wall->side_dist.y = (info->pos.y
				- wall->map.y) * wall->delta_dist.y;
	}
	else
	{
		wall->step.y = 1;
		wall->side_dist.y = (wall->map.y + 1.0
				- info->pos.y) * wall->delta_dist.y;
	}
}

void	wall_init(t_wall_cast *wall, t_info *info)
{
	double	cameraX;

	cameraX = 2 * wall->cord.x / (double)info->resol.width - 1;
	wall->ray_dir = (sum_v_d(info->dir, (mult_v_d(info->plane, cameraX))));
	wall->map = construct_v_i((int)info->pos.x, (int)info->pos.y);
	wall->delta_dist.x = fabs(1 / wall->ray_dir.x);
	wall->delta_dist.y = fabs(1 / wall->ray_dir.y);
	wall->hit = 0;
}
