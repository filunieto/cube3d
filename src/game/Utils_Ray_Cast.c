/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Ray_Cast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:59:19 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 20:36:58 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

//Function to calculate distance between 2 points
float	distancia(float p0x, float p0y, float p1x, float p1y)
{
	float	distance_x;
	float	distance_y;
	float	distance;

	distance_x = pow(p0x - p1x, 2);
	distance_y = pow(p0y - p1y, 2);
	distance = sqrt(distance_x + distance_y);
	return (distance);
}

//Function main loop for horizontal raycast
void	vertical_ray_cast_loop(t_map *map, t_point_f *wall_hit_vertical,
		t_data_raycast *data, t_point_f *step)
{
	int	vertical_hit;

	vertical_hit = 0;
	while (vertical_hit == 0
		&& wall_hit_vertical->x < (float)(map->width * map->columns)
		&& wall_hit_vertical->x > 1.0 && wall_hit_vertical->y > 1.0
		&& wall_hit_vertical->y < (float)(map->rows * map->height))
	{
		if (map->map[(int)wall_hit_vertical->y
				/ map->height][(int)wall_hit_vertical->x / map->width] == '1'
			|| (data->izquierda == 1 && map->map[((int)wall_hit_vertical->y)
			/ map->height][(int)(wall_hit_vertical->x - 1)
			/ map->width] == '1'))
			vertical_hit = 1;
		else
		{
			wall_hit_vertical->x += step->x;
			wall_hit_vertical->y += step->y;
		}
	}
}

void	horizontal_ray_cast_loop(t_map *map, t_point_f *wall_hit_horizontal,
		t_data_raycast *data, t_point_f *step)
{
	int	horizontal_hit;

	horizontal_hit = 0;
	while (horizontal_hit == 0
		&& wall_hit_horizontal->x < (float)(map->width * map->columns)
		&& wall_hit_horizontal->x > 1.0 && wall_hit_horizontal->y > 1.0
		&& wall_hit_horizontal->y < (float)(map->rows * map->height))
	{
		if (map->map[(int)wall_hit_horizontal->y
				/ map->height][(int)wall_hit_horizontal->x
			/ map->width] == '1' || (data->abajo == 0
			&& map->map[(int)(wall_hit_horizontal->y - 1)
			/ map->height][((int)wall_hit_horizontal->x) / map->width] == '1'))
			horizontal_hit = 1;
		else
		{
			wall_hit_horizontal->x += step->x;
			wall_hit_horizontal->y += step->y;
		}
	}
}

//Function to initialize the directions and rads in raycasting
void	set_data(t_data_raycast *data, float angle)
{
	data->rads = grades_to_rads(angle);
	data->izquierda = 0;
	data->abajo = 0;
	if (data->rads < (float)(M_PI) && data->rads > (float)0)
		data->abajo = 1;
	if (data->rads > (float)(M_PI / 2) && data->rads < (3 *(float)(M_PI / 2)))
		data->izquierda = 1;
}
