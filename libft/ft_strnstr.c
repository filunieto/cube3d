/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 22:35:35 by anramire          #+#    #+#             */
/*   Updated: 2022/04/29 00:59:33 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test(char *aux, const char *needle, size_t i, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*aux;
	size_t	i;
	char	*ptr;

	aux = (char *)haystack;
	i = 0;
	if (needle[i] == '\0')
		return (aux);
	while (i < len && haystack[i])
	{
		if (aux[i] == needle[0])
		{
			ptr = &aux[i];
			if (test(aux, needle, i, len) != 0)
				return (ptr);
		}
		i++;
	}
	return (NULL);
}

static int	test(char *aux, const char *needle, size_t i, size_t len)
{
	size_t	j;
	size_t	k;

	j = i;
	k = 0;
	while ((j < len) && (needle[k] != '\0'))
	{
		if (aux[j] != needle[k])
			break ;
		j++;
		k++;
	}
	if (needle[k] == '\0')
		return (1);
	return (0);
}
