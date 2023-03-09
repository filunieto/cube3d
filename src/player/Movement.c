/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:45:13 by anramire          #+#    #+#             */
/*   Updated: 2023/03/09 22:19:42 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player/Player.h"

void player_advance(t_player *player, int direction)
{
	float angle;
	float advance_x;
	float advance_y;
	printf("Angle: %d\n", player->angle);
	angle = (player->angle * M_PI) / 180;
	if(direction == -1 || direction == 1)
	{
		advance_x = (float)direction * player->vel * cos(angle);
		advance_y = (float)direction * player->vel * sin(angle);
		printf("Advance_x: %f\nAdvance_y: %f\n", advance_x , advance_y);	
		player->pos_x += round((double)advance_x);
		player->pos_y += round((double)advance_y);
	}
}
