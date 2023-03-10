/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:46:29 by anramire          #+#    #+#             */
/*   Updated: 2022/04/27 22:33:54 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_strs(char const *str, char c);
static char		**get_split_strs(const char *str, char c, size_t n, size_t *i);
static char		*copy(char const *str, size_t f_pos, size_t l_pos);
static int		init_var(size_t *i, size_t *n_strs, size_t *auxi, int init);

char	**ft_split(char const *s, char c)
{
	size_t	n_strs;
	char	**strs;
	size_t	i;

	n_strs = get_strs(s, c);
	if (n_strs == 0)
	{
		strs = (char **) malloc(sizeof (char *));
		strs[0] = NULL;
		return (strs);
	}
	return (get_split_strs(s, c, n_strs, &i));
}

static size_t	get_strs(char const *str, char c)
{
	size_t	i;
	size_t	n_strs;
	size_t	aux;

	aux = 1;
	n_strs = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (aux == 1))
		{
			n_strs++;
			aux = 0;
		}
		if (str[i] == c)
			aux = 1;
		i++;
	}
	return (n_strs);
}

static char	**get_split_strs(const char *str, char c, size_t n, size_t *i)
{
	char	**strs;
	size_t	aux;
	size_t	f_pos;

	strs = (char **)malloc((n + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	init_var(i, &n, &aux, 1);
	while (str[*i] != '\0')
	{
		if (str[*i] != c && aux == 1)
			f_pos = init_var(i, &n, &aux, 0);
		if ((str[*i] == c) && (aux == 0))
		{
			aux = 1;
			strs[n++] = copy(str, f_pos, (*i) - 1);
		}
		(*i)++;
	}
	if (str[(*i) - 1] != c)
		strs[n++] = copy(str, f_pos, (*i) - 1);
	strs[n] = NULL;
	return (strs);
}

static char	*copy(char const *str, size_t f_pos, size_t l_pos)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = (char *)malloc((l_pos - f_pos + 2) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (f_pos <= l_pos)
	{
		cpy[i] = str[f_pos];
		i++;
		f_pos++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	init_var(size_t *i, size_t *n_strs, size_t *aux, int init)
{
	if (init == 1)
	{
		(*i) = 0;
		(*n_strs) = 0;
		(*aux) = 1;
	}
	else
	{
		(*aux) = 0;
	}
	return (*i);
}
