/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:24:20 by bzelda            #+#    #+#             */
/*   Updated: 2021/04/25 18:28:07 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tempo;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tempo = (unsigned int)(n * -1);
	}
	else
		tempo = (unsigned int)n;
	if (tempo >= 10)
		ft_putnbr_fd(tempo / 10, fd);
	ft_putchar_fd((char)(tempo % 10 + 48), fd);
}
