/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:49:19 by anramire          #+#    #+#             */
/*   Updated: 2022/04/29 00:49:07 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	char	*aux;
	int		len;

	len = (int)get_length(s);
	aux = (char *)s;
	aux = aux + len;
	while (len >= 0)
	{
		if ((*aux) == (char)c)
			return (aux);
		aux--;
		len--;
	}
	return (NULL);
}

static size_t	get_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
