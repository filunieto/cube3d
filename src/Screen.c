/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:55:43 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 12:37:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Screen.h"

int	init_window(t_pars *parsing_str)
{	
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_game		game;

	mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "Cub3D", true);
	mlx_set_window_limit(mlx, MIN_WIDTH, MIN_HEIGHT,
		INITIAL_WIDTH, INITIAL_HEIGHT);
	if (!mlx)
	{
		printf("Error initializing window!!!\n");
		return (-1);
	}
	img = mlx_new_image(mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	init_game(mlx, img, &game, parsing_str);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_game(&game);
	return (0);
}
