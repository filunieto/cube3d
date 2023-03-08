/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:00 by anramire          #+#    #+#             */
/*   Updated: 2023/03/08 19:38:39 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_H
# define MAP_H

# include "../../memory-leaks/include/memory_leaks.h"
# include "../../libft/libft.h"
# include "../player/Player.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_map
{
	unsigned int rows;
	unsigned int width;
	unsigned int height;
	char **map;
}t_map;

//Functions aux temporarily!!!!!!!!

void init_map(t_map *map, t_player *player);
void free_map(t_map *map);

//Function to show map
void show_map(t_map *map);
#endif
