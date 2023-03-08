/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:53:04 by anramire          #+#    #+#             */
/*   Updated: 2022/04/27 19:29:14 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(const char *str);
static void		init_v(size_t *l1, size_t *l2, char *s1, char *s2);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	init_v(&len_s1, &len_s2, (char *)s1, (char *) s2);
	dup = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		dup[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		dup[len_s1 + i] = s2[i];
		i++;
	}
	dup[len_s1 + i] = '\0';
	return (dup);
}

static size_t	get_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static void	init_v(size_t *l1, size_t *l2, char *s1, char *s2)
{
	*l1 = get_length(s1);
	*l2 = get_length(s2);
}
