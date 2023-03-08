/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:41:16 by anramire          #+#    #+#             */
/*   Updated: 2022/04/29 00:56:48 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;	
	size_t	slen;

	slen = ft_strlen(s);
	if (start > slen)
	{
		dup = ft_calloc(1, 1);
		return (dup);
	}
	if ((slen - start) < len)
		len = slen - start;
	dup = (char *)ft_calloc(len + 1, sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len && (s[i] != '\0'))
	{
		dup[i] = s[start + i];
		i++;
	}
	return (dup);
}
