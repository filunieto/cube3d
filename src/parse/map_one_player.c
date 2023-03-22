/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:45:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/22 11:46:22 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"
//verificamos que haya un solo jugador
int	one_player(t_pars* parsing_str)
{
	int i;
	char *trimmed_player;
	int	player;

	player = 0;
	i = -1;
	i = parsing_str->nb_line_map;
	while (++i < (int)parsing_str->nb_endline_map)
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
		return(print_error(ERR_MAP8_MES, ERR_MAP8));
	if (player > 1)
		return(print_error(ERR_MAP9_MES, ERR_MAP9));
	printf("Borrar este mensaje. El jugador es %c.\n",parsing_str->player );
	return (EXIT_SUCCESS);
}
