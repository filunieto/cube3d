/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:55:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/01 21:44:47 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Screen.h"

int	init_window(void)
{	
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_4vertex *sq;

	sq = (t_4vertex *)malloc(sizeof(t_4vertex));

	mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "Cub3D", true);
	if (!mlx)
	{
		printf("Error initializing window!!!\n");
		return (-1);
	}
	img = mlx_new_image(mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	t_player player;
	init_player(img, &player);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(sq);
	return (0);
}
