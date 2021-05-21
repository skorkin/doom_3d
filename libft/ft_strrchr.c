/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:37:02 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/07 01:58:54 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char			*copy;
	unsigned char			tempo;

	tempo = (unsigned char)c;
	copy = (unsigned char *)s + ft_strlen(s);
	while (copy >= (unsigned char *)s)
	{
		if (*copy == tempo)
			return ((char *)copy);
		copy--;
	}
	return (NULL);
}
