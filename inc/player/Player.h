/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:51:40 by anramire          #+#    #+#             */
/*   Updated: 2023/03/01 21:51:44 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define WIDTH 1920
# define HEIGHT 1080
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../shapes/Shapes.h"

typedef struct s_player{
	mlx_image_t *img;
	unsigned int tam;
	int screen_x;
	int screen_y;
	int color;

}t_player;

//Functions to init player a define a position
void 	init_player(mlx_image_t *img, t_player *player);
void	pos_player(t_player *player);

#endif
