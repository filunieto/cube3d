/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Turn_Right_and_Left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:27:25 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:31:55 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void	key_turn(t_game *game, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		rotate(game->player, -1);
		paint(game);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		rotate(game->player, 1);
		paint(game);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		rotate(game->player, -1);
		paint(game);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		rotate(game->player, 1);
		paint(game);
	}
}
