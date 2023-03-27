/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/27 20:33:38 by anramire         ###   ########.fr       */
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
		proyected_height = player->screen_y - 1;

	if(proyected_height > (player->screen_y - 1))
		proyected_height = player->screen_y - 1;
	y0 = half_screen - (int)(proyected_height / 2);	
	y1 = half_screen + (int)(proyected_height / 2);
	printf("y0: %d, y1: %d\n", y0, y1);	
	for(; y0 <y1; y0++)
	{
		mlx_put_pixel(player->img, x, y0, 0x00FF00FF);
	}

}
