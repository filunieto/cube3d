/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:42:29 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 00:16:38 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_length(char const *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_returned;
	unsigned int	len;

	len = get_length(s);
	str_returned = (char *)malloc((1 + len) * sizeof(char));
	if (str_returned == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_returned[i] = f(i, s[i]);
		i++;
	}
	str_returned[i] = '\0';
	return (str_returned);
}

static unsigned int	get_length(char const *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
