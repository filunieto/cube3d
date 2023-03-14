/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Advance_and_Back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:23:02 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:25:23 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void	key_advance_and_back(t_game *game, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		player_advance(game->map, game->player, 1);
		paint(game);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		player_advance(game->map, game->player, -1);
		paint(game);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		player_advance(game->map, game->player, 1);
		paint(game);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		player_advance(game->map, game->player, -1);
		paint(game);
	}
}
