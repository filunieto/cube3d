/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Draw_Map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:51:44 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 21:01:58 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

/*
 * Main loop to draw the ceil of column
 * params=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
*/

static void	check_color_columns(t_map *map, int *params, int *color, int comp);
static void	loop_draw_columns(t_map *map, t_player *player, t_4vertex *sq,
				int *aux);

void	loop_column_up(t_map *map, t_player *player, t_4vertex *sq1,
		int *params)
{
	unsigned int	rest;
	int				color;

	params[2] -= map->height;
	check_color_columns(map, params, &color, -1);
	if ((params[1] / map->height) != 0)
	{	
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y);
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y - map->height);
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y - map->height);
		params[1] -= map->height;
	}
	else
	{
		rest = params[1] % map->height;
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y);
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y - rest);
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y - rest);
		params[1] = 0;
	}
	draw_square_filled(player->img, sq1, color, 1);
}

/*
 * Main loop to draw the floor of column
 * params=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
*/
void	loop_column_down(t_map *map, t_player *player, t_4vertex *sq1,
		int *params)
{
	unsigned int	rest;
	int				color;

	params[2] += map->height;
	check_color_columns(map, params, &color, 1);
	if ((params[1] / map->height) != 0)
	{	
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y);
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y + map->height);
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y + map->height);
		params[1] -= map->height;
	}
	else
	{
		rest = params[1] % map->height;
		insert_point(&(sq1->p0), sq1->p3.x, sq1->p3.y);
		insert_point(&(sq1->p1), sq1->p2.x, sq1->p2.y);
		insert_point(&(sq1->p2), sq1->p1.x, sq1->p1.y + rest);
		insert_point(&(sq1->p3), sq1->p0.x, sq1->p0.y + rest);
		params[1] = 0;
	}
	draw_square_filled(player->img, sq1, color, 1);
}

/*
 *Function to make the main loop drawing map
 * aux=> 0 -> offset_x, 1 -> aux, 2 -> y
 * */
void	loop_draw_map(t_map *map, t_player *player, t_4vertex *sq, int *aux)
{
	unsigned int	rest;
	int				color;

	//aux[0] = ((int)player->pos_x - (aux[1] - map->semi_len)) / map->width;
	if((int)((int)player->pos_x - (aux[1] - map->semi_len)) < 0)
	{
		color = 0x000000FF;
		aux[0] = -1;
	}	
	else
	{
		aux[0] = ((int)player->pos_x - (aux[1] - map->semi_len)) / map->width;
		check_color(map->map[(int)player->pos_y / map->height][aux[0]], &color);
	}
	if ((aux[1] / map->width) != 0)
	{
		insert_point(&(sq->p0), sq->p1.x, sq->p1.y);
		insert_point(&(sq->p1), sq->p0.x + map->width, sq->p0.y);
		insert_point(&(sq->p2), sq->p0.x + map->width, sq->p0.y + map->height);
		insert_point(&(sq->p3), sq->p0.x, sq->p0.y + map->height);
		aux[1] -= map->width;
	}
	else
	{
		rest = aux[1] % map->width;
		aux[1] = 0;
		insert_point(&(sq->p0), sq->p1.x, sq->p1.y);
		insert_point(&(sq->p1), sq->p0.x + rest, sq->p0.y);
		insert_point(&(sq->p2), sq->p0.x + rest, sq->p0.y + map->height);
		insert_point(&(sq->p3), sq->p0.x, sq->p0.y + map->height);
	}
	loop_draw_columns(map, player, sq, aux);
	draw_square_filled(player->img, sq, color, 1);
}

//Function to check the colors when drawing columns
static void	check_color_columns(t_map *map, int *params, int *color, int comp)
{
	if (comp == -1)
	{
		if (params[2] < 0)
			(*color) = 0x000000FF;
		else
			check_color(map->map[params[2] / map->height][params[0]], color);
	}
	else if (comp == 1)
	{
		if ((params[2] / map->height) >= map->rows)
			*(color) = 0x000000FF;
		else
			check_color(map->map[params[2] / map->height][params[0]], color);
	}
}

static void	loop_draw_columns(t_map *map, t_player *player, t_4vertex *sq,
			int *aux)
{
	t_line	line;

	insert_points_line(&line, &(sq->p0), &(sq->p1));
	draw_column_up(map, player, &line, aux);
	insert_points_line(&line, &(sq->p2), &(sq->p3));
	draw_column_down(map, player, &line, aux);
}
