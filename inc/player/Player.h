/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:51:40 by anramire          #+#    #+#             */
/*   Updated: 2023/03/07 19:30:35 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define WIDTH 1920
# define HEIGHT 1080
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../memory-leaks/include/memory_leaks.h"
# include "../shapes/Shapes.h"

typedef struct s_player{
	mlx_t *mlx;
	mlx_image_t *img;
	unsigned int tam;
	t_point *center_point;
	unsigned int length_direction;
	t_point *direction;
	t_point *absolute_direction;
	int color;

}t_player;

//Functions to init player a define a position
void 	init_player(mlx_t *mlx, mlx_image_t *img, t_player *player);
void	pos_player(t_player *player);

//Function to free memoroy in player structure
void free_player(t_player *player);

//Function to paint a repaint player
void paint_player(t_player *player);

void update_direction(t_player *player);
#endif
