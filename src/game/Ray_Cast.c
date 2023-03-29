/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray_Cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:47:59 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 22:37:45 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

//Auxiliar functions in raycasting
static void	raycast_horizontal(t_map *map, t_player *player,
				t_point_f *wall_hit_horizontal, t_data_raycast *data);
static void	raycast_vertical(t_map *map, t_player *player,
				t_point_f *wall_hit_vertical, t_data_raycast *data);
static void	set_horizontal_texture(t_map *map, t_data_raycast *data,
				t_point_f *wall_hit_horizontal, t_texture *texture);
static void	set_vertical_texture(t_map *map, t_data_raycast *data,
				t_point_f *wall_hit_vertical, t_texture *texture);

//Functions defined int Utils_Ray_Cast
extern void	vertical_ray_cast_loop(t_map *map, t_point_f *wall_hit_vertical,
				t_data_raycast *data, t_point_f *step);
extern void	horizontal_ray_cast_loop(t_map *map, t_point_f *wall_hit_horizontal,
				t_data_raycast *data, t_point_f *step);
extern void	set_data(t_data_raycast *data, float angle);

/*
 * izquierda=> 0 -> derecha, 1 -> izquierda
 * abajo=> 0 -> arriba, 1 -> abajo
*/
float	cast(t_game *game, float angle, t_point_f *p_ext, t_texture *texture)
{
	t_data_raycast	data;
	t_point_f		wall_hit_horizontal;
	t_point_f		wall_hit_vertical;
	float			vertical_distance;
	float			horizontal_distance;

	set_data(&data, angle);
	raycast_horizontal(game->map, game->player, &wall_hit_horizontal, &data);
	raycast_vertical(game->map, game->player, &wall_hit_vertical, &data);
	horizontal_distance = distancia(game->player->pos_x, game->player->pos_y,
			wall_hit_horizontal.x, wall_hit_horizontal.y);
	vertical_distance = distancia(game->player->pos_x, game->player->pos_y,
			wall_hit_vertical.x, wall_hit_vertical.y);
	if (horizontal_distance <= vertical_distance)
	{
		insert_point_f(p_ext, wall_hit_horizontal.x, wall_hit_horizontal.y);
		set_horizontal_texture(game->map, &data, &wall_hit_horizontal, texture);
		return (horizontal_distance);
	}
	else
	{
		insert_point_f(p_ext, wall_hit_vertical.x, wall_hit_vertical.y);
		set_vertical_texture(game->map, &data, &wall_hit_vertical, texture);
		return (vertical_distance);
	}	
}

static void	raycast_horizontal(t_map *map, t_player *player,
		t_point_f *wall_hit_horizontal, t_data_raycast *data)
{
	float		y_intercept;
	float		x_intercept;
	t_point_f	step;

	y_intercept
		= floor(player->pos_y / (float)map->height) * (float)map->height;
	if (data->abajo == 1)
		y_intercept += (float)map->height;
	x_intercept = player->pos_x;
	x_intercept += (y_intercept - player->pos_y) / tan(data->rads);
	step.y = map->height;
	step.x = ((float)((float)map->height) / tan(data->rads));
	wall_hit_horizontal->x = x_intercept;
	wall_hit_horizontal->y = y_intercept;
	step.x = -step.x;
	if (data->abajo == 0)
		step.y = -step.y;
	if (data->abajo == 1)
		step.x = -step.x;
	horizontal_ray_cast_loop(map, wall_hit_horizontal, data, &step);
}

static void	raycast_vertical(t_map *map, t_player *player,
		t_point_f *wall_hit_vertical, t_data_raycast *data)
{
	float		y_intercept;
	float		x_intercept;
	t_point_f	step;

	x_intercept = floor(player->pos_x / (float)map->width) * (float)map->width;
	if (data->izquierda == 0)
		x_intercept += map->width;
	y_intercept = player->pos_y;
	y_intercept += ((float)(x_intercept - player->pos_x) * tan(data->rads));
	step.x = (float)map->width;
	step.y = ((float)((float)map->height) *tan(data->rads));
	wall_hit_vertical->y = y_intercept;
	wall_hit_vertical->x = x_intercept;
	step.y = -step.y;
	if (data->izquierda == 1)
		step.x = -step.x;
	if (data->izquierda == 0)
		step.y = -step.y;
	vertical_ray_cast_loop(map, wall_hit_vertical, data, &step);
}

static void	set_horizontal_texture(t_map *map, t_data_raycast *data,
		t_point_f *wall_hit_horizontal, t_texture *texture)
{
	if (data->abajo == 1)
	{
		texture->texture = map->no;
		texture->x_texture = (1 - ((int)wall_hit_horizontal->x % map->width)
				/ (float) map->width) * ((texture->texture)->width);
	}
	else
	{
		texture->texture = map->so;
		texture->x_texture = (((int)wall_hit_horizontal->x % map->width)
				/ (float) map->width) * ((texture->texture)->width);
	}
	if (texture->x_texture >= (int)map->we->width)
		(texture->x_texture)--;
}

static void	set_vertical_texture(t_map *map, t_data_raycast *data,
		t_point_f *wall_hit_vertical, t_texture *texture)
{
	if (data->izquierda == 1)
	{
		texture->texture = map->ea;
		texture->x_texture = (1 - ((int)wall_hit_vertical->y % map->height)
				/ (float) map->height) * ((texture->texture)->height);
	}
	else
	{
		texture->texture = map->we;
		texture->x_texture = (((int)wall_hit_vertical->y % map->height)
				/ (float) map->height) * ((texture->texture)->height);
	}
	if (texture->x_texture >= (int)map->we->width)
		(texture->x_texture)--;
}
