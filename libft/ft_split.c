/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:46:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 18:46:37 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_countsubs(const char *s, char c, size_t *n_subs)
{
	char	*travers;

	*n_subs = 0;
	if (!s)
		return ;
	travers = (char *)s;
	while (*travers)
	{
		if (*travers == c)
			travers++;
		else
		{
			(*n_subs)++;
			while (*travers && *travers != c)
				travers++;
		}
	}
}

static void	ft_free_str(char ***arr_str, size_t i_failedsub)
{
	size_t	i;

	i = 0;
	while (i < i_failedsub)
	{
		free((*arr_str)[i]);
		i++;
	}
	free(*arr_str);
	*arr_str = NULL;
}

static char	*ft_makesub(char *travers, char c, size_t *sublen)
{
	char	*endofsub;
	char	*sub;

	endofsub = ft_strchr(travers, c);
	if (!endofsub)
		*sublen = ft_strlen(travers);
	else
		*sublen = endofsub - travers;
	sub = ft_calloc(((*sublen) + 1), sizeof(char));
	if (!sub)
		return (NULL);
	return (ft_memcpy(sub, travers, *sublen));
}

static void	ft_fill_arr(const char *s, char c, size_t n_subs, char ***arr_str)
{
	char	*travers;
	size_t	sublen;
	size_t	i;

	i = 0;
	travers = (char *)s;
	while (i < n_subs)
	{
		while (*travers == c)
			travers++;
		(*arr_str)[i] = ft_makesub(travers, c, &sublen);
		if (!(*arr_str)[i])
			ft_free_str(arr_str, i);
		i++;
		travers = travers + sublen;
	}
	(*arr_str)[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**arr_str;
	size_t	n_subs;

	if (!s)
		return (NULL);
	ft_countsubs(s, c, &n_subs);
	arr_str = malloc((n_subs + 1) * sizeof(char *));
	if (!arr_str)
		return (NULL);
	ft_fill_arr(s, c, n_subs, &arr_str);
	return (arr_str);
}
