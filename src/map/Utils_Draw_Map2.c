/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Draw_Map2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:40:27 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 22:30:29 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

//Function to check when we are out of map borders to select the correct color
void	check_outside_colors(t_map *map, t_player *player, int *color, int *aux)
{
	if ((int)((int)player->pos_x - (aux[1]
			- map->semi_len)) < 0)
	{
		*color = 0x000000FF;
		aux[0] = -1;
	}	
	else
	{
		aux[0] = ((int)player->pos_x - (aux[1] - map->semi_len)) / map->width;
		check_color(map->map[(int)player->pos_y / map->height][aux[0]], color);
	}
}
