/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 06:00:05 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:27:56 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
	return (words);
}

static int	wordlen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*freedom(char **res, int words)
{
	int	i;

	i = -1;
	while (++i < words)
		free(res[i]);
	free(res);
	return (NULL);
}

static char	**fill(char const *s, int words, char c, char **res)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = wordlen(s, c);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (freedom(res, i));
		j = 0;
		while (j < len)
			res[i][j++] = *s++;
		res[i][j] = '\0';
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char	const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = countwords(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res = fill(s, words, c, res);
	return (res);
}
