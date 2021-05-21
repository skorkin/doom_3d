/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:53 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 21:05:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vec_d	*sprite_push(t_sprite *sprite, int x, int y)
{
	t_vec_d	*new_mas_pos;
	int		tempo;

	sprite->count++;
	new_mas_pos = malloc(sizeof(t_vec_d) * (sprite->count));
	if (new_mas_pos == NULL)
		ft_wich_error(NOT_MALLOC);
	tempo = 0;
	while (tempo < sprite->count - 1)
	{
		new_mas_pos[tempo] = construct_v_d(sprite->pos[tempo].x,
				sprite->pos[tempo].y);
		tempo++;
	}
	new_mas_pos[tempo] = construct_v_d((double)x + 0.5, (double)y + 0.5);
	free(sprite->pos);
	return (new_mas_pos);
}

double	sprite_distance(t_info *info, int wich)
{
	return (
		fabs(info->pos.x - info->sprite.pos[wich].x)
		* (fabs(info->pos.x - info->sprite.pos[wich].x))
		+ (fabs(info->pos.y - info->sprite.pos[wich].y))
		* (fabs(info->pos.y - info->sprite.pos[wich].y))
	);
}

void	sprite_swap(t_sprite *sprite, int first_sprite, int second_sprite)
{
	t_vec_d	tempo;

	tempo = copy_v_d(sprite->pos[first_sprite]);
	sprite->pos[first_sprite] = copy_v_d(sprite->pos[second_sprite]);
	sprite->pos[second_sprite] = copy_v_d(tempo);
}

void	sort_sprite(t_info *info)
{
	t_vec_int	count;

	count.x = -1;
	while (++count.x < info->sprite.count)
	{
		count.y = 0;
		while (count.y < info->sprite.count - 1)
		{
			if (sprite_distance(info, count.y)
				< sprite_distance(info, count.y + 1))
				sprite_swap(&info->sprite, count.y, count.y + 1);
			count.y++;
		}
	}
}
