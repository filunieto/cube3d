/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:16:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 23:08:02 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

extern void	resize_func(int x, int y, void *param);
extern void	key_func(mlx_key_data_t keydata, void *param);
extern void	cursorhook(double xpos, double ypos, void *param);

void	init_game(mlx_t *mlx, mlx_image_t *img, t_game *game)
{
	game->mlx = mlx;
	game->player = (t_player *) malloc (sizeof(t_player));
	game->map = (t_map *) malloc (sizeof(t_map));
	init_player(mlx, img, game->player);
	init_map(game->map, game->player);
	paint(game);
	mlx_loop_hook(mlx, key_advance_and_back_aux, game);
	mlx_resize_hook(game->mlx, resize_func, game);
	mlx_cursor_hook(mlx, cursorhook, game);
}

void	free_game(t_game *game)
{
	free_player(game->player);
	free(game->player);
	free_map(game->map);
	free(game->map);
}
