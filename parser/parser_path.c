/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:19:36 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 04:23:23 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_xpm(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len < 4)
		ft_wich_error(NOT_XPM);
	if (line[len - 4] != '.'
		|| line[len - 3] != 'x'
		|| line[len - 2] != 'p'
		|| line[len - 1] != 'm')
		ft_wich_error(NOT_XPM);
}

void	is_cub(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len < 4)
		ft_wich_error(NOT_XPM);
	if (line[len - 4] != '.'
		|| line[len - 3] != 'c'
		|| line[len - 2] != 'u'
		|| line[len - 1] != 'b')
		ft_wich_error(NOT_XPM);
}

void	parser_path(char *tempo, t_path *path)
{
	char	*line;

	line = ft_split(tempo, ' ')[1];
	if (open (line, O_RDONLY) <= 0)
		ft_wich_error (WRONG_TEXTURE);
	if (ft_mass_strlen(ft_split(tempo, ' ')) != 2)
		ft_wich_error (WRONG_TEXTURE);
	is_xpm(line);
	if (tempo[0] == 'N' && tempo[1] == 'O' && tempo[2] == ' '
		&& path->north_path == NULL)
		path->north_path = line;
	else if (tempo[0] == 'S' && tempo[1] == 'O' && tempo[2] == ' '
		&& path->south_path == NULL)
		path->south_path = line;
	else if (tempo[0] == 'W' && tempo[1] == 'E' &&tempo[2] == ' '
		&& path->west_path == NULL)
		path->west_path = line;
	else if (tempo[0] == 'E' && tempo[1] == 'A' && tempo[2] == ' '
		&& path->east_path == NULL)
		path->east_path = line;
	else if (tempo[0] == 'S' && tempo[1] == ' ' && path->sprite_path == NULL)
		path->sprite_path = line;
	else
		ft_wich_error(WRONG_TEXTURE);
}
