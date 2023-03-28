/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:26:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 22:33:31 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

//Functions of this file
void			check_collision(t_map *map, t_player *player,
					float advance_x, float advance_y);
static void		check_horizontal_collision(t_map *map, t_player *player,
					float advance_x);
static void		check_vertical_collision(t_map *map, t_player *player,
					float advance_y);
static void		check_diagonal_collision(t_map *map, t_player *player,
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

//Function to check collision
void	check_collision(t_map *map, t_player *player,
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
	float	aux_y;

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
	float	aux_x;

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
