/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:23:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 18:25:07 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Let's check that the arguments colours/texture , are at the beginning 
 * and we can open the path /colours. We do not check map consistency
 * If we find a correct identifier, we look at the following element 
 * that it is the correct argument for colours (int) or for textures
 * (paths that can be opened)
 * @param parsing_str 
 * @param s_splited_cleaned : array of line elements without spaces
 * @return
 */
int	check_arguments(t_pars *parsing_str, char **s_splited_cleaned)
{
	int	id;

	id = check_identifier(parsing_str, s_splited_cleaned[0]);
	if (id == 0)
		return (EXIT_FAILURE);
	if (id >= NORTH && id <= WEST)
	{
		if (check_textur_path(parsing_str, &s_splited_cleaned[1], id))
			return (EXIT_FAILURE);
		parsing_str->arg_ok += 1;
	}
	if (id == GROUND || id == HEAVEN)
	{
		if (check_colours(parsing_str, &s_splited_cleaned[1], id))
			return (EXIT_FAILURE);
		parsing_str->arg_ok += 1;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * If the first element of the line matches NO, SO, F,...
 * will return that identifier.
 * Will return an error if:
 * There is a repetition or the string is not correct.
 * @param parsing_str 
 * @param line_splitd 
 * @return int 
 */
int	check_identifier(t_pars *parsing_str, char *line_splitd)
{
	int		i;
	char	*card_arr[6] = {NORTH_STR, SOUTH_STR, 
			EAST_STR, WEST_STR, HEAVEN_STR, GROUND_STR};
	char	*error_ar[6] = {ERR_REPET_NO, ERR_REPET_SO, ERR_REPET_EA, ERR_REPET_WE, ERR_REPET_F, ERR_REPET_G};
	char	card_char[6] = {NORTH, SOUTH, EAST, WEST, HEAVEN, GROUND};

	i = -1;
	if (parsing_str->arg_ok < 6)
	{
		while (++i < 6)
		{
			if (!ft_strcmp(line_splitd, card_arr[i]))
			{
				if (parsing_str->arra_arg[i] == 0)
					return (parsing_str->arra_arg[i] = card_char[i]);
				else
					return (print_error(error_ar[i], 0));
			}
		}
		return (print_error(ERR_MAP12_MES, 0));
	}
	return (MAP);
}

/**
 * @brief 
 * 
 * @param parsing_str 
 * @param s_splited_cleaned 
 * @param id 
 * @return int 
 */
int	check_textur_path(t_pars *parsing_str, char **s_splited_cleaned, int id) //preguntara  a Andres si prefiere el path
{
	int	fd;

	if (s_splited_cleaned[1] != NULL)
		return (print_error(ERR_TEXT_INP_MES, ERR_TEXT_INP));
	fd = open(s_splited_cleaned[0], O_RDONLY, CHMOD);
	if (fd < 0)
		return (print_error(ERR_TEXT_PATH_MES, ERR_TEXT_PATH));
	if (id == NORTH)
		parsing_str->north.path = s_splited_cleaned[0];
	else if (id == SOUTH)
		parsing_str->south.path = s_splited_cleaned[0];
	else if (id == EAST)
		parsing_str->east.path = s_splited_cleaned[0];
	else if (id == WEST)
		parsing_str->west.path = s_splited_cleaned[0];
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * This function will check that the cardinal numbers and 
 * textures are at the beginning of the file.
 * When it has the necessary 6 arguments, it will consider that the following
 * is the map and will check for consistency.
 * It will parse each line, having trimmed spaces from it.
 * If the line is empty, it will not parse it and will jump to the next line.
 * @param parsing_str 
 * @return int 
 */
int	check_lines(t_pars *parsing_str)
{
	int		i;
	char	*s_trimmed;
	char	**s_splited_cleaned;

	i = -1;
	while (parsing_str->map[++i] && parsing_str->arg_ok < 6)
	{
		s_trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if (ft_strlen(s_trimmed))
		{
			s_splited_cleaned = ft_split(s_trimmed, SPACE);
			if (check_arguments(parsing_str, s_splited_cleaned))
			{
				free(s_trimmed);
				free_split(&s_splited_cleaned);
				return (EXIT_FAILURE);
			}
			free_split(&s_splited_cleaned);
		}
		free(s_trimmed);
	}
	if (parsing_str->arg_ok < 6)
		return (print_error(ERR_MAP13_MES, 1));
	parsing_str->nb_line_map = i;
	return (EXIT_SUCCESS);
}
