/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:28:31 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/13 17:47:29 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	count;

	if (s == 0)
		return (0);
	count = 0;
	res = malloc(len * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	if (start >= ft_strlen(s) - 1)
	{
		res[0] = '\0';
		return (res);
	}
	if (s)
	{
		while (len--)
		{
			res[count] = s[start + count];
			count++;
		}
		res[count] = '\0';
	}
	return (res);
}
