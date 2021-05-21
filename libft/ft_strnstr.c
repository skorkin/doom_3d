/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:40:14 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:23:07 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	tempo;

	count = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (count < len && haystack[count])
	{
		if (haystack[count] == needle[0])
		{
			tempo = 0;
			while (needle[tempo] == haystack[count + tempo]
				&& count + tempo < len)
			{
				if (tempo == ft_strlen(needle) - 1)
					return ((char *)&haystack[count]);
				tempo++;
			}
		}
		count++;
	}
	return (NULL);
}
