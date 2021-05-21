/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 03:02:42 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/26 21:25:53 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	free_sprite(t_sprite *sprite)
{
	int	i;

	if (sprite == NULL)
		return (0);
	if (sprite->pos == NULL)
		return (0);
	i = 0;
	while (&sprite->pos[i] != NULL)
	{
		free (&sprite->pos[i]);
		i++;
	}
	free(sprite);
	return (0);
}
