/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:12 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 18:47:55 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void adjust_line(t_map *map, t_player *player, t_point_f *p_extremo, t_point *p_final)
{
	float delta_x;
	float delta_y;
	float x;
	float y;

	if(distancia(player->pos_x, 0, p_extremo->x, 0) <= distancia(0, player->pos_y, 0, p_extremo->y))
	{
		if((player->pos_y - p_extremo->y) > (float)map->semi_len)
		{
			delta_x = (-1 * (float)map->semi_len / (float)tan((float)player->angle * M_PI / 180));
			insert_point_f(p_extremo, (float)player->center_point->x + delta_x, (float)player->center_point->y - (float)map->semi_len);
		}
		else if((player->pos_y - p_extremo->y) < (-1 * (float)map->semi_len))
		{
			delta_x = (map->semi_len / (float)tan((float)player->angle * M_PI / 180));
			insert_point_f(p_extremo, (float)player->center_point->x + delta_x, (float)player->center_point->y + map->semi_len);
		}
		else
		{
			x = (float)player->center_point->x + p_extremo->x - player->pos_x;
			y = (float)player->center_point->y + p_extremo->y - player->pos_y;
			insert_point_f(p_extremo, x, y);
		}
	}
	else
	{
		if((player->pos_x - p_extremo->x) > (float)map->semi_len)
		{
			delta_y = (-1 * (float)map->semi_len * (float)tan((float)player->angle * M_PI / 180));
			insert_point_f(p_extremo, (float)player->center_point->x - (float)map->semi_len, (float)player->center_point->y + delta_y);
		}
		else if((player->pos_x - p_extremo->x) < (-1 * (float)map->semi_len))
		{
			delta_y = ((float)map->semi_len * (float)tan((float)player->angle * M_PI / 180));
			insert_point_f(p_extremo, (float)player->center_point->x + (float)map->semi_len, (float)player->center_point->y + delta_y);
		}
		else
		{
			x = (float)player->center_point->x + p_extremo->x - player->pos_x;
			y = (float)player->center_point->y + p_extremo->y - player->pos_y;
			insert_point_f(p_extremo, x, y);
		}
	}

	insert_point(p_final, (int)p_extremo->x, (int)p_extremo->y);
}
