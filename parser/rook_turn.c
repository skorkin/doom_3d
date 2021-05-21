/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rook_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:24:12 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 03:26:56 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_empty_row(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (i == (int) ft_strlen(line))
		return (1);
	return (0);
}

void	set_dir_plane(t_info *info, char symbol)
{
	if (symbol == 'N')
	{
		info->dir = construct_v_d(-1.0, 0.0);
		info->plane = construct_v_d(0.0, 0.66);
	}
	if (symbol == 'S')
	{
		info->dir = construct_v_d(1.0, 0.0);
		info->plane = construct_v_d(0.0, -0.66);
	}
	if (symbol == 'W')
	{
		info->dir = construct_v_d(0.0, -1.0);
		info->plane = construct_v_d(-0.66, 0.0);
	}
	if (symbol == 'E')
	{
		info->dir = construct_v_d(0.0, 1.0);
		info->plane = construct_v_d(0.66, 0.0);
	}
}
