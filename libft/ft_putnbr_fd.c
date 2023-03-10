/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:13:22 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 18:48:51 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	copia;

	copia = n;
	if (copia < 0)
	{
		ft_putchar_fd('-', fd);
		copia = copia * (-1);
	}
	if (copia > 9)
	{
		ft_putnbr_fd(copia / 10, fd);
		ft_putchar_fd('0' + (copia % 10), fd);
	}
	else
	{
		ft_putchar_fd('0' + copia, fd);
	}
}
