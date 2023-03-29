/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:15:17 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/29 00:51:47 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

int	free_split_rgb(char ***rgb, char *message)
{
	int		i;
	char	**array_rgb;

	array_rgb = *rgb;
	i = -1;
	if (array_rgb)
	{
		while (array_rgb[++i])
		{
			free(array_rgb[i]);
			array_rgb[i] = NULL;
		}
	}
	free(array_rgb);
	array_rgb = NULL;
	if (message)
		printf("%s\n", message);
	return (1);
}

/**
 * @brief 
 * Verify that the file extension is .cub
 * and that the extension is at least 4 characters long.
 * We will use pointer arithmetic.
 * @param parsing_str 
 * @return true:  if file extension is ".cub"
 * @return false: other case
 */
int	is_ext_cub(t_pars *parsing_str)
{
	char	*file;
	size_t	leng_s;
	char	*extension;

	file = parsing_str->arg_1;
	leng_s = strlen(file);
	if (leng_s <= 4)
		return (1);
	extension = file + (leng_s - 1) - 3;
	if (ft_strcmp(extension, ".cub"))
		print_error(ERR_EXT_MES, ERR_EXT);
	return (EXIT_SUCCESS);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i])
// 	{
// 		if (s1[i] == s2[i])
// 			i++;
// 		else
// 			break ;
// 	}
// 	if (s1[i] == s2[i])
// 		return (0);
// 	return (1);
// }
