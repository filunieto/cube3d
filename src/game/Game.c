/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:16:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/20 21:32:19 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

extern void	resize_func(int x, int y, void *param);
extern void	key_func(mlx_key_data_t keydata, void *param);

void	init_game(mlx_t *mlx, mlx_image_t *img, t_game *game)
{
	game->mlx = mlx;
	game->player = (t_player *) malloc (sizeof(t_player));
	game->map = (t_map *) malloc (sizeof(t_map));
	init_player(mlx, img, game->player);
	init_map(game->map, game->player);
	show_map(game->map);
	draw_map(game->map, game->player);
	paint_player(game->player);
	mlx_resize_hook(game->mlx, resize_func, game);
	mlx_key_hook(game->mlx, &key_func, game);
}

void	free_game(t_game *game)
{
	free_player(game->player);
	free(game->player);
	free_map(game->map);
	free(game->map);
}
