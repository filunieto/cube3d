/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 22:32:46 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

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

	if (left == 1)
		rotated_angle = (float)player->angle - 90.0;
	else if (left == -1)
		rotated_angle = (float)player->angle + 90.0;
	if (left == 1 || left == -1)
	{
		angle = (rotated_angle * M_PI) / 180;
		advance_x = (float)player->vel * cos(angle);
		advance_y = (float)player->vel * sin(angle);
		check_collision(map, player, advance_x, advance_y);
	}
}
