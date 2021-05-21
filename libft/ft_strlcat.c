/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:03:10 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:26:17 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	copylen;
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dst);
	copylen = destlen;
	i = 0;
	if (destlen < size - 1 && size > 0)
	{
		while (src[i] && destlen + i < size - 1)
			dst[copylen++] = src[i++];
		dst[copylen] = 0;
	}
	if (destlen >= size)
		destlen = size;
	return (destlen + srclen);
}
