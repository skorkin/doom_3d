/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:42:02 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 03:40:54 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_pos(t_info *info, t_vec_int ij)
{
	info->pos = construct_v_d((double)ij.x + 0.5, (double)ij.y + 0.5);
	set_dir_plane(info, info->map.map[ij.x][ij.y]);
	info->map.map[ij.x][ij.y] = '0';
}

void	legal_char_map(t_info *info)
{
	t_vec_int	ij;
	int			flag;

	ij.x = -1;
	flag = 0;
	while (++ij.x < info->map.count)
	{
		ij.y = -1;
		while (++ij.y < info->map.max_len)
		{
			if (info->map.map[ij.x][ij.y] == '2')
				info->sprite.pos = sprite_push(&info->sprite, ij.x, ij.y);
			if (ft_strchr("012 ", info->map.map[ij.x][ij.y]))
				continue ;
			if (ft_strchr("NSWE", info->map.map[ij.x][ij.y]) && flag == 0)
			{
				check_pos(info, ij);
				flag = 1;
				continue ;
			}
			ft_wich_error(WRONG_MAP_OTHER_SYM);
		}
	}
	if (flag != 1)
		ft_wich_error(WRONG_MAP_OTHER_SYM);
}

void	rook_turn(t_map map, int i, int j)
{
	int	copy;

	copy = 0;
	while (map.map[i][j - copy] != '1')
	{
		if (copy == j || (map.map[i][j - copy] == ' '))
			ft_wich_error(MAP_NOT_CLOSED);
		copy++;
	}
	copy = j - 1;
	while (map.map[i][++copy] != '1')
		if (copy == (int) ft_strlen(map.map[i]) || map.map[i][copy] == ' ')
			ft_wich_error(MAP_NOT_CLOSED);
	copy = 0;
	while (map.map[i - copy][j] != '1')
	{
		if (map.map[i - copy][j] == ' ' || copy == i)
			ft_wich_error(MAP_NOT_CLOSED);
		copy++;
	}
	copy = i - 1;
	while (map.map[++copy][j] != '1')
		if (map.map[copy][j] == ' ' || copy == (int)ft_strlen(map.map[copy]))
			ft_wich_error(MAP_NOT_CLOSED);
}

void	is_map_closed(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.count)
	{
		j = 0;
		while (j < map.max_len)
		{
			if (ft_strchr("NSWE", map.map[i][j]))
				map.map[i][j] = '0';
			if (map.map[i][j] == ' ' || map.map[i][j] == '1')
			{
				j++;
				continue ;
			}
			rook_turn(map, i, j);
			j++;
		}
		i++;
	}
}

void	map_check(t_info *info)
{
	legal_char_map(info);
	is_map_closed(info->map);
}
