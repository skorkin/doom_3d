/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:51:45 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/27 01:05:02 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_screenshot2(int fd, t_info *info)
{
	int32_t	x;
	int32_t	y;
	int		color;

	y = info->resol.heigth;
	while (--y >= 0)
	{
		x = -1;
		while (++x < info->resol.width)
			write (fd, &info->img.data[y * info->resol.width + x], 4);
	}
	close (fd);
}

void	*bitmap(t_info *info)
{
	static char	bitmap[54];

	ft_bzero (bitmap, 54);
	bitmap[0] = 'B';
	bitmap[1] = 'M';
	*((int *)(bitmap + 2)) = info->resol.heigth * info->resol.width * 4 + 54;
	*(int *)(bitmap + 10) = 54;
	*(int *)(bitmap + 14) = 40;
	*(int *)(bitmap + 18) = (int)info->resol.width;
	*(int *)(bitmap + 22) = (int)info->resol.heigth;
	*(bitmap + 26) = 1;
	*(bitmap + 28) = 32;
	return ((void *)bitmap);
}

void	create_screenshot(t_info *info)
{
	int		fd;
	void	*bit_map;

	fd = 0;
	fd = open ("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (fd < 0)
	{
		printf ("Error\nСreating a screenshot resulted in an error");
		exit (-1);
	}
	bit_map = bitmap(info);
	write (fd, bit_map, 54);
	create_screenshot2 (fd, info);
	exit (0);
}
