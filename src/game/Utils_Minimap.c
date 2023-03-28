/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:12 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 23:31:57 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

//Auxiliar functions to adjust minimap
static void	horizontal_adjust(t_map *map, t_player *player,
				t_point_f *p_extremo);
static void	vertical_adjust(t_map *map, t_player *player,
				t_point_f *p_extremo);

void	adjust_line(t_map *map, t_player *player, t_point_f *p_extremo,
			t_point *p_final)
{
	if (distancia(player->pos_x, 0, p_extremo->x, 0)
		<= distancia(0, player->pos_y, 0, p_extremo->y))
		horizontal_adjust(map, player, p_extremo);
	else
		vertical_adjust(map, player, p_extremo);
	insert_point(p_final, (int)p_extremo->x, (int)p_extremo->y);
}

static void	horizontal_adjust(t_map *map, t_player *player,
			t_point_f *p_extremo)
{
	float	delta_x;
	float	x;
	float	y;

	if ((player->pos_y - p_extremo->y) > (float)map->semi_len)
	{
		delta_x = (-1 * (float)map->semi_len
				/ (float)tan((float)player->angle * M_PI / 180));
		insert_point_f(p_extremo, (float)player->center_point->x + delta_x,
			(float)player->center_point->y - (float)map->semi_len);
	}
	else if ((player->pos_y - p_extremo->y) < (-1 * (float)map->semi_len))
	{
		delta_x = (map->semi_len
				/ (float)tan((float)player->angle * M_PI / 180));
		insert_point_f(p_extremo, (float)player->center_point->x + delta_x,
			(float)player->center_point->y + map->semi_len);
	}
	else
	{
		x = (float)player->center_point->x + p_extremo->x - player->pos_x;
		y = (float)player->center_point->y + p_extremo->y - player->pos_y;
		insert_point_f(p_extremo, x, y);
	}
}

static void	vertical_adjust(t_map *map, t_player *p, t_point_f *p_extremo)
{
	float	delta_y;
	float	x;
	float	y;

	if ((p->pos_x - p_extremo->x) > (float)map->semi_len)
	{
		delta_y = (-1 * (float)map->semi_len
				* (float)tan((float)p->angle * M_PI / 180));
		insert_point_f(p_extremo, (float)p->center_point->x
			- (float)map->semi_len,
			(float)p->center_point->y + delta_y);
	}
	else if ((p->pos_x - p_extremo->x) < (-1 * (float)map->semi_len))
	{
		delta_y = ((float)map->semi_len
				* (float)tan((float)p->angle * M_PI / 180));
		insert_point_f(p_extremo, (float)p->center_point->x
			+ (float)map->semi_len, (float)p->center_point->y + delta_y);
	}
	else
	{
		x = (float)p->center_point->x + p_extremo->x - p->pos_x;
		y = (float)p->center_point->y + p_extremo->y - p->pos_y;
		insert_point_f(p_extremo, x, y);
	}
}
