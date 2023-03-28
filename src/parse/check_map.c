/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:05 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/28 12:26:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * We calculate the parameters of the map. On which line it starts,
 * where it ends and the maximum length of its lines.
 * From this we check the consistency of the map.
 * That there is only one player, that there are no
 * incorrect characters and that is closed by 1.
 * @param parsing_str 
 * @return int 
 */
int	check_map(t_pars *parsing_str)
{
	if (find_init(parsing_str))
		return (print_error(ERR_MAP10_MES, ERR_MAP10));
	parsing_str->nb_endline_map = find_end(parsing_str);
	parsing_str->max_leng_map = find_max_line(parsing_str);
	if (parsing_str->nb_endline_map - parsing_str->nb_line_map < 2)
		return (print_error(ERR_MAP0_MES, ERR_MAP0));
	if (parsing_str->nb_line_map < 6)
		return (print_error(ERR_MAP10_MES, ERR_MAP10));
	if (is_map_consistent(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_consistent(t_pars *parsing_str)
{
	if (map_char(parsing_str))
		return (EXIT_FAILURE);
	if (one_player(parsing_str))
		return (EXIT_FAILURE);
	if (map_closed(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * Returns the first line where the map starts. Does not check
 * consistency
 * @param parsing_str 
 * @return 
 */
int	find_init(t_pars *parsing_str)
{
	char	*trimmed_spac;
	int		leng_strim;

	while (parsing_str->map[parsing_str->nb_line_map])
	{
		trimmed_spac = ft_strtrim(parsing_str->map[parsing_str->nb_line_map],
				SPACE_STR);
		leng_strim = ft_strlen(trimmed_spac);
		free(trimmed_spac);
		if (leng_strim == 0)
			parsing_str->nb_line_map++;
		else
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * @brief 
 * Returns the last line where the map finishes. Does not check
 * consistency
 * @param parsing_str 
 * @return int valor del final
 */
int	find_end(t_pars *parsing_str)
{
	int		i;
	char	*trimmed_spac;
	int		end;
	int		leng_line;

	end = parsing_str->nb_line - 2;
	i = 0;
	while (end >= (int)parsing_str->nb_line_map)
	{
		trimmed_spac = ft_strtrim(parsing_str->map[end], SPACE_STR);
		leng_line = ft_strlen(trimmed_spac);
		free(trimmed_spac);
		if (leng_line == 0)
			i++;
		else
			break ;
		end--;
	}
	return (end);
}

/**
 * @brief 
 * Returns the maximum length of the lines belonging to map for calculating the 
 * normalised matrix. 
 * @param parsing_str 
 * @return Length of max line in map not including char \n .
 */
int	find_max_line(t_pars *parsing_str)
{
	size_t	max_leng_map;
	size_t	leng_line;
	int		i;

	max_leng_map = 0;
	i = parsing_str->nb_line_map;
	while (i <= (int)parsing_str->nb_endline_map)
	{
		leng_line = ft_strlen(parsing_str->map[i]);
		if (leng_line > max_leng_map)
			max_leng_map = leng_line;
		i++;
	}
	return (max_leng_map - 1);
}
