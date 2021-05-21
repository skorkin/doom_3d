/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:41:08 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/22 15:04:39 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *text)
{
	ft_putstr_fd(text, 1);
	exit(0);
}

void	ft_wich_error(int error)
{
	if (error == WRONG_RESOL)
		ft_print_error("error\nWRONG RESOL\n");
	if (error == WRONG_TEXTURE)
		ft_print_error("error\nWRONG TEXTURE\n");
	if (error == WRONG_PATH)
		ft_print_error("error\nWRONG PATH TEXTURE\n");
	if (error == WRONG_COLOR)
		ft_print_error("error\nWRONG COLOR\n");
	if (error == WRONG_COLOR_COUNT)
		ft_print_error("error\nWRONG_COLOR_COUNT\n");
	if (error == KEY_DUPLICATE)
		ft_print_error("error\nKEY DUPLICATE\n");
	if (error == KEY_LOW)
		ft_print_error("error\nKEY LOW\n");
	if (error == NOT_XPM)
		ft_print_error("error\nNOT XPM\n");
	if (error == WRONG_MAP_OTHER_SYM)
		ft_print_error("error\nWRONG_MAP_OTHER_SYM\n");
	if (error == WRONG_MAP)
		ft_print_error("error\nWRONG MAP");
	if (error == MAP_NOT_CLOSED)
		ft_print_error("error\nMAP_NOT_CLOSED");
	if (error == NOT_MALLOC)
		ft_print_error("error\nNOT MALLOC");
}
