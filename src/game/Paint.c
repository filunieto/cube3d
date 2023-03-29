/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 21:26:45 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

static void	casting(t_game *game);

static void	draw_ceil_and_floor(t_map *map, t_player *player);

//Extern auxiliar functions defined in Utils_Paint
extern void	loop_casting(t_game *game, float init_angle,
				float increment_angle, t_texture *texture);

//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{
	clear_image(game->player);
	draw_ceil_and_floor(game->map, game->player);
	casting(game);
	draw_map(game->map, game->player);
	paint_player(game->player);
}

void	casting(t_game *game)
{
	float		increment_angle;
	float		init_angle;
	t_texture	texture;

	increment_angle = game->player->fov / (float)game->player->screen_x;
	init_angle = (float)game->player->angle - (game->player->fov / 2);
	init_angle = normalize_angle(init_angle);
	loop_casting(game, init_angle, increment_angle, &texture);
}

static void	draw_ceil_and_floor(t_map *map, t_player *player)
{
	t_4vertex	ceil;
	t_4vertex	floor;

	insert_point(&(ceil.p0), 1, 1);
	insert_point(&(ceil.p1), player->screen_x - 1, 1);
	insert_point(&(ceil.p2), player->screen_x - 1, player->screen_y / 2);
	insert_point(&(ceil.p3), 1, player->screen_y / 2);
	insert_point(&(floor.p0), 1, player->screen_y / 2);
	insert_point(&(floor.p1), player->screen_x - 1, player->screen_y / 2);
	insert_point(&(floor.p2), player->screen_x - 1, player->screen_y - 1);
	insert_point(&(floor.p3), 1, player->screen_y - 1);
	draw_square_filled(player->img, &ceil, map->ceil_color, 1);
	draw_square_filled(player->img, &floor, map->floor_color, 1);
}
