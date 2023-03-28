/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:58:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 19:48:46 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player/Player.h"

void	init_direction(t_player *player)
{
	player->angle = 270;
	player->length_direction = 50;
	player->absolute_direction = (t_point *) malloc(sizeof(t_point));
	player->direction_x = 0.0;
	player->direction_y = (float)(-1 * (int)player->length_direction);
	update_direction(player);
}

void	update_direction(t_player *player)
{	
	insert_point(player->absolute_direction,
		(float)player->center_point->x + player->direction_x,
		(float)player->center_point->y + player->direction_y);
}

//Anti-Clockwise = -1, Clockwise = 1
void	rotate(t_player *player, int clockwise)
{
	double	angle;

	if (clockwise == 1)
		player->angle += ANGLE_ROTATE;
	else if (clockwise == -1)
		player->angle -= ANGLE_ROTATE;
	if (player->angle < 0)
		player->angle = 360 + player->angle;
	else if (player->angle > 360)
		player->angle = player->angle % 360;
	angle = ((double)player->angle * M_PI) / 180;
	if (clockwise == -1 || clockwise == 1)
	{
		player->direction_x = (float)player->length_direction * cos(angle);
		player->direction_y = (float)player->length_direction * sin(angle);
		update_direction(player);
	}
}
