/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 03:29:33 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/13 02:12:35 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parser_color(char *str, t_info *info)
{
	if (ft_mass_strlen(ft_split(&str[2], ',')) != 3)
		ft_wich_error(WRONG_COLOR_COUNT);
	if (ft_atoi(ft_split(&str[2], ',')[0]) < 0
	|| ft_atoi(ft_split(&str[2], ',')[0]) > 255
	|| ft_atoi(ft_split(&str[2], ',')[1]) < 0
	|| ft_atoi(ft_split(&str[2], ',')[1]) > 255
	|| ft_atoi(ft_split(&str[2], ',')[2]) < 0
	|| ft_atoi(ft_split(&str[2], ',')[2]) > 255)
		ft_wich_error(WRONG_COLOR);
	if (str[0] == 'C' && str[1] == ' ')
	{
		info->c_color.red = ft_atoi(ft_split(&str[2], ',')[0]);
		info->c_color.green = ft_atoi(ft_split(&str[2], ',')[1]);
		info->c_color.blue = ft_atoi(ft_split(&str[2], ',')[2]);
		return ;
	}
	if (str[0] == 'F' && str[1] == ' ')
	{
		info->f_color.red = ft_atoi(ft_split(&str[2], ',')[0]);
		info->f_color.green = ft_atoi(ft_split(&str[2], ',')[1]);
		info->f_color.blue = ft_atoi(ft_split(&str[2], ',')[2]);
		return ;
	}
	ft_wich_error(WRONG_COLOR);
}
