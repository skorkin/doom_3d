/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:19:29 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 03:41:11 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_info *info)
{
	int	count;

	count = 0;
	while (info->map.map[count])
	{
		if (info->map.map[count] != NULL)
			free (info->map.map[count]);
		count++;
	}
	if (info->map.map != NULL)
		free (info->map.map);
	if (info->map.map != NULL)
		free (info->map.map);
	if (info->map.count != NULL)
		free (info->map.count);
	if (info->map.max_len != NULL)
		free (info->map.max_len);
}

void	free_resol(t_info *info)
{
	if (info->resol.heigth != NULL)
		free(info->resol.heigth);
	if (info->resol.width != NULL)
		free(info->resol.width);
}

void	free_color(t_info *info)
{
	if (info->c_color.blue != NULL)
		free (info->c_color.blue);
	if (info->c_color.red != NULL)
		free (info->c_color.red);
	if (info->c_color.green != NULL)
		free (info->c_color.green);
	if (info->f_color.blue != NULL)
		free (info->f_color.blue);
	if (info->f_color.red != NULL)
		free (info->f_color.red);
	if (info->f_color.green != NULL)
		free (info->f_color.green);
}

void	free_texture(t_info *info)
{
	if (info->path.east_path != NULL)
		free (info->path.east_path);
	if (info->path.west_path != NULL)
		free (info->path.west_path);
	if (info->path.north_path != NULL)
		free (info->path.north_path);
	if (info->path.south_path != NULL)
		free (info->path.south_path);
	if (info->path.sprite_path != NULL)
		free (info->path.sprite_path);
}

void	free_input(t_info *info)
{
	free_color(info);
	free_texture(info);
	free_map(info);
	free_resol(info);
}
