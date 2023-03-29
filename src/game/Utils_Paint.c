/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_Paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:13:30 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 21:37:43 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

static void	draw_vertical_line(unsigned int x, float distancia_colision,
				t_player *player, t_texture *texture);
static void	set_variables_draw_vertical_line(t_player *player,
				t_draw_vertical *param, float distancia_colision,
				t_texture *texture);

void	loop_casting(t_game *game, float init_angle,
		float increment_angle, t_texture *texture)
{
	t_point_f		p_extremo;
	float			aux;
	unsigned int	i;

	i = 0;
	while (i < game->player->screen_x)
	{
		aux = game->player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rads(aux);
		aux = cos(aux) * cast(game, init_angle, &p_extremo, texture);
		draw_vertical_line(i, aux, game->player, texture);
		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
		i++;
	}
}

static void	draw_vertical_line(unsigned int x, float distancia_colision,
		t_player *player, t_texture *txt)
{
	t_draw_vertical	params;
	int				color;

	set_variables_draw_vertical_line(player, &params,
		distancia_colision, txt);
	while (params.y0 < params.y1)
	{
		color = txt->texture->pixels[(txt->x_texture
				+ (((int)params.acc) * txt->texture->width))
			* txt->texture->bytes_per_pixel] << 24;
		color |= txt->texture->pixels[(txt->x_texture
				+ (((int)params.acc) * txt->texture->width))
			* txt->texture->bytes_per_pixel + 1] << 16;
		color |= txt->texture->pixels[(txt->x_texture
				+ (((int)params.acc) * txt->texture->width))
			* txt->texture->bytes_per_pixel + 2] << 8;
		color |= txt->texture->pixels[(txt->x_texture
				+ (((int)params.acc) * txt->texture->width))
			* txt->texture->bytes_per_pixel + 3];
		if (params.y0 > 0 && params.y0 <= (int)(player->screen_y - 1))
			mlx_put_pixel(player->img, x, params.y0, color);
		if ((float)(params.acc + params.ratio) < (float)txt->texture->height)
			params.acc += params.ratio;
		params.y0++;
	}
}

static void	set_variables_draw_vertical_line(t_player *player,
		t_draw_vertical *param, float distancia_colision, t_texture *texture)
{
	float	proyected_height;
	int		half_screen;

	half_screen = player->screen_y / 2;
	param->acc = 0;
	if (distancia_colision > 0)
		proyected_height = 20000 / distancia_colision;
	else
		proyected_height = player->screen_y - 1;
	param->ratio = (float)texture->texture->height / proyected_height;
	param->y0 = half_screen - (int)(proyected_height / 2);
	if (y0 < 0)
	{
		param->acc = (-(param->y0) + 1) * param->ratio;
		param->y0 = 0;
	}
	param->y1 = half_screen + (int)(proyected_height / 2);
	if (param->y1 > (int)(player->screen_y - 1))
		param->y1 = player->screen_y - 1;
}
