/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClearingImage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:57:31 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 21:41:17 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/player/Player.h"

void	clear_image(t_player *player)
{

	unsigned int x;
	unsigned int y;

	y = 0;
	while(y < player->screen_y)
	{
		x = 0;
		while(x < player->screen_x)
		{
			mlx_put_pixel(player->img, x, y, 0x4a4747FF);
			x++;
		}
		y++;
	}
}

/*
 	mlx_delete_image(player->mlx, player->img);
	player->img = mlx_new_image(player->mlx, player->screen_x,
			player->screen_y);
	mlx_image_to_window(player->mlx, player->img, 0, 0);
*/
/*unsigned int x;
unsigned int y;

y = 0;
while(y < player->screen_y)
{
	x = 0;
	while(x < player->screen_x)
	{
		mlx_put_pixel(player->img, x, y, 0x4a4747FF);
		x++;
	}
	y++;
}*/
