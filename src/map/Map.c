/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:11 by anramire          #+#    #+#             */
/*   Updated: 2023/03/11 16:07:54 by fnieves-         ###   ########.fr       */
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
			"10000000000000001100000011001    ",
			"10000000000000001101010010001    ",
			"11000001110101011111011010N0101  ",
			"11110111 1110101 101111010001    ",
			"11111111 1111111 111111111111    "
	};
	map->semi_len = 200;
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
	unsigned rest;
	unsigned int aux;
	int color = 0x0000FFFF;
	char c;
	t_4vertex sq;	
	t_4vertex sq1;

	rest = (map->semi_len - x) % map->width;
	aux = 2 * map->semi_len;	
	c = map->map[player->pos_y / map->height][(player->pos_x - (aux - map->semi_len)) / map->width];
	if(c == '1')
		color = 0xFF0000FF;
	insert_point(&(sq.p0), player->center_point->x - map->semi_len, player->center_point->y - y);
	insert_point(&(sq.p1), sq.p0.x + rest, sq.p0.y);
	insert_point(&(sq.p2), sq.p0.x + rest, sq.p0.y + map->height);
	insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);
	draw_square_filled(player->img, &sq, color, 1);
	aux = aux - rest;
	unsigned int aux2 = map->semi_len - y;
	printf("aux2: %d\n", aux2);
	insert_point(&(sq1.p3), sq.p0.x, sq.p0.y);	
	insert_point(&(sq1.p2), sq.p1.x, sq.p1.y);
	insert_point(&(sq1.p0), sq1.p3.x, sq1.p3.y - map->height);
	insert_point(&(sq1.p1), sq1.p2.x, sq1.p0.y);
	draw_square_filled(player->img, &sq1, color, 1);
	aux2 = aux2 - map->height;
	while(aux2 > 0)
	{
		if((aux2 / 60) != 0)
		{
			
			insert_point(&(sq1.p3), sq1.p0.x, sq1.p0.y);	
			insert_point(&(sq1.p2), sq1.p1.x, sq1.p1.y);
			insert_point(&(sq1.p0), sq1.p3.x, sq1.p3.y - map->height);
			insert_point(&(sq1.p1), sq1.p2.x, sq1.p2.y - map->height);
			printf("--aux2: %d\n", aux2);	
			printf("p0=> x: %d, y: %d\n", sq1.p0.x, sq1.p0.y);
			printf("p1=> x: %d, y: %d\n", sq1.p1.x, sq1.p1.y);
			printf("p2=> x: %d, y: %d\n", sq1.p2.x, sq1.p2.y);
			printf("p3=> x: %d, y: %d\n", sq1.p3.x, sq1.p3.y);
			aux2 = aux2 - map->height;
		}
		else
		{
			rest = aux2 % map->height;
			
			insert_point(&(sq1.p3), sq1.p0.x, sq1.p0.y);	
			insert_point(&(sq1.p2), sq1.p1.x, sq1.p1.y);
			insert_point(&(sq1.p0), sq1.p3.x, sq1.p3.y - rest);
			insert_point(&(sq1.p1), sq1.p2.x, sq1.p2.y - rest);	
			printf("rest: %d\n", rest);	
			printf("p0=> x: %d, y: %d\n", sq1.p0.x, sq1.p0.y);
			printf("p1=> x: %d, y: %d\n", sq1.p1.x, sq1.p1.y);
			printf("p2=> x: %d, y: %d\n", sq1.p2.x, sq1.p2.y);
			printf("p3=> x: %d, y: %d\n", sq1.p3.x, sq1.p3.y);
			aux2 = 0;
		}

		draw_square_filled(player->img, &sq1, color, 1);
	}

	while(aux > 0)
	{
		c = map->map[player->pos_y / map->height][(player->pos_x - (aux - map->semi_len)) / map->width];
		if(c == '1')
			color = 0xFF0000FF;
		else
			color = 0x0000FFFF;
		if((aux / map->width) != 0)	
		{
			insert_point(&(sq.p0), sq.p1.x, sq.p1.y);
			insert_point(&(sq.p1), sq.p0.x + map->width, sq.p0.y);
			insert_point(&(sq.p2), sq.p0.x + map->width, sq.p0.y + map->height);
			insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);
			aux = aux - map->width;
		}
		else
		{
			rest = aux % map->width;
			aux = 0;
			insert_point(&(sq.p0), sq.p1.x, sq.p1.y);
			insert_point(&(sq.p1), sq.p0.x + rest, sq.p0.y);
			insert_point(&(sq.p2), sq.p0.x + rest, sq.p0.y + map->height);
			insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);
		}	
		draw_square_filled(player->img, &sq, color, 1);
	}
}
