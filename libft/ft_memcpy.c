/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:55:00 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 22:56:23 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	if (dst1 == src1 || (n == 0))
		return (dst1);
	if (src == NULL && (dst == NULL))
		return (0);
	i = 0;
	if (n <= 0)
		return (dst1);
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}
