/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:00 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 22:43:58 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_H
# define MAP_H

# include "../../memory-leaks/include/memory_leaks.h"
# include "../../libft/libft.h"
# include "../player/Player.h"
# include "../shapes/Shapes.h"

#include <stdlib.h>
#include <string.h>

# define COLOR_WALLS 0x9C0000FF
# define COLOR_FREE_SPACES 0x490080FF
typedef struct s_map
{
	unsigned int semi_len;
	unsigned int rows;
	unsigned int columns;
	unsigned int width;
	unsigned int height;
	mlx_image_t *img;
	char **map;
	mlx_texture_t *NO;
	mlx_texture_t *SO;
	mlx_texture_t *EA;
	mlx_texture_t *WE;
	int ceil_color;
	int floor_color;
}t_map;

//Functions aux temporarily!!!!!!!!
//To init map player must have been initialized previously
void init_map(t_map *map, t_player *player);
void free_map(t_map *map);

//Function to check the color of a position
void	check_color(char c, int *color);
void	check_outside_colors(t_map *map, t_player *player, int *color, int *aux);
//Function to show map
void show_map(t_map *map);

//Function to draw map
void	draw_map(t_map *map, t_player *player);

//Function to draw the upper part of the column
void	draw_column_up(t_map *map, t_player *player, t_line *line, int *aux);

//Function to draw the down part of the column
void	draw_column_down(t_map *map, t_player *player, t_line *line, int *aux);

//Function to move player in the direction of direction vector
void player_advance(t_map *map, t_player *player, int direction);

//Function to advance to the sides with 'A' or 'D', left == 1 goes to left
//left == -1 goes to right
void	player_advance_lateral(t_map *map, t_player *player, int left);

//Function to check collisions
void	check_collision(t_map *map, t_player *player,
			float advance_x, float advance_y);


#endif
