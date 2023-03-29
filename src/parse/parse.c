/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/29 16:37:43 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

void	free_parser(t_pars *parsing_str)
{
	if (parsing_str->map)
		free_split(&parsing_str->map);
	if (parsing_str->map_normal)
		free_split(&parsing_str->map_normal);
	if (parsing_str->north.path)
		free(parsing_str->north.path);
	if (parsing_str->south.path)
		free(parsing_str->south.path);
	if (parsing_str->east.path)
		free(parsing_str->east.path);
	if (parsing_str->west.path)
		free(parsing_str->west.path);
}

void	free_split(char ***s_splitted)
{
	int		i;
	char	**array_str;

	i = -1;
	array_str = *s_splitted;
	if (array_str)
	{
		while (array_str[++i])
		{
			free(array_str[i]);
			array_str[i] = NULL;
		}
	}
	free(array_str);
	array_str = NULL;
}

/**
 * @brief 
 * Function which , made the whole process of parsing.
 * At the end it will pass the verified parameters to the main structure. 
 * to continue running the game.
 * Check 2nd player in wall
 * @param file_mup 
 * @return int 
 */

int	ft_parse(char *file_mup, t_pars *parsing_str)
{
	init_pars(parsing_str);
	parsing_str->arg_1 = file_mup;
	if (is_ext_cub(parsing_str))
		return (EXIT_FAILURE);
	parsing_str->arg_1 = file_mup;
	parsing_str->file_inp = open(parsing_str->arg_1, O_RDONLY);
	if (parsing_str->file_inp < 0)
		return (print_error(ERR_OPEN_FILE, 1));
	if (lets_beggin_parse(parsing_str))
	{
		free_parser(parsing_str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
