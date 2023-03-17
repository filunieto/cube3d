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

//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{
	clear_image(game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);
	t_point p_extremo;
	if(game->player->angle != 360 && game->player->angle != 0)
	{
		cast(game->map, game->player, (float)game->player->angle, &p_extremo);
		draw_line(game->player->img, game->player->center_point, &p_extremo, 0xFF00FFFF);
	}
}

void	cast(t_map *map, t_player *player, float angle, t_point *p_ext)
{
	(void)p_ext;
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

	horizontal_hit = 0;
	izquierda = 0;
	abajo = 0;
	if(rads < (float)(M_PI) && rads > (float)0)
		abajo = 1;

	if(rads > (float)(M_PI / 2) && rads < (3*(float)(M_PI / 2)))
		izquierda = 1;
	(void)izquierda;	
	y_intercept = (int)floor(player->pos_y / map->height) * map->height;
	if(abajo == 1)
		y_intercept += map->height;

	x_intercept = (int)player->pos_x;
	x_intercept += (int)((double)(y_intercept - (int)player->pos_y) / tan(rads));


	step_y = map->height;
	step_x = (int)((double)((int)map->height) / tan(rads));
	wall_hit_x_horizontal = x_intercept;
	wall_hit_y_horizontal = y_intercept;
	printf("y_intercept: %d\n", y_intercept);	
	printf("x_intercept: %d\n", x_intercept);


	step_y = -step_y;
	step_x = -step_x;
	if(abajo == 0)
	{
		wall_hit_y_horizontal--;
	}

	printf("step_x: %d\n", step_x);
	printf("step_y: %d\n", step_y);
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
	printf("wall_hit_x_horizontal: %d\n", wall_hit_x_horizontal);
	printf("wall_hit_y_horizontal: %d\n", wall_hit_y_horizontal);
	insert_point(p_ext, player->center_point->x + wall_hit_x_horizontal - player->pos_x,
			player->center_point->y + wall_hit_y_horizontal - player->pos_y);

}
