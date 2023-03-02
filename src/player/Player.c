/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:52:35 by anramire          #+#    #+#             */
/*   Updated: 2023/03/01 21:52:38 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/player/Player.h"

void	pos_player(t_player *player)
{
	t_point pos;

	insert_point(&pos, player->screen_x / 2, player->screen_y / 2);
	draw_square_pos(player->img, &pos, player->tam, player->color);
}

void	init_player(mlx_image_t *img, t_player *player)
{
	player->img = img;
	player->tam = 10;
	player->screen_x = WIDTH;
	player->screen_y = HEIGHT;
	player->color = 0xE0E0E0FF;
	pos_player(player);
}
