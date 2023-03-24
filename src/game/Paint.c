/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/24 21:35:06 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

#define PI 3.1415926535
void	casting(t_map *map, t_player *player);

void drawRays3D(t_map *map, t_player *player);

void draw_vertical_line(unsigned int x, float distancia_proyec, float distancia_colision, t_player *player);
//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{

	clear_image(game->player);
	
	casting(game->map, game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);


}

void	casting(t_map *map, t_player *player)
{
	t_point_f p_extremo;
	t_point p_final;
	float increment_angle;
	float half_fov;
	float init_angle;
	float distancia_proyec;
	float distancia_colision;
	float aux;

	half_fov = player->fov / 2;
	distancia_proyec = ((float)player->screen_x / 2) / tan (grades_to_rads(half_fov));
	
	increment_angle = player->fov / (float)player->screen_x;
	init_angle = (float)player->angle - half_fov;
	init_angle = normalize_angle(init_angle);
	cast(map, player, (float)player->angle, &p_extremo);
	adjust_line(map, player, &p_extremo, &p_final);
	draw_line(player->img, player->center_point, &p_final, 0xFF00FFFF);
	

	for(unsigned int i = 0; i < player->screen_x; i++)
	{
		distancia_colision = cast(map, player, init_angle, &p_extremo);	

		aux = player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rads(aux);
		aux = distancia_colision * cos(aux);
		draw_vertical_line(i, distancia_proyec, aux, player);


		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
	}
}

void draw_vertical_line(unsigned int x, float distancia_proyec, float distancia_colision, t_player *player)
{
	float proyected_height;
	int half_screen = player->screen_y / 2;
	int y0;
	int y1;
	(void)distancia_proyec;
	if(distancia_colision > 0)
		proyected_height = 15000/ distancia_colision;
	else
		proyected_height = 1079;

	if(proyected_height > 1079)
		proyected_height = 1079;
	y0 = half_screen - (int)(proyected_height / 2);	
	y1 = half_screen + (int)(proyected_height / 2);
	printf("y0: %d, y1: %d\n", y0, y1);	
	for(; y0 <y1; y0++)
	{
		mlx_put_pixel(player->img, x, y0, 0x00FF00FF);
	}

	printf("Sale vertical\n");
}
/*
void drawRays3D(t_map *map, t_player *player)
{
	int r;
	int mx;
	int my;
	int mp;
	int dof;

	float rx;
	float ry;
	float ra;
	float x0;
	float y0;

	char map_aux[] = {
			' ',' ',' ',' ',' ',' ',' ',' ','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1',
			' ',' ',' ',' ',' ',' ',' ',' ','1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1',
			' ',' ',' ',' ',' ',' ',' ',' ','1','0','1','1','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1',
			' ',' ',' ',' ',' ',' ',' ',' ','1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1',
			'1','1','1','1','1','1','1','1','1','0','1','1','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0','0','0','1',
			'1','0','0','0','0','0','0','0', 'N', '0','1','1','0','0','0','0','0','1','1','1','0','1','1','1','1','1','0','1','1','1','1','1','1',
			'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','1',
			'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','0','1','0','0','0','1', 
			'1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','0','0','0','0','0','0','1','1','0','0','1',  
			'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','1','1','0','0','1',   
			'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','0','1','0','1','0','0','1','0','0','0','1',  
			'1','1','0','0','0','0','0','1','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','0','1','0','0','0','1','0','1', 
			'1','1','1','1','0','1','1','1', '1','1','1','0','1','0','1', '1','0','1','1','1','1','0','1','0','0','0','1',   
			'1','1','1','1','1','1','1','1', '1','1','1','1','1','1','1', '1','1','1','1','1','1','1','1','1','1','1','1',    
	};

	ra = (float)player->angle;
	for(r = 0; r < 1; r++)
	{
		//--- Check Horizontal Lines ---
		dof = 0;
		float aTan = -1.0 / (float)tan(ra);
		if(ra >PI)
		{
			ry = (((int)player->pos_y >> 6) << 6) - 0.0001;
			rx = (player->pos_y - ry) * aTan + player->pos_x;
			y0 = - (map->rows * (float)map->width);
			x0 = -y0 * aTan;
		}

		if(ra < PI)
		{
			ry = (((int)player->pos_y >> 6) << 6) + (float)(map->height * map->rows);
			rx = (player->pos_y - ry) * aTan + player->pos_x;
			y0 = (map->rows * map->width);
			x0 = -y0 * aTan;
		}
		if(ra == 0 || ra == PI)
		{
			rx = player->pos_x;
			ry = player->pos_y;
			dof = map->rows;
		}
		printf("x0: %f, y0: %f\n", x0, y0);
		while(dof < (int)map->rows)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			
			mp = (int)(my*(int)map->columns + mx);
			if(mp < (int)(map->columns * map->rows) && map_aux[mp] == '1')
			{
				dof = map->rows;
			}
			else
			{
				rx += x0;
				ry += y0;
				dof += 1;
			}
			printf("rx: %f, ry: %f\n", rx, ry);

		}
		printf("Final bucle\n");
	}

	t_point p_final;
	t_point_f p_extremo;

	insert_point_f(&p_extremo, rx, ry);
	adjust_line(map, player, &p_extremo, &p_final);

	printf("rx: %d, ry: %d\n", p_final.x, p_final.y);
	draw_line(player->img, player->center_point, &p_final, 0xFF00FFFF);
	printf("Final\n");

}*/
