/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MouseHook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:14:38 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 21:31:33 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/game/Game.h"

void cursorhook(double xpos, double ypos, void *param)
{
	(void)ypos;

	t_game *game = (t_game *)param;
	if(xpos < (float)((game->player->screen_x / 2) - (game->player->screen_x / 4)))
		rotate(game->player, -1);
	if(xpos > (float)((game->player->screen_x / 2) + (game->player->screen_x / 4)))
		rotate(game->player, 1);

}
