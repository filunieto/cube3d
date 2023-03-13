/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/13 20:45:44 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	check_collision(t_map *map, t_player *player, int advance_x, int advance_y);
static void	check_horizontal_collision(t_map *map, t_player *player, int advance_x);
static void	check_vertical_collision(t_map *map, t_player *player, int advance_y);
static void check_diagonal_collision(t_map *map, t_player *player, int advance_x, int advance_y);

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
	
	if(advance_y !=  0 && advance_x == 0)
		check_vertical_collision(map, player, advance_y);
	else if(advance_x != 0 && advance_y == 0)
		check_horizontal_collision(map, player, advance_x);
	else if(advance_x != 0 && advance_y != 0)
		check_diagonal_collision(map, player, advance_x, advance_y);
}

static void	check_vertical_collision(t_map *map, t_player *player, int advance_y)
{

	char c;
	unsigned int provisional_pos_y;
	int aux_advance;


	provisional_pos_y = player->pos_y + advance_y;
	if(advance_y < 0)
	{
		printf("arriba coord_y: %d\n", (int)(provisional_pos_y - (player->tam / 2)) / map->height);
		c = map->map[(provisional_pos_y - (player->tam / 2)) / map->height][player->pos_x / map->width];	
		aux_advance = -1 * ((player->pos_y - (player->tam / 2 )) % map->height);
	}
	else
	{
		printf("abajo coord_y: %d\n", (int)(provisional_pos_y + (player->tam / 2)) / map->height);
		c = map->map[(provisional_pos_y + (player->tam / 2)) / map->height][player->pos_x / map->width];
		aux_advance = map->height - player->tam - ((player->pos_y - (player->tam / 2 )) % map->height);
	}

	if(c == '1')
	{	
		player->pos_y += aux_advance;
	}
	else
	{
		player->pos_y += advance_y;
	}
}
static void	check_horizontal_collision(t_map *map, t_player *player, int advance_x)
{
	
	unsigned int provisional_pos_x;
	char c;
	int aux_advance;

	provisional_pos_x = player->pos_x + advance_x;
	if(advance_x < 0)
	{
		printf("izquierda coord_x: %d\n", (int)(provisional_pos_x - (player->tam / 2)) / map->width);
		c = map->map[player->pos_y / map->width][(provisional_pos_x - (player->tam / 2)) / map->width];
		aux_advance = -1 * ((player->pos_x - (player->tam / 2 )) % map->width);
	}
	else
	{
		printf("derecha coord_x: %d\n", (int)(provisional_pos_x + (player->tam / 2)) / map->width);
		c = map->map[player->pos_y / map->width][(provisional_pos_x + (player->tam / 2)) / map->width];	
		aux_advance = map->width - player->tam - ((player->pos_x - (player->tam / 2 )) % map->width);
	}

	if(c == '1')
	{	
		player->pos_x += aux_advance; 
	}
	else
	{
		player->pos_x += advance_x;
	}
}

static void check_diagonal_collision(t_map *map, t_player *player, int advance_x, int advance_y)
{
	printf("Diagonal\n");
	check_vertical_collision(map, player, advance_y);
	check_horizontal_collision(map, player, advance_x);
}
