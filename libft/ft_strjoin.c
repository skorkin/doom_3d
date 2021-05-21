/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:47:35 by bzelda            #+#    #+#             */
/*   Updated: 2020/11/13 17:43:01 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	countfirst;
	size_t	countsecond;

	countfirst = 0;
	countsecond = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	res = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (res == NULL)
		return (NULL);
	while (s1[countfirst])
	{
		res[countfirst] = s1[countfirst];
		countfirst++;
	}
	while (s2[countsecond])
	{
		res[countsecond + countfirst] = s2[countsecond];
		countsecond++;
	}
	res[countfirst + countsecond] = '\0';
	return (res);
}
