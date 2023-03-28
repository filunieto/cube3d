/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray_Cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:47:59 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 23:47:56 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

/*
 * izquierda=> 0 -> derecha, 1 -> izquierda
 * abajo=> 0 -> arriba, 1 -> abajo
*/
float	cast(t_map *map, t_player *player, float angle, t_point_f *p_ext, int *x_texture, mlx_texture_t **texture)
{
	int		izquierda;
	int		abajo;
	float	rads;
	float	y_intercept;
	float	x_intercept;
	float	step_y;
	float	step_x;
	float	wall_hit_x_horizontal;
	float	wall_hit_y_horizontal;
	int		horizontal_hit;
	float	wall_hit_x_vertical;
	float	wall_hit_y_vertical;
	int		vertical_hit;
	
	rads = grades_to_rads(angle);
	horizontal_hit = 0;
	izquierda = 0;
	abajo = 0;
	if(rads < (float)(M_PI) && rads > (float)0)
		abajo = 1;

	if(rads > (float)(M_PI / 2) && rads < (3*(float)(M_PI / 2)))
		izquierda = 1;
	
	y_intercept = floor(player->pos_y / (float)map->height) * (float)map->height;
	if(abajo == 1)
		y_intercept += (float)map->height;

	x_intercept = player->pos_x;
	x_intercept += (y_intercept - player->pos_y) / tan(rads);


	step_y = map->height;
	step_x = ((float)((float)map->height) / tan(rads));
	wall_hit_x_horizontal = x_intercept;
	wall_hit_y_horizontal = y_intercept;


	step_x = -step_x;
	if(abajo == 0)
		step_y = -step_y;
	if(abajo == 1)
		step_x = -step_x;
	while(horizontal_hit == 0 && wall_hit_x_horizontal < (float)(map->width * map->columns)
			&& wall_hit_x_horizontal > 1.0 && wall_hit_y_horizontal > 1.0 &&
			wall_hit_y_horizontal < (float)(map->rows * map->height))	
	{
//' 
		if(map->map[(int)wall_hit_y_horizontal / map->height][(int)wall_hit_x_horizontal / map->width] == '1' || (abajo == 0 && map->map[(int)(wall_hit_y_horizontal - 1) / map->height][((int)wall_hit_x_horizontal) / map->width] == '1'))
			horizontal_hit = 1;
		else
		{
			wall_hit_x_horizontal += step_x;
			wall_hit_y_horizontal += step_y;
		}
	}
	//Aqui acaba la parte horizontal
	x_intercept = floor(player->pos_x / (float)map->width) * (float)map->width;
	if(izquierda == 0)
		x_intercept += map->width;

	y_intercept = player->pos_y;
	y_intercept += ((float)(x_intercept - player->pos_x) * tan(rads));
	step_x = (float)map->width;
	step_y = ((float)((float)map->height) * tan(rads));
	wall_hit_y_vertical = y_intercept;
	wall_hit_x_vertical = x_intercept;
	
	step_y = -step_y;
	if(izquierda == 1)
		step_x = -step_x;
	if(izquierda == 0)
		step_y = -step_y;
	vertical_hit = 0;	
	while(vertical_hit  == 0 && wall_hit_x_vertical < (float)(map->width * map->columns)
			&& wall_hit_x_vertical > 1.0 && wall_hit_y_vertical > 1.0 &&
			wall_hit_y_vertical < (float)(map->rows * map->height))	
	{
		if(map->map[(int)wall_hit_y_vertical / map->height][(int)wall_hit_x_vertical / map->width] == '1' 
			|| (izquierda == 1 && map->map[((int)wall_hit_y_vertical) / map->height][(int)(wall_hit_x_vertical - 1) / map->width] == '1'))
			vertical_hit = 1;
		else
		{
			wall_hit_x_vertical += step_x;
			wall_hit_y_vertical += step_y;
		}
	}
	
	float horizontal_distance = distancia(player->pos_x, player->pos_y, wall_hit_x_horizontal, wall_hit_y_horizontal);
	float vertical_distance = distancia(player->pos_x, player->pos_y, wall_hit_x_vertical, wall_hit_y_vertical);
	if(horizontal_distance <= vertical_distance)
	{
		insert_point_f(p_ext, wall_hit_x_horizontal, wall_hit_y_horizontal);
		if(abajo == 1)
		{
			*texture = map->NO;
			*x_texture = (1 - ((int)wall_hit_x_horizontal % map->width) / (float) map->width) * ((*texture)->width );
		}
		else
		{
			*texture = map->SO;
			*x_texture = (((int)wall_hit_x_horizontal % map->width) / (float) map->width) * ((*texture)->width );
		}
		if (*x_texture >=  (int)map->WE->width)
			(*x_texture)--;
		return horizontal_distance;
	}
	else
	{
		insert_point_f(p_ext, wall_hit_x_vertical, wall_hit_y_vertical);
		if(izquierda == 1)
		{
			*texture = map->EA;
			*x_texture = (1 - ((int)wall_hit_y_vertical % map->height) / (float) map->height) * ((*texture)->height);
		}
		else
		{
			*texture = map->WE;
			*x_texture = (((int)wall_hit_y_vertical % map->height) / (float) map->height) * ((*texture)->height);
		}
		if (*x_texture >=  (int)map->WE->width)
			(*x_texture)--;
		return vertical_distance;
	}	
}

//Function to calculate distance between 2 points
float distancia(float p0x, float p0y, float p1x, float p1y)
{
	float distance_x = pow(p0x - p1x, 2);
	float distance_y = pow(p0y - p1y, 2);
	float distance = sqrt(distance_x + distance_y);


	return distance;
}
