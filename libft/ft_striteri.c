/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:59:22 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 21:34:55 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	get_length(char *str);

void	ft_striteri(char *s, void (*f) (unsigned int, char *c))
{
	unsigned int	len;
	unsigned int	i;

	len = get_length(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

static	unsigned int	get_length(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
