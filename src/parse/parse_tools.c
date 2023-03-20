/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:15:17 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/20 12:57:01 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

void free_split (char ***s_splitted)
{
	int i;
	char **array_str;

	i = -1;
	array_str = *s_splitted;
	while (array_str[++i])
	{
		free(array_str[i]);
		array_str[i] = NULL;
	}
	free(array_str);
	array_str = NULL;
}


/*
	Por qué no está
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if (s1[i] == s2[i])
		return (0);
	return (1);
}
