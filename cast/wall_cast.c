/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:00:33 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 17:28:20 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_jump(t_wall_cast *wall, t_info *info)
{
	if (wall->side_dist.x < wall->side_dist.y)
	{
		wall->side_dist.x += wall->delta_dist.x;
		wall->map.x += wall->step.x;
		wall->side = 0;
	}
	else
	{
		wall->side_dist.y += wall->delta_dist.y;
		wall->map.y += wall->step.y;
		wall->side = 1;
	}
	if (info->map.map[wall->map.x][wall->map.y] == '1')
		wall->hit = 1;
}

void	set_color_wall(t_info *info, t_wall_cast *wall)
{
	int	tex_y;
	int	color;

	tex_y = (int)wall->text_pos & (64 - 1);
	color = info->texture[wall->text_num][64 * tex_y + wall->tex_x];
	wall->text_pos += wall->step_d;
	info->buf[wall->cord.y][wall->cord.x] = color;
}

void	wall_count_draw(t_wall_cast *wall, t_info *info)
{
	wall->line_height = (int)(info->resol.heigth / wall->perp_wall_dist);
	wall->draw_start = -wall->line_height / 2 + info->resol.heigth / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + info->resol.heigth / 2;
	if (wall->draw_end >= info->resol.heigth)
		wall->draw_end = info->resol.heigth - 1;
	wall->text_num = 0;
	if (wall->side == 0)
	{
		wall->text_num = 2;
		if (wall->step.x >= 0)
			wall->text_num = 3;
		wall->wall_x = info->pos.y + wall->perp_wall_dist * wall->ray_dir.y;
	}
	else
	{
		wall->text_num = 0;
		if (wall->step.y >= 0)
			wall->text_num = 1;
		wall->wall_x = info->pos.x + wall->perp_wall_dist * wall->ray_dir.x;
	}
	wall->wall_x -= floor((wall->wall_x));
	wall->tex_x = (int)(wall->wall_x * (double)64);
}

void	wall_dda(t_info *info, t_wall_cast *wall)
{
	while (wall->hit == 0)
		wall_jump(wall, info);
	if (wall->side == 0)
		wall->perp_wall_dist = (wall->map.x
				-info->pos.x + (1 - wall->step.x) / 2) / wall->ray_dir.x;
	else
	{
		wall->perp_wall_dist = (wall->map.y
				-info->pos.y + (1 - wall->step.y) / 2) / wall->ray_dir.y;
	}
	wall_count_draw(wall, info);
	if (wall->side == 0 && wall->ray_dir.x > 0)
		wall->tex_x = 64 - wall->tex_x - 1;
	if (wall->side == 1 && wall->ray_dir.y < 0)
		wall->tex_x = 64 - wall->tex_x - 1;
	wall->step_d = 1.0 * 64 / wall->line_height;
	wall->text_pos = (wall->draw_start - info->resol.heigth
			/ 2 + wall->line_height / 2) * wall->step_d;
	wall->cord.y = wall->draw_start - 1;
}

void	wall_cast(t_info *info)
{
	t_wall_cast	wall;

	wall.cord.x = -1;
	while (++wall.cord.x < info->resol.width)
	{
		wall_init(&wall, info);
		wall_wich_dir(&wall, info);
		wall_dda(info, &wall);
		while (++wall.cord.y < wall.draw_end)
		{
			set_color_wall(info, &wall);
		}
		info->len_buf[wall.cord.x] = wall.perp_wall_dist;
	}
}
