/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/27 20:40:38 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"
//Functions of this file
static void	check_collision(t_map *map, t_player *player,
				float advance_x, float advance_y);
static void	check_horizontal_collision(t_map *map, t_player *player,
				float advance_x);
static void	check_vertical_collision(t_map *map, t_player *player,
				float advance_y);
static void	check_diagonal_collision(t_map *map, t_player *player,
				float advance_x, float advance_y);

//Functions defined in Checking_Collisions_Sides.c
extern float	check_up_collisions(t_map *map, t_player *player,
				float advance_x, float advance_y);
extern float	check_down_collisions(t_map *map, t_player *player,
				float advance_x, float advance_y);
extern float	check_left_collisions(t_map *map, t_player *player,
				float advance_x, float advance_y);
extern float	check_right_collisions(t_map *map, t_player *player,
				float advance_x, float advance_y);

//Function to move player in the direction of direction vector
void	player_advance(t_map *map, t_player *player, int direction)
{
	float	angle;
	float	advance_x;
	float	advance_y;
	angle = (player->angle * M_PI) / 180;
	if (direction == -1 || direction == 1)
	{
		advance_x = (float)direction * player->vel * cos(angle);
		advance_y = (float)direction * player->vel * sin(angle);
		check_collision(map, player, advance_x, advance_y);
	}
}

//Function to advance to the sides with 'A' or 'D', left == 1 goes to left
//left == -1 goes to right
void	player_advance_lateral(t_map *map, t_player *player, int left)
{
	
	float	angle;
	float	advance_x;
	float	advance_y;
	float	rotated_angle;

	if(left == 1)
		rotated_angle = (float)player->angle - 90.0;
	else if(left == -1)
		rotated_angle = (float)player->angle + 90.0;
	if(left == 1 || left == -1)
	{
		angle = (rotated_angle * M_PI) / 180;
		advance_x = (float)player->vel * cos(angle);
		advance_y = (float)player->vel * sin(angle);
		check_collision(map, player, advance_x, advance_y);
	}
}

//Function to check collision
static void	check_collision(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	if (advance_y != 0.0 && advance_x == 0)
		check_vertical_collision(map, player, advance_y);
	else if (advance_x != 0 && advance_y == 0)
		check_horizontal_collision(map, player, advance_x);
	else if (advance_x != 0 && advance_y != 0)
		check_diagonal_collision(map, player, advance_x, advance_y);
}

//Function to check vertical collisions with walls
static void	check_vertical_collision(t_map *map, t_player *player,
			float advance_y)
{
	float aux_y;

	aux_y = 0.0f;
	if (advance_y < 0)
		aux_y = check_up_collisions(map, player, 0, advance_y);
	else
		aux_y = check_down_collisions(map, player, 0, advance_y);
	player->pos_y = aux_y;
}

static void	check_horizontal_collision(t_map *map, t_player *player,
			float advance_x)
{	
	float aux_x;

	if (advance_x < 0)
		aux_x = check_left_collisions(map, player, advance_x, 0);
	else
		aux_x = check_right_collisions(map, player, advance_x, 0);
	player->pos_x = aux_x;
}

//Function to check diagonal collisions with walls
static void	check_diagonal_collision(t_map *map, t_player *plyr,
			float advance_x, float advance_y)
{
	if (advance_x < 0 && advance_y < 0)
	{
		plyr->pos_y = check_up_collisions(map, plyr, advance_x, advance_y);
		plyr->pos_x = check_left_collisions(map, plyr, advance_x, advance_y);
	}
	else if (advance_x > 0 && advance_y < 0)
	{
		plyr->pos_y = check_up_collisions(map, plyr, advance_x, advance_y);
		plyr->pos_x = check_right_collisions(map, plyr, advance_x, advance_y);
	}
	else if (advance_x < 0 && advance_y > 0)
	{
		plyr->pos_y = check_down_collisions(map, plyr, advance_x, advance_y);
		plyr->pos_x = check_left_collisions(map, plyr, advance_x, advance_y);
	}
	else if (advance_x > 0 && advance_y > 0)
	{
		plyr->pos_y = check_down_collisions(map, plyr, advance_x, advance_y);
		plyr->pos_x = check_right_collisions(map, plyr, advance_x, advance_y);
	}
}
