/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:16:24 by anramire          #+#    #+#             */
/*   Updated: 2022/04/27 19:43:07 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		get_first_pos(const char *str, const char *set);
static size_t	get_length(const char *str);
static int		get_last_pos(const char *str, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dup;
	int		f_pos;
	int		l_pos;
	int		i;

	f_pos = get_first_pos(s1, set);
	if ((get_length(s1) == 0) || (!(f_pos < (int)get_length(s1))))
		return (ft_strdup(""));
	l_pos = get_last_pos(s1, set);
	if (l_pos < 0)
		return (ft_strdup(""));
	dup = (char *)malloc((l_pos - f_pos + 2) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (f_pos <= l_pos)
	{
		dup[i] = s1[f_pos];
		i++;
		f_pos++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	get_first_pos(const char *str, const char *set)
{
	size_t	len_set;
	size_t	len_str;
	size_t	i;
	size_t	aux;

	len_str = get_length(str);
	len_set = get_length(set);
	i = 0;
	while (i < len_str)
	{
		aux = 0;
		while (aux < len_set)
		{
			if (str[i] == set[aux])
				break ;
			aux++;
		}
		if (aux == len_set)
			return (i);
		i++;
	}
	return (i);
}

static int	get_last_pos(const char *str, const char *set)
{
	int	len_set;
	int	len_str;

	len_str = get_length(str) - 1;
	while (len_str >= 0)
	{
		len_set = get_length(set) - 1;
		while (len_set >= 0)
		{
			if (str[len_str] == set[len_set])
				break ;
			len_set--;
		}
		if (len_set < 0)
			return (len_str);
		len_str--;
	}
	return (len_str);
}

static size_t	get_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
