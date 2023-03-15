/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 23:06:39 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

//Functions of this file
static void	check_collision(t_map *map, t_player *player,
				int advance_x, int advance_y);
static void	check_horizontal_collision(t_map *map, t_player *player,
				int advance_x);
static void	check_vertical_collision(t_map *map, t_player *player,
				int advance_y);
static void	check_diagonal_collision(t_map *map, t_player *player,
				int advance_x, int advance_y);

//Functions defined in Checking_Collisions_Sides.c
extern int	check_up_collisions(t_map *map, t_player *player,
				int advance_x, int advance_y);
extern int	check_down_collisions(t_map *map, t_player *player,
				int advance_x, int advance_y);
extern int	check_left_collisions(t_map *map, t_player *player,
				int advance_x, int advance_y);
extern int	check_right_collisions(t_map *map, t_player *player,
				int advance_x, int advance_y);

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
		check_collision(map, player, round(advance_x), round(advance_y));
	}
}

//Function to check collision
static void	check_collision(t_map *map, t_player *player,
			int advance_x, int advance_y)
{
	if (advance_y != 0 && advance_x == 0)
		check_vertical_collision(map, player, advance_y);
	else if (advance_x != 0 && advance_y == 0)
		check_horizontal_collision(map, player, advance_x);
	else if (advance_x != 0 && advance_y != 0)
		check_diagonal_collision(map, player, advance_x, advance_y);
	printf("Player pos=> x: %d, y: %d\n", player->pos_x, player->pos_y);
}

//Function to check vertical collisions with walls
static void	check_vertical_collision(t_map *map, t_player *player,
			int advance_y)
{
	int	aux_y;

	if (advance_y < 0)
		aux_y = check_up_collisions(map, player, 0, advance_y);
	else
		aux_y = check_down_collisions(map, player, 0, advance_y);
	player->pos_y = aux_y;
}

static void	check_horizontal_collision(t_map *map, t_player *player,
			int advance_x)
{	
	int	aux_x;

	if (advance_x < 0)
		aux_x = check_left_collisions(map, player, advance_x, 0);
	else
		aux_x = check_right_collisions(map, player, advance_x, 0);
	player->pos_x = aux_x;
}

//Function to check diagonal collisions with walls
static void	check_diagonal_collision(t_map *map, t_player *plyr,
			int advance_x, int advance_y)
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
