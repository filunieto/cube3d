/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:40:39 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 21:42:20 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

int check_left_up_player(t_player *player, t_map *map, int advance_x, int advance_y)
{
	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x - (player->tam / 2) + 1 ;
	aux_y = player->pos_y + advance_y - (player->tam / 2);

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}

int check_right_up_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x + (player->tam / 2) - 1;
	aux_y = player->pos_y + advance_y - (player->tam / 2) + 1;

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}


int check_left_down_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x - (player->tam / 2) + 1;
	aux_y = player->pos_y + advance_y + (player->tam / 2) - 1;

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}
int check_right_down_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x + (player->tam / 2) - 1;
	aux_y = player->pos_y + advance_y + (player->tam / 2) - 1;
	
	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}
