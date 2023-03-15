/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Draw_Map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:51:44 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 18:53:45 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

/*
 * Main loop to draw the ceil of column
 * Auxiliar_values=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
*/
void	loop_column_up(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values)
{
	unsigned int rest;
	int color;

	(auxiliar_values[2]) -= map->height;
	if(auxiliar_values[2]< 0)
		color = 0x000000FF;	
	else
		check_color(map->map[auxiliar_values[2]/ map->height][auxiliar_values[0]], &color);
	if((auxiliar_values[1] / 60) != 0)
	{	
			insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y);	
			insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y);
			insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y - map->height);
			insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y - map->height);
			auxiliar_values[1] -= map->height;
	}
	else
	{
		rest = auxiliar_values[1] % map->height;	
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y);	
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y);
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y - rest);
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y - rest);	
		auxiliar_values[1] = 0;
	}
	draw_square_filled(player->img, sq1, color, 1);
}

/*
 * Main loop to draw the floor of column
 * Auxiliar_values=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
*/
void	loop_column_down(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values)
{
	unsigned int rest;
	int color;
	auxiliar_values[2] += map->height;
	if((auxiliar_values[2]/ map->height) >= map->rows)
		color = 0x000000FF;	
	else
		check_color(map->map[auxiliar_values[2]/ map->height][auxiliar_values[0]], &color);	
	if((auxiliar_values[1] / 60) != 0)
	{	
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y);	
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y + map->height);
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y + map->height);
		auxiliar_values[1] -= map->height;
	}
	else
	{
		rest = auxiliar_values[1] % map->height;	
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y);	
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y + rest);
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y + rest);
		auxiliar_values[1] = 0;
	}
	draw_square_filled(player->img, sq1, color, 1);
}


/*
 *Function to make the main loop drawing map
 * aux=> 0 -> offset_x, 1 -> aux, 2 -> y
 * */
void	loop_draw_map(t_map *map, t_player *player, t_4vertex *sq, int *auxiliar_values)
{
	unsigned int rest;
	int color;

	auxiliar_values[0] = (player->pos_x - (auxiliar_values[1] - map->semi_len)) / map->width;
	check_color(map->map[player->pos_y / map->height][auxiliar_values[0]], &color);
	if ((auxiliar_values[1] / map->width) != 0)	
	{
		insert_point(&(sq->p0), sq->p1.x, sq->p1.y);
		insert_point(&(sq->p1), sq->p0.x + map->width, sq->p0.y);
		insert_point(&(sq->p2), sq->p0.x + map->width, sq->p0.y + map->height);
		insert_point(&(sq->p3), sq->p0.x, sq->p0.y + map->height);	
		auxiliar_values[1] -= map->width;
	}
	else
	{
		rest = auxiliar_values[1] % map->width;
		auxiliar_values[1] = 0;
		insert_point(&(sq->p0), sq->p1.x, sq->p1.y);
		insert_point(&(sq->p1), sq->p0.x + rest, sq->p0.y);
		insert_point(&(sq->p2), sq->p0.x + rest, sq->p0.y + map->height);
		insert_point(&(sq->p3), sq->p0.x, sq->p0.y + map->height);
	}
	draw_column_up(map, player, &(sq->p0), &(sq->p1), auxiliar_values[2], auxiliar_values[0]);
	draw_column_down(map, player, &(sq->p2), &(sq->p3), auxiliar_values[2], auxiliar_values[0]);
	draw_square_filled(player->img, sq, color, 1);
}
