/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 22:08:29 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void	casting(t_map *map, t_player *player);


static void draw_vertical_line(unsigned int x, float distancia_colision, t_player *player, t_map *map, int x_texture, mlx_texture_t *texture);

static void draw_ceil_and_floor(t_map *map, t_player *player);
//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{

	clear_image(game->player);
	
	//draw ceil and floor
	draw_ceil_and_floor(game->map, game->player);
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
	int x_texture;
	mlx_texture_t *texture;
	half_fov = player->fov / 2;
	distancia_proyec = ((float)player->screen_x / 2) / tan (grades_to_rads(half_fov));
	
	increment_angle = player->fov / (float)player->screen_x;
	init_angle = (float)player->angle - half_fov;
	init_angle = normalize_angle(init_angle);
	cast(map, player, (float)player->angle, &p_extremo, &x_texture, &texture);
	adjust_line(map, player, &p_extremo, &p_final);
	draw_line(player->img, player->center_point, &p_final, 0xFF00FFFF);
	

	for(unsigned int i = 0; i < player->screen_x; i++)
	{
		distancia_colision = cast(map, player, init_angle, &p_extremo, &x_texture, &texture);	

		aux = player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rads(aux);
		aux = distancia_colision * cos(aux);
		draw_vertical_line(i, aux, player, map, x_texture, texture);

		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
	}
}

void draw_vertical_line(unsigned int x, float distancia_colision, t_player *player, t_map *map, int x_texture, mlx_texture_t *texture)
{
	float proyected_height;
	int half_screen = player->screen_y / 2;
	int y0;
	int y1;
	float ratio; //pixel_pantalla / pixel_textura
	float acc;
	(void)map;

	acc = 0;
	if(distancia_colision > 0)
		proyected_height = 20000/ distancia_colision;
	else
		proyected_height = player->screen_y - 1;
		// if(proyected_height > (player->screen_y - 1))
		// 	acc = proyected_height * texture->height / player->screen_x - 1 ;
	ratio = (float)texture->height / proyected_height;
	//printf("proyected_height: %f, ratio: %f\n", proyected_height, ratio);
	y0 = half_screen - (int)(proyected_height / 2);
	if (y0 < 0)
	{
		acc = (-y0 + 1) * ratio;
		y0 = 0;
	}
	y1 = half_screen + (int)(proyected_height / 2);
	if(y1 > (int)(player->screen_y - 1))
		y1 = player->screen_y - 1;
	//int pos = 30;
	//uint8_t *color;
	int color;
	int color_def;
	for(; y0 <y1; y0++)
	{
		(void) x_texture;
		color = texture->pixels[(x_texture + (((int)acc) * texture->width)) *  texture->bytes_per_pixel]<< 24;
		color |= texture->pixels[(x_texture + (((int)acc) * texture->width)) *  texture->bytes_per_pixel + 1] << 16;
		color |= texture->pixels[(x_texture + (((int)acc) * texture->width)) *  texture->bytes_per_pixel + 2] << 8;
		color |= texture->pixels[(x_texture + (((int)acc) * texture->width)) *  texture->bytes_per_pixel + 3];

		//color_def = (color[0] << 24) | (color[1] << 16) | (color[2] << 8) | color[3];
		//color_def = color>>24 | color<<24 | (((color << 8) >> 24) << 8) | (((color >> 8) << 24) >> 8) ;
		color_def = color;
		if(y0 > 0 && y0 <= (int)(player->screen_y - 1))
			mlx_put_pixel(player->img, x, y0, color_def);
		if((float)(acc + ratio) < (float)texture->height)
			acc += ratio;

	}
		//printf("pixel: %f\n", acc);

}

static void draw_ceil_and_floor(t_map *map, t_player *player)
{
	(void)map;	
	t_4vertex ceil;
	t_4vertex floor;
	
	//ceil
	insert_point(&(ceil.p0), 1, 1);
	insert_point(&(ceil.p1), player->screen_x - 1, 1);
	insert_point(&(ceil.p2), player->screen_x - 1, player->screen_y / 2);
	insert_point(&(ceil.p3), 1, player->screen_y / 2);
	
	//floor
	insert_point(&(floor.p0), 1, player->screen_y / 2);
	insert_point(&(floor.p1), player->screen_x - 1, player->screen_y / 2);
	insert_point(&(floor.p2), player->screen_x - 1, player->screen_y - 1);
	insert_point(&(floor.p3), 1 , player->screen_y - 1);
	draw_square_filled(player->img, &ceil, map->ceil_color, 1);
	draw_square_filled(player->img, &floor, map->floor_color, 1);

}
