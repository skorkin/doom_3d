/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:04:19 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 21:30:45 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_key(t_info *info)
{
	info->key.key_a = 0;
	info->key.key_w = 0;
	info->key.key_s = 0;
	info->key.key_d = 0;
	info->key.key_left = 0;
	info->key.key_right = 0;
	info->key.key_esc = 0;
}

void	info_init(t_info *info)
{
	init_key(info);
	info->flag_save = 0;
	info->c_color.blue = 0;
	info->c_color.green = 0;
	info->c_color.blue = 0;
	info->f_color.blue = 0;
	info->f_color.green = 0;
	info->f_color.blue = 0;
	info->resol.heigth = 0;
	info->resol.width = 0;
	info->path.east_path = NULL;
	info->path.north_path = NULL;
	info->path.south_path = NULL;
	info->path.sprite_path = NULL;
	info->path.west_path = NULL;
	info->map.count = 0;
	info->map.max_len = 0;
	info->map.map = NULL;
	info->map.begin_row = 0;
	info->sprite.pos = NULL;
	info->sprite.count = 0;
}

void	buf_init(t_info *info)
{
	int	i;

	info->buf = malloc(sizeof(int *) * info->resol.heigth);
	if (info->buf == NULL)
		ft_wich_error(NOT_MALLOC);
	i = 0;
	while (i < info->resol.heigth)
	{
		info->buf[i] = malloc(sizeof(int) * info->resol.width);
		if (info->buf[i] == NULL)
			ft_wich_error(NOT_MALLOC);
		i++;
	}
	info->len_buf = malloc(sizeof(double) * info->resol.width);
	if (info->len_buf == NULL)
		ft_wich_error(NOT_MALLOC);
}
