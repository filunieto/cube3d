/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:52:35 by anramire          #+#    #+#             */
/*   Updated: 2023/03/24 19:03:26 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player/Player.h"

extern void	init_direction(t_player *player);
void		paint_player(t_player *player);

void	pos_player(t_player *player)
{
	draw_square_pos(player->img, player->center_point,
		player->tam, player->color);
}

void	init_player(mlx_t *mlx, mlx_image_t *img, t_player *player)
{
	player->mlx = mlx;
	player->img = img;
	player->tam = 10;
	player->screen_x = WIDTH;
	player->screen_y = HEIGHT;
	player->center_point = (t_point *) malloc (sizeof(t_point));
	insert_point(player->center_point, WIDTH - MARGINS, MARGINS);
	init_direction(player);
	player->color = 0xE0E0E0FF;
	player->vel = 2;
	player->fov = (float)FOV;
	paint_player(player);
}

void	free_player(t_player *player)
{
	free(player->center_point);
	free(player->absolute_direction);
}

void	paint_player(t_player *player)
{
	pos_player(player);
	draw_line(player->img, player->center_point, player->absolute_direction,
		0x00FF00FF);
}
