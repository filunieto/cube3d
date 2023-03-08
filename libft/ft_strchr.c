/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:06:14 by anramire          #+#    #+#             */
/*   Updated: 2022/04/29 00:48:08 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(const char *str);

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;
	char	*aux;

	aux = (char *)s;
	len = get_length(s);
	i = 0;
	while (i <= len)
	{
		if ((*aux) == (char)c)
			return (aux);
		aux++;
		i++;
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
