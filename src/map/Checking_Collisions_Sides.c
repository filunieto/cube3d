/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checking_Collisions_Sides.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:35:54 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 22:23:06 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"
//This functions are defined in Utils_Collisions.c
extern int	check_left_up_player(t_player *player, t_map *map,
				float advance_x, float advance_y);
extern int	check_right_up_player(t_player *player, t_map *map,
				float advance_x, float advance_y);
extern int	check_left_down_player(t_player *player, t_map *map,
				float advance_x, float advance_y);
extern int	check_right_down_player(t_player *player, t_map *map,
				float advance_x, float advance_y);

float	check_up_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_y;
	float	aux_y;

	aux_y = player->pos_y;
	if (check_right_up_player(player, map, advance_x, advance_y) == 0
		&& check_left_up_player(player, map, advance_x, advance_y) == 0)
	{
		aux_y += advance_y;
	}
	else
	{
		aux_advance_y = (((int)player->pos_y
					- (player->tam / 2)) % map->height);
		if (aux_advance_y <= (int)(player->tam / 2)
				&& (float)aux_advance_y <= (-1.0 * advance_y)
				&& aux_advance_y != 0)
			aux_y -= (float)aux_advance_y;
		else if (check_right_up_player(player, map, 0, advance_y) == 0
			&& check_left_up_player(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}

//Function to check collisions on the down horizontal line of player
float	check_down_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_y;
	float	aux_y;

	aux_y = player->pos_y;
	if (check_right_down_player(player, map, advance_x, advance_y) == 0
		&& check_left_down_player(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		aux_advance_y = map->height
			- (((int)player->pos_y + (player->tam / 2)) % map->height);
		if (aux_advance_y <= (int)(player->tam / 2)
				&& (float)aux_advance_y <= advance_y && aux_advance_y != 0)
			aux_y += (float)aux_advance_y;
		else if (check_right_down_player(player, map, 0, advance_y) == 0
			&& check_left_down_player(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}

float	check_left_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_x;
	float	aux_x;

	aux_x = player->pos_x;
	if (check_left_down_player(player, map, advance_x, advance_y) == 0
		&& check_left_up_player(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		aux_advance_x = (((int)player->pos_x - (player->tam / 2)) % map->width);
		if (aux_advance_x <= (int)(player->tam / 2)
				&& (float)aux_advance_x <= (-1.0 * advance_x)
				&& aux_advance_x != 0)
			aux_x -= (float)aux_advance_x;
		else if (check_left_down_player(player, map, advance_x, 0) == 0
			&& check_left_up_player(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}

float	check_right_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_x;
	float	aux_x;

	aux_x = player->pos_x;
	if (check_right_down_player(player, map, advance_x, advance_y) == 0
		&& check_right_up_player(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		aux_advance_x = map->width
			- (((int)player->pos_x + (player->tam / 2)) % map->width);
		if (aux_advance_x <= (int)(player->tam / 2)
			&& (float)aux_advance_x <= advance_x && aux_advance_x != 0)
			aux_x += (float)aux_advance_x;
		else if (check_right_down_player(player, map, advance_x, 0) == 0
			&& check_right_up_player(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}
