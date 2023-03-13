/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/13 19:21:49 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	check_collision(t_map *map, t_player *player, int advance_x, int advance_y);

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
	}
}


//Function to check collision
void	check_collision(t_map *map, t_player *player, int advance_x, int advance_y)
{
	unsigned int provisional_pos_x;
	unsigned int provisional_pos_y;
	char c;	
	
	provisional_pos_x = player->pos_x + advance_x;	
	provisional_pos_y = player->pos_y + advance_y;
	printf("advance_y: %ld\n", (long)advance_y);
	if(advance_y < 0)
	{
		printf("arriba coord_y: %d\n", (int)(provisional_pos_y - (player->tam / 2)) / map->height);
		c = map->map[(provisional_pos_y - (player->tam / 2)) / map->height][player->pos_x / map->width];
	}
	else
	{
		printf("abajo coord_y: %d\n", (int)(provisional_pos_y + (player->tam / 2)) / map->height);
		c = map->map[(provisional_pos_y + (player->tam / 2)) / map->height][player->pos_x / map->width];
	}
	printf("Char: %c\n", c);
	if(c == '1')
	{
		
		player->pos_x += 0; 
		player->pos_y += 0;
	}
	else
	{
		player->pos_x += round((double)advance_x);
		player->pos_y += round((double)advance_y);
	}
}
