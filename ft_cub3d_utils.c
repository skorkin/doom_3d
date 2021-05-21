/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 12:19:52 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 21:41:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mass_strlen(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

void	is_save(char **argv, t_info *info, int argc)
{
	if (argc == 3 && ft_strlen(argv[2]) == 6)
		if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
			&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e'
			&& argv[2][6] == '\0')
			info->flag_save = 1;
}

void	set_cub(t_info *info, char **argv, int argc)
{
	if (argc > 3)
		ft_wich_error(WRONG_MAP);
	if (argc == 3 && info->flag_save == 0)
		ft_wich_error(WRONG_MAP);
	is_cub(argv[1]);
	if (open (argv[1], O_RDONLY) <= 0)
		ft_wich_error (WRONG_MAP);
	info->file = malloc(sizeof(char) * ft_strlen(argv[1]) + 1);
	ft_strlcpy(info->file, argv[1], ft_strlen(argv[1]) + 1);
}
