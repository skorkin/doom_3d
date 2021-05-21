/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 06:23:58 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 04:29:39 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_info_full(t_info	info)
{
	if (info.resol.heigth == 0 || info.path.east_path == NULL
		|| info.path.north_path == NULL || info.path.south_path == NULL
		|| info.path.sprite_path == NULL || info.path.west_path == NULL
		// || info.map.map == NULL || info.map.max_len == 0
		|| info.f_color.blue == 0 || info.c_color.blue == 0)
		return (0);
	return (1);
}

void	parser_map_count(t_map *map, int fd, char *line)
{
	int	i;

	i = 1;
	if (map->max_len == 0)
		map->max_len = ft_strlen(line);
	while (i > 0)
	{
		if (is_empty_row(line))
		{
			close(fd);
			return ;
		}
		map->count++;
		if (map->max_len < (int)ft_strlen(line))
			map->max_len = (int)ft_strlen(line);
		i = get_next_line(fd, &line);
	}
	map->count++;
	if (map->max_len < (int)ft_strlen(line))
		map->max_len = (int)ft_strlen(line);
	close(fd);
}

void	row_copy(t_map *map, char *line, int num_row)
{
	int	count;

	count = 0;
	while (line[count])
	{
		map->map[num_row][count] = line[count];
		count++;
	}
	while (count < map->max_len)
	{
		map->map[num_row][count] = ' ';
		count++;
	}
	map->map[num_row][count] = '\0';
}

void	rewrite_map_begin(t_map *map, char *line, int fd)
{
	int	i;
	int	num_row;

	num_row = 0;
	i = 1;
	while (num_row < map->count)
	{
		map->map[num_row] = malloc(sizeof(char) * (map->max_len) + 1);
		row_copy(map, line, num_row);
		num_row++;
		i = get_next_line(fd, &line);
	}
	close(fd);
}

void	parser_map_write(t_info *info, int fd, char *line)
{
	int	i;
	int	tempo;

	tempo = info->map.begin_row - 1;
	fd = open(info->file, O_RDONLY);
	i = get_next_line(fd, &line);
	while (i)
	{
		if (tempo)
		{
			tempo--;
			i = get_next_line(fd, &line);
			continue ;
		}
		rewrite_map_begin(&info->map, line, fd);
		break ;
	}
}
