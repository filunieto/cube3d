/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/09 23:44:40 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	check_collision(t_map *map, t_player *player, unsigned int advance_x, unsigned int advance_y);

//Function to move player in the direction of direction vector
void player_advance(t_map *map, t_player *player, int direction)
{
	float angle;
	float advance_x;
	float advance_y;
	angle = (player->angle * M_PI) / 180;
	if(direction == -1 || direction == 1)
	{
		advance_x = (float)direction * player->vel * cos(angle);
		advance_y = (float)direction * player->vel * sin(angle);
		check_collision(map, player, round(advance_x), round(advance_y));
		player->pos_x += round((double)advance_x);
		player->pos_y += round((double)advance_y);
	}
}


//Function to check collision
void	check_collision(t_map *map, t_player *player, unsigned int advance_x, unsigned int advance_y)
{
	unsigned int provisional_pos_x;
	unsigned int provisional_pos_y;
	char c;	
	provisional_pos_x = player->pos_x + advance_x;	
	provisional_pos_y = player->pos_y + advance_y;
	printf("coord_y: %d\n", (int)(player->pos_y - advance_y - (player->tam / 2)) / map->height);
	c = map->map[(player->pos_y - advance_y - (player->tam / 2)) / map->height][player->pos_x];
	printf("Char: %c\n", c);
	if(map->map[(player->pos_y - advance_y - (player->tam / 2)) / map->height][player->pos_x] == '1')
		printf("Atravesando muro por arriba\n");
}
