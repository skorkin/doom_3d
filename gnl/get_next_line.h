/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 07:17:27 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/22 19:55:35 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2020
# endif

typedef struct s_str
{
	char		*s;
	size_t		len;
}				t_str;

int				get_next_line(int fd, char **line);
char			*my_strjoin_c(char *s1, char *s2, char c);
char			*my_strchr(char *s, char c);

#endif
