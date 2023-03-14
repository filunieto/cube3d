/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResizeHook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:33:12 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:38:19 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void	resize_func(int x, int y, void *param)
{
	t_game		*game;
	mlx_image_t	*img;

	game = (t_game *)param;
	game->player->screen_x = x;
	game->player->screen_y = y;
	img = game->player->img;
	game->player->img = mlx_new_image(game->player->mlx, x, y);
	mlx_delete_image(game->player->mlx, img);
	insert_point(game->player->center_point, x / 2, y / 2);
	mlx_image_to_window(game->player->mlx, game->player->img, 0, 0);
	update_direction(game->player);
	paint(game);
}
