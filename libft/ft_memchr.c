/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:25:25 by anramire          #+#    #+#             */
/*   Updated: 2022/04/21 22:22:54 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ocurrence;	
	size_t			i;

	i = 0;
	ocurrence = (unsigned char)c;
	while (i < n)
	{
		if ((*(unsigned char *)s) == ocurrence)
			return ((unsigned char *)s);
		s++;
		i++;
	}
	return (NULL);
}
