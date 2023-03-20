/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/16 23:18:27 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

float distancia(t_point *p1, t_point *p2);

//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{
	clear_image(game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);
	t_point p_extremo;
		cast(game->map, game->player, (float)game->player->angle, &p_extremo);
	/*
		if((game->player->center_point->y - p_extremo.y) > 200){
			int delta_x = (int)(-200 / (float)tan((float)game->player->angle * M_PI / 180));
			insert_point(&p_extremo, game->player->center_point->x + delta_x, game->player->center_point->y - 200);
		}
		else if((int)(game->player->center_point->y - p_extremo.y) < -200)
		{
			
			int delta_x = (int)(200 / (float)tan((float)game->player->angle * M_PI / 180));
			insert_point(&p_extremo, game->player->center_point->x + delta_x, game->player->center_point->y - 200);
		}
		*/
		draw_line(game->player->img, game->player->center_point, &p_extremo, 0xFF00FFFF);
}

void	cast(t_map *map, t_player *player, float angle, t_point *p_ext)
{
	int izquierda;// 0 -> derecha, 1 -> izquierda
	int abajo;// 0 -> arriba, 1 -> abajo
	float rads = grades_to_rads(angle);
	int y_intercept;
	int x_intercept;
	int step_y;
	int step_x;
	int wall_hit_x_horizontal;
	int wall_hit_y_horizontal;
	int horizontal_hit;
	int wall_hit_x_vertical;
	int wall_hit_y_vertical;
	int vertical_hit;
	printf("Angle: %f\n", angle);
	horizontal_hit = 0;
	izquierda = 0;
	abajo = 0;
	if(rads < (float)(M_PI) && rads > (float)0)
		abajo = 1;

	if(rads > (float)(M_PI / 2) && rads < (3*(float)(M_PI / 2)))
		izquierda = 1;
	
	y_intercept = (int)floor(player->pos_y / map->height) * map->height;
	if(abajo == 1)
		y_intercept += map->height;

	x_intercept = (int)player->pos_x;
	x_intercept += (int)((double)(y_intercept - (int)player->pos_y) / tan(rads));


	step_y = map->height;
	step_x = (int)((double)((int)map->height) / tan(rads));
	wall_hit_x_horizontal = x_intercept;
	wall_hit_y_horizontal = y_intercept;


	step_x = -step_x;
	if(abajo == 0)
	{

		step_y = -step_y;
		wall_hit_y_horizontal--;
	}
	if(abajo == 1)
	{
		step_x = -step_x;
	}

	while(horizontal_hit == 0 && wall_hit_x_horizontal < (int)(map->width * map->columns)
			&& wall_hit_x_horizontal >= 0 && wall_hit_y_horizontal >= 0 &&
			wall_hit_y_horizontal < (int)(map->rows * map->height))	
	{

		if(map->map[wall_hit_y_horizontal / map->height][wall_hit_x_horizontal / map->width] == '1')
			horizontal_hit = 1;
		else
		{
			wall_hit_x_horizontal += step_x;
			wall_hit_y_horizontal += step_y;
		}
	}
	//Aqui acaba la parte horizontal
	x_intercept = floor(player->pos_x / map->width) * map->width;
	if(izquierda == 0)
		x_intercept += map->width;

	y_intercept = (int)player->pos_y;
	y_intercept += (int)((double)(x_intercept - (int)player->pos_x) * tan(rads));
	step_x = map->width;
	step_y = (int)((double)((int)map->height) * tan(rads));
	wall_hit_y_vertical = y_intercept;
	wall_hit_x_vertical = x_intercept;
	if(izquierda == 1)
	{
		step_x = -step_x;

		wall_hit_x_vertical--;
	}
	
	vertical_hit = 0;	
	while(vertical_hit  == 0 && wall_hit_x_vertical < (int)(map->width * map->columns)
			&& wall_hit_x_vertical >= 0 && wall_hit_y_vertical >= 0 &&
			wall_hit_y_vertical < (int)(map->rows * map->height))	
	{

		if(map->map[wall_hit_y_vertical / map->height][wall_hit_x_vertical / map->width] == '1')
			vertical_hit = 1;
		else
		{
			printf("wall_hit_x_vertical: %d\n", wall_hit_x_vertical);
			printf("wall_hit_y_vertical: %d\n", wall_hit_y_vertical);
			wall_hit_x_vertical += step_x;
			wall_hit_y_vertical += step_y;
		}
	}
	
			printf("wall_hit_x_vertical: %d\n", wall_hit_x_vertical);
			printf("wall_hit_y_vertical: %d\n", wall_hit_y_vertical);
	t_point aux;
	t_point horizontal;
	t_point vertical;
	insert_point(&aux, player->pos_x, player->pos_y);
	insert_point(&horizontal,wall_hit_x_horizontal, wall_hit_y_horizontal);
	insert_point(&vertical, wall_hit_x_vertical, wall_hit_y_vertical);
	if(distancia(&aux, &horizontal) <= distancia(&aux, &vertical))
	{
		printf("Horizontal\n");
	insert_point(p_ext, player->center_point->x + wall_hit_x_horizontal - player->pos_x,
			player->center_point->y + wall_hit_y_horizontal - player->pos_y);
	}
	else
	{
		printf("Vertical\n");
		insert_point(p_ext, player->center_point->x + wall_hit_x_vertical - player->pos_x,
			player->center_point->y + wall_hit_y_vertical - player->pos_y);
	}	
	printf("Final function\n");
}

float distancia(t_point *p1, t_point *p2)
{
	double distance_x = pow(p1->x - p2->x, 2);
	double distance_y = pow(p1->y - p2->y, 2);
	double root = sqrt(distance_x + distance_y);

	float res = (float)root;
	return res;
}
