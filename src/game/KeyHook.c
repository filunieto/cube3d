/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyHook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:18:24 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:30:55 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

//Aux methods
extern void	key_advance_and_back(t_game *game, mlx_key_data_t keydata);
extern void	key_turn(t_game *game, mlx_key_data_t keydata);

void	key_func(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	key_advance_and_back(game, keydata);
	key_turn(game, keydata);
}
