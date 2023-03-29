/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_consistence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/29 01:37:17 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

void	draw_normalize2(t_pars *parsing_str)
{
	int	i;
	int	j;

	i = 0;
	while (parsing_str->map_normal[i])
	{
		j = 0;
		while (parsing_str->map_normal[i][j])
		{
			printf("%c", parsing_str->map_normal[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	map_closed(t_pars *parsing_str)
{
	if (normalize_map(parsing_str))
		return (EXIT_FAILURE);
	if (char_per_char_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * This function checks that we only have the characters 1, 0, W, E, W, N.
 * E, W, N.
 * 
 * @param parsing_str 
 * @return
 */
int	map_char(t_pars *parsing_str)
{
	char	*trimmed_map;
	int		i;

	i = parsing_str->nb_line_map;
	while (i <= (int)parsing_str->nb_endline_map)
	{
		trimmed_map = ft_strtrim(parsing_str->map[i], MAP_STR);
		if (ft_strlen(trimmed_map) != 0)
		{
			free(trimmed_map);
			return (print_error(ERR_MAP1_MES, ERR_MAP1));
		}
		free(trimmed_map);
		i++;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * We run through  each element of the normalised matrix. If we find a 0 or 
 * the player, we go to another function that verifies that around it,
 * there are no spaces. 
 * @param parsing_str 
 * @return int 
 */
int	char_per_char_map(t_pars *parsing_str)
{
	int	i;
	int	j;

	i = -1;
	while (parsing_str->map_normal[++i])
	{
		j = -1;
		while (parsing_str->map_normal[i][++j])
		{
			if (parsing_str->map_normal[i][j] == '0' \
			|| parsing_str->map_normal[i][j] == parsing_str->player)
				if (check_around(parsing_str, i, j))
					return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * Once we have the coordinate of the 0 or the player, we verify if 
 * there is no space around it. If a space is found, the 
 * map is not closed.
 * @param parsing_str 
 * @param i 
 * @param j 
 * @return int 
 */
int	check_around(t_pars *parsing_str, int i, int j)
{
	if (i == 0)
		return (print_error(ERR_MAP3_MES, ERR_MAP3));
	if (i == (int)(parsing_str->nb_endline_map - parsing_str->nb_line_map))
		return (print_error(ERR_MAP4_MES, ERR_MAP4));
	if (j == 0)
		return (print_error(ERR_MAP5_MES, ERR_MAP5));
	if (j == (int)parsing_str->max_leng_map - 1)
		return (print_error(ERR_MAP6_MES, ERR_MAP6));
	if (parsing_str->map_normal[i - 1][j] == PT ||
		parsing_str->map_normal[i][j - 1] == PT ||
		parsing_str->map_normal[i][j + 1] == PT ||
		parsing_str->map_normal[i + 1][j] == PT)
		return (print_error(ERR_MAP2_MES, ERR_MAP2));
	return (EXIT_SUCCESS);
}

// void	draw_normalize(t_pars *parsing_str) //borrar
// {
// 	int	i;

// 	i = 0;
// 	while (parsing_str->map_normal[i])
// 	{
// 		printf ("%s\n", parsing_str->map_normal[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
