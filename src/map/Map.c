/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:11 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 19:10:12 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	draw_column_up(t_map *map, t_player *player, t_point *p0, t_point *p1,
			unsigned int y, unsigned int offset_x);
void	draw_column_down(t_map *map, t_player *player, t_point *p0,
			t_point *p1, unsigned int y, unsigned int offset_x);
extern void	loop_column_up(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values);

extern void	loop_column_down(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values);
void loop_draw_map(t_map *map, t_player *player, t_4vertex *sq, int *auxiliar_values);

void	init_map(t_map *map, t_player *player)
{
	unsigned int	rows;
	unsigned int	i;
	unsigned int	j;

	rows = 14;
	i = 0;
	char *map_aux[] = {
			"        1111111111111111111111111",
			"        1000000000110000000000001",
			"        1011000001110000000000001",
			"        1001000000000000000000001",
			"111111111011000001110000000000001",
			"100000000011000001110111110111111",
			"11110111111111011100000010001    ",
			"11110111111111011101010010001    ",
			"11000000110101011100000011001    ",
			"10000000000000001100000011001    ",
			"10000000000000001101010010N01    ",
			"1100000111010101111101101000101  ",
			"11110111 1110101 101111010001    ",
			"11111111 1111111 111111111111    "
	};
	map->semi_len = 200;
	map->width = 60;
	map->height = 60;
	map->rows = rows;
	map->columns = ft_strlen(map_aux[i]);
	map->map = (char **) malloc(rows * sizeof(char *));	
	while (i < 14)
	{	
		map->map[i] = ft_strdup(map_aux[i]); //we use this strdup!!!!!!!!!!!!,
										  //instead ft_strdup should be used
		j = 0;
		while (map_aux[i][j] != '\0')
		{
			if (map_aux[i][j] == 'N' || map_aux[i][j] == 'S'
					|| map_aux[i][j] == 'E' || map_aux[i][j] == 'W')
			{
				player->pos_x = (j * map->width) + (map->width / 2);
				player->pos_y = (i * map->height) + (map->height / 2);
				break ;
			}
			j++;
		}
		i++;
	}
}

/*
 *Function to make the main loop drawing map
 * aux=> 0 -> offset_x, 1 -> auxiliar, 2 -> y
 * */
void	draw_map(t_map *map, t_player *player)
{
	unsigned int	rest;
	int				color;
	t_4vertex		sq;
	int				aux[3];

	aux[2] = player->pos_y % map->height;
	rest = (map->semi_len - (player->pos_x % map->width)) % map->width;
	aux[1] = 2 * map->semi_len;
	aux[0] = (player->pos_x - (aux[1] - map->semi_len)) / map->width;
	check_color(map->map[player->pos_y / map->height][aux[0]], &color);
	insert_point(&(sq.p0), player->center_point->x - map->semi_len,
		player->center_point->y - aux[2]);
	insert_point(&(sq.p1), sq.p0.x + rest, sq.p0.y);
	insert_point(&(sq.p2), sq.p0.x + rest, sq.p0.y + map->height);
	insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);
	draw_square_filled(player->img, &sq, color, 1);
	aux[1] -= rest;
	draw_column_up(map, player, &(sq.p0), &(sq.p1), aux[2], aux[0]);
	draw_column_down(map, player, &(sq.p2), &(sq.p3), aux[2], aux[0]);
	while (aux[1] > 0)
		loop_draw_map(map, player, &sq, aux);
}

void	draw_column_up(t_map *map, t_player *player, t_point *p0, t_point *p1, unsigned int y, unsigned int offset_x)
{	
	t_4vertex		sq1;
	int				color;
	int 			auxiliar_values[3];

	auxiliar_values[0] = (int)offset_x;
	auxiliar_values[1] = map->semi_len - y;
	auxiliar_values[2] = player->pos_y - map->height;	
	if(auxiliar_values[2]  < 0)
		color = 0x000000FF;	
	else
		check_color(map->map[auxiliar_values[2]/ map->height][auxiliar_values[0]], &color);	
	insert_point(&(sq1.p3), p0->x, p0->y);	
	insert_point(&(sq1.p2), p1->x, p1->y);
	insert_point(&(sq1.p0), sq1.p3.x, sq1.p3.y - map->height);
	insert_point(&(sq1.p1), sq1.p2.x, sq1.p0.y);
	draw_square_filled(player->img, &sq1, color, 1);
	auxiliar_values[1] -= map->height;
	while (auxiliar_values[1] > 0)
		loop_column_up(map, player, &sq1, auxiliar_values);
}

void	draw_column_down(t_map *map, t_player *player, t_point *p2, t_point *p3, unsigned int y, unsigned int offset_x)
{
	t_4vertex	sq1;
	int			color;
	int			auxiliar_values[3];

	auxiliar_values[0] = (int)offset_x;
	auxiliar_values[1] = map->semi_len - (map->height - y);
	auxiliar_values[2] = player->pos_y + map->height;
	if((auxiliar_values[2]/ map->height) >= map->rows)
		color = 0x000000FF;	
	else
		check_color(map->map[auxiliar_values[2]/ map->height][offset_x], &color);
	insert_point(&(sq1.p0), p3->x, p3->y);	
	insert_point(&(sq1.p1), p2->x, p2->y);
	insert_point(&(sq1.p2), sq1.p1.x, sq1.p1.y + map->height);
	insert_point(&(sq1.p3), sq1.p0.x, sq1.p0.y + map->height);
	draw_square_filled(player->img, &sq1, color, 1);
	auxiliar_values[1] -= map->height;
	while (auxiliar_values[1] > 0)
		loop_column_down(map, player, &sq1, auxiliar_values);
}
