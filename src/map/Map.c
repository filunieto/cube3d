/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:11 by anramire          #+#    #+#             */
/*   Updated: 2023/03/08 19:04:33 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/map/Map.h"

void init_map(t_map *map)
{
	unsigned int rows = 14;
	unsigned int i = 0;

	char *map_aux[] = {
			"        1111111111111111111111111",
			"        1000000000110000000000001",
			"        1011000001110000000000001",
			"        1001000000000000000000001",
			"111111111011000001110000000000001",
			"100000000011000001110111111111111",
			"11110111111111011100000010001    ",
			"11110111111111011101010010001    ",
			"11000000110101011100000010001    ",
			"10000000000000001100000010001    ",
			"10000000000000001101010010001    ",
			"11000001110101011111011110N0111  ",
			"11110111 1110101 101111010001    ",
			"11111111 1111111 111111111111    "
	};
	map->rows = rows;
	map->map = (char **) malloc(rows * sizeof(char *));
	
	while(i < 14)
	{
		
		map->map[i] = ft_strdup(map_aux[i]); //we use this strdup!!!!!!!!!!!!,
										  //instead ft_strdup should be used
		i++;	
	}

}

