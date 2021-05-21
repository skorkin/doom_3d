/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:33:34 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:26:31 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*bump;

	if (c == '\0')
	{
		bump = (char *)s;
		return (bump + ft_strlen(s));
	}
	return (ft_memchr(s, c, ft_strlen(s)));
}
