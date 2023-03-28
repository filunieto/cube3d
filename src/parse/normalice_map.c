/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalice_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:48 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 18:39:04 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"
/**
 * @brief 
 * We calculate the maximum number of rows of the map and add 1 to it. 
 * for the nullterminated we set for each row the maximum line length of the map,
 * which is also nullterminated. We calculate the maximum number of lines
 * of the map, which we also nullterminated. Something similar we will use 
 * to copy the structure.
 * 
 * @param parsing_str 
 * @return int 
 */
int	normalize_map(t_pars *parsing_str)
{
	int	i;
	int	len_mllc;

	len_mllc = parsing_str->nb_endline_map - parsing_str->nb_line_map + 2;
	parsing_str->map_normal = ft_calloc(sizeof(char *), len_mllc);
	if (!parsing_str->map_normal)
		return (print_error(ERR_MALLO_MES, ERR_MALLO));
	i = -1;
	while (++i < len_mllc - 1)
	{
		parsing_str->map_normal[i] = ft_calloc(sizeof(char),
				parsing_str->max_leng_map);
		if (!parsing_str->map_normal[i])
			return (print_error(ERR_MALLO_MES, ERR_MALLO));
	}
	parsing_str->map_normal[i] = NULL;
	if (copy_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief
 * Next step for normalisation. We copy each char and fill
 * with spaces in the square matrix. We will have 2 cases:
 * If the length of the line is less than the maximum length.
 * If both lengths are equal
 * @param parsing_str 
 * @return int 
 */
int	copy_map(t_pars *parsing_str)
{
	int	line_run;

	line_run = parsing_str->nb_line_map;
	while (line_run <= (int)parsing_str->nb_endline_map)
	{
		if (ft_strlen(parsing_str->map[line_run])
			< parsing_str->max_leng_map + 1)
			copy_char1(parsing_str, line_run);
		else
			copy_char2(parsing_str, line_run);
		line_run++;
	}
	return (EXIT_SUCCESS);
}

int	copy_char1(t_pars *parsing_str, int line_run)
{
	char	*map_norml;
	char	*map;
	size_t	i;

	i = -1;
	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
	map = parsing_str->map[line_run];
	while (++i < ft_strlen(map))
	{
		if (map[i] == SPACE || map[i] == EOL)
			map_norml[i] = PT;
		else if (map[i] == '1' || map[i] == '0'
			|| map[i] == parsing_str->player)
			map_norml[i] = map[i];
	}
	i--;
	while (++i < parsing_str->max_leng_map)
		map_norml[i] = PT;
	map_norml[++i] = 0;
	return (EXIT_SUCCESS);
}

int	copy_char2(t_pars *parsing_str, int line_run)
{
	char	*map_norml;
	char	*map;
	size_t	i;

	i = -1;
	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
	map = parsing_str->map[line_run];
	while (++i < parsing_str->max_leng_map)
	{
		if (map[i] == SPACE)
			map_norml[i] = PT;
		else
			map_norml[i] = map[i];
	}
	map[i] = 0;
	return (EXIT_SUCCESS);
}
