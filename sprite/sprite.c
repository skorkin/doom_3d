/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:29 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 23:49:00 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_cast_init(t_sprite_cast *cast, t_info *info, int count)
{
	cast->sprite = dif_v_d(info->sprite.pos[count], info->pos);
	cast->invDet = 1.0 / (info->plane.x * info->dir.y
			- info->dir.x * info->plane.y);
	cast->transform.x = cast->invDet * (info->dir.y * cast->sprite.x
			- info->dir.x * cast->sprite.y);
	cast->transform.y = cast->invDet * (-info->plane.y * cast->sprite.x
			+ info->plane.x * cast->sprite.y);
	cast->sprite_screen_x = (int)((info->resol.width / 2)
			* (1 + cast->transform.x / cast->transform.y));
	cast->spriteHeight = (int)fabs((info->resol.heigth / cast->transform.y));
	cast->draw_start_y = -cast->spriteHeight / 2 + info->resol.heigth / 2;
	if (cast->draw_start_y < 0)
		cast->draw_start_y = 0;
	cast->draw_end_y = cast->spriteHeight / 2 + info->resol.heigth / 2;
	if (cast->draw_end_y >= info->resol.heigth)
		cast->draw_end_y = info->resol.heigth - 1;
	cast->sprite_width = (int)fabs((info->resol.heigth / cast->transform.y));
	cast->draw_start_x = -cast->sprite_width / 2 + cast->sprite_screen_x;
	if (cast->draw_start_x < 0)
		cast->draw_start_x = 0;
	cast->draw_end_x = cast->sprite_width / 2 + cast->sprite_screen_x;
	if (cast->draw_end_x >= info->resol.width)
		cast->draw_end_x = info->resol.width - 1;
}

void	set_color_sprite(t_sprite_cast *cast, t_info *info, t_vec_int draw)
{
	cast->d = (draw.y) * 256 - info->resol.heigth
		* 128 + cast->spriteHeight * 128;
	cast->tex_y = ((cast->d * 64) / cast->spriteHeight) / 256;
	cast->color = info->texture[4][64 * cast->tex_y + cast->tex_x];
	if ((cast->color & 0x00FFFFFF) != 0)
		info->buf[draw.y][draw.x] = cast->color;
}

void	sprite_cast(t_info *info)
{
	t_vec_int		count;
	t_vec_int		draw;
	t_sprite_cast	cast;

	sort_sprite(info);
	count.x = -1;
	while (++count.x < info->sprite.count)
	{
		sprite_cast_init(&cast, info, count.x);
		draw.x = cast.draw_start_x - 1;
		while (++draw.x < cast.draw_end_x)
		{
			cast.tex_x = (int)((256 * (draw.x - (-cast.sprite_width / 2
								+ cast.sprite_screen_x)) * 64
						/ cast.sprite_width) / 256);
			if (cast.transform.y > 0 && draw.x > 0 && draw.x < info->resol.width
				&& cast.transform.y < info->len_buf[draw.x])
			{
				draw.y = cast.draw_start_y - 1;
				while (++draw.y < cast.draw_end_y)
					set_color_sprite(&cast, info, draw);
			}
		}
	}
}
