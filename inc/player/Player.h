/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:51:40 by anramire          #+#    #+#             */
/*   Updated: 2023/03/09 19:09:46 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define WIDTH 1920
# define HEIGHT 1080
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../memory-leaks/include/memory_leaks.h"
# include "../shapes/Shapes.h"
# include <math.h>

typedef struct s_player{
	mlx_t *mlx;
	mlx_image_t *img;
	unsigned int tam;
	unsigned int screen_x;
	unsigned int screen_y;
	unsigned int pos_x;
	unsigned int pos_y;
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

//Functions to rotate direction of player
//if clockwise = 1 it goes clockwise, if it is -1 it goes reverse
void	rotate(t_player *player, int clockwise);

//Function to update direction of player
void update_direction(t_player *player);

//Function to clear window
void clear_image(t_player *player);

#endif
