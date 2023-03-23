/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:15:17 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/23 13:03:02 by fnieves-         ###   ########.fr       */
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

/**
 * @brief 
 * Verify that the file extension is .cub
 * and that the extension is at least 4 characters long.
 * We will use pointer arithmetic.
 * 
 * @param parsing_str 
 * @return true:  if file extension is ".cub"
 * @return false: other case
 */
int  is_ext_cub(t_pars* parsing_str)
{
	char *file;
	size_t  leng_s;
	char	*extension;
	
	file = parsing_str->arg_1;
	leng_s =  strlen(file);
	if (leng_s <= 4)
		return (1);
	extension = file + (leng_s - 1) - 3;
	if (ft_strcmp(extension, ".cub"))
		print_error(ERR_EXT_MES, ERR_EXT);
	return (EXIT_SUCCESS);
}
