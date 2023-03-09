/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:00 by anramire          #+#    #+#             */
/*   Updated: 2023/03/09 23:14:03 by anramire         ###   ########.fr       */
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

typedef struct s_map
{
	unsigned int semi_len;
	unsigned int rows;
	unsigned int columns;
	unsigned int width;
	unsigned int height;
	mlx_image_t *img;
	char **map;
}t_map;

//Functions aux temporarily!!!!!!!!
//To init map player must have been initialized previously
void init_map(t_map *map, t_player *player);
void free_map(t_map *map);

//Function to show map
void show_map(t_map *map);

//Function to draw map
void	draw_map(t_map *map, t_player *player);

//Function to move player in the direction of direction vector
void player_advance(t_map *map, t_player *player, int direction);
#endif
