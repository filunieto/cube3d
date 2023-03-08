/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:11 by anramire          #+#    #+#             */
/*   Updated: 2023/03/08 21:11:12 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/map/Map.h"

void init_map(t_map *map, t_player *player)
{
	unsigned int rows = 14;
	unsigned int i = 0;
	unsigned int j;

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
	map->img = mlx_new_image(player->mlx, player->screen_x, player->screen_y);
	mlx_image_to_window(player->mlx, map->img, 0, 0);
	map->width = 60;
	map->height = 60;
	map->rows = rows;
	map->columns = ft_strlen(map_aux[i]);
	map->map = (char **) malloc(rows * sizeof(char *));
	
	while(i < 14)
	{
		
		map->map[i] = ft_strdup(map_aux[i]); //we use this strdup!!!!!!!!!!!!,
										  //instead ft_strdup should be used
		j = 0;
		while(map_aux[i][j] != '\0')
		{
			if(map_aux[i][j] == 'N' || map_aux[i][j] == 'S' 
					|| map_aux[i][j] == 'E' || map_aux[i][j] == 'W')
			{
				player->pos_x = (j * map->width) + (map->width / 2) ;
				player->pos_y = (i * map->height) + (map->height /  2);
				break;
			}
			j++;
		}
		i++;	
	}

}


void draw_map(t_map *map, t_player *player)
{
	unsigned int y = player->pos_y % map->height;
	unsigned int x = player->pos_x % map->width;
	t_4vertex sq;	
	insert_point(&(sq.p0), player->center_point->x - x, player->center_point->y - y);
	insert_point(&(sq.p1), sq.p0.x + map->width, sq.p0.y);
	insert_point(&(sq.p2), sq.p0.x + map->width, sq.p0.y + map->height);
	insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);
	draw_square_filled(map->img, &sq, 0x0000FFFF, 1);
}

