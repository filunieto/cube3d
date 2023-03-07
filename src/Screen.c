/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:55:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/07 21:48:30 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Screen.h"

int	init_window(void)
{	
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "Cub3D", true);
	if (!mlx)
	{
		printf("Error initializing window!!!\n");
		return (-1);
	}
	img = mlx_new_image(mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	t_game game;
	t_map map;
	init_map(&map);
	show_map(&map);
	init_game(mlx, img, &game);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (0);
}
