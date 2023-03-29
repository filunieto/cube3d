/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:45:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/29 21:35:35 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"
/**
 * @brief 
 * Function that checks if there is more than one player or none.
 * If only 1 player is found, EXIT_SUCCESS is returned.
 * @param parsing_str 
 * @return int 
 */
int	one_player(t_pars *parsing_str)
{
	int		i;
	char	*trimmed_player;
	int		player;

	player = 0;
	i = parsing_str->nb_line_map - 1;
	while (++i <= (int)parsing_str->nb_endline_map)
	{
		trimmed_player = ft_strtrim(parsing_str->map[i], NO_PLAYER_STR);
		if (ft_strlen(trimmed_player) == 1)
		{
			parsing_str->player = trimmed_player[0];
			player++;
		}
		free(trimmed_player);
	}
	if (player == 0)
		return (print_error(ERR_MAP8_MES, ERR_MAP8));
	if (player > 1)
		return (print_error(ERR_MAP9_MES, ERR_MAP9));
	return (EXIT_SUCCESS);
}

void	define_cardinal(char **card_arr)
{
	card_arr[0] = NORTH_STR;
	card_arr[1] = SOUTH_STR;
	card_arr[2] = EAST_STR;
	card_arr[3] = WEST_STR;
	card_arr[4] = HEAVEN_STR;
	card_arr[5] = GROUND_STR;
}

void	define_error(char **error_ar)
{
	error_ar[0] = ERR_REPET_NO;
	error_ar[1] = ERR_REPET_SO;
	error_ar[2] = ERR_REPET_EA;
	error_ar[3] = ERR_REPET_WE;
	error_ar[4] = ERR_REPET_F;
	error_ar[5] = ERR_REPET_G;
}

void	define_card_char(char *card_char)
{
	card_char[0] = NORTH;
	card_char[1] = SOUTH;
	card_char[2] = EAST;
	card_char[3] = WEST;
	card_char[4] = HEAVEN;
	card_char[5] = GROUND;
}
