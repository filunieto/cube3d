/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:31:16 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 18:48:15 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/game/Game.h"

//This functiom is constantly executing and it is in charge of repainting
void	paint(t_game *game)
{
	clear_image(game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);
	t_point_f p_extremo;
	t_point p_final;

	cast(game->map, game->player, (float)game->player->angle, &p_extremo);
	adjust_line(game->map, game->player, &p_extremo, &p_final);
	draw_line(game->player->img, game->player->center_point, &p_final, 0xFF00FFFF);

}
