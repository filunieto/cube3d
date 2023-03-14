/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:31:36 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

void	paint(t_game *game)
{
	clear_image(game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);
}
