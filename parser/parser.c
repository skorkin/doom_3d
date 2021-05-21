/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 05:06:36 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/27 02:18:55 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	map_init(t_info *info)
{
	info->map.map = malloc(sizeof(char *) * (info->map.count));
	if (info->map.map == NULL)
		ft_wich_error(WRONG_TEXTURE);
	buf_init(info);
}

int	tempo_parser(char *line, t_info *info, int fd)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		parser_resolution(line, &info->resol);
		return (1);
	}
	if (ft_strchr("NSWE", line[0]) && ft_strchr("OEAP ", line[1]))
	{
		parser_path(line, &info->path);
		return (1);
	}
	if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
	{
		parser_color(line, info);
		return (1);
	}
	if (is_info_full(*info))
	{
		parser_map_count(&info->map, fd, line);
		map_init(info);
		parser_map_write(info, fd, line);
		map_check(info);
		return (0);
	}
	ft_wich_error(WRONG_MAP);
	return (0);
}

int	parser(t_info *info)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(info->file, O_RDONLY);
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		info->map.begin_row ++;
		if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
		{
			i = get_next_line(fd, &line);
			continue ;
		}
		tempo_parser(line, info, fd);
		i = get_next_line(fd, &line);
	}
	close(fd);
	return (0);
}
