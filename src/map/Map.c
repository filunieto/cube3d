/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:58:11 by anramire          #+#    #+#             */
/*   Updated: 2023/03/24 19:02:26 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"


extern void	loop_column_up(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values);

extern void	loop_column_down(t_map *map, t_player *player, t_4vertex *sq1, int *auxiliar_values);
extern void loop_draw_map(t_map *map, t_player *player, t_4vertex *sq, int *auxiliar_values);

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
			"10000000N011000001110111110111111",
			"11110111111111011100000010001    ",
			"11110111111111011101010010001    ",
			"11000000110101011100000011001    ",
			"10000000000000001100000011001    ",
			"10000000000000001101010010001    ",
			"1100000111010101111101101000101  ",
			"11110111 1110101 101111010001    ",
			"11111111 1111111 111111111111    "
	};
	map->semi_len = 150;
	map->width = 40;
	map->height = 40;
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
	t_line			line;
	aux[2] = (int)player->pos_y % map->height;
	rest = (map->semi_len - ((int)player->pos_x % map->width)) % map->width;
	aux[1] = 2 * map->semi_len;

	if((int)((int)player->pos_x - (aux[1] - map->semi_len)) < 0)
	{
		color = 0x000000FF;
		aux[0] = -1;
	}
	else
	{
		aux[0] = ((int)player->pos_x - (aux[1] - map->semi_len)) / map->width;
		check_color(map->map[(int)player->pos_y / map->height][aux[0]], &color);
	}
	insert_point(&(sq.p0), player->center_point->x - map->semi_len,
		player->center_point->y - aux[2]);
	insert_point(&(sq.p1), sq.p0.x + rest, sq.p0.y);
	insert_point(&(sq.p2), sq.p0.x + rest, sq.p0.y + map->height);
	insert_point(&(sq.p3), sq.p0.x, sq.p0.y + map->height);

	draw_square_filled(player->img, &sq, color, 1);
	aux[1] -= rest;
	insert_points_line(&line, &(sq.p0), &(sq.p1));
	draw_column_up(map, player, &line, aux);
	insert_points_line(&line, &(sq.p2), &(sq.p3));
	draw_column_down(map, player, &line, aux);

	while (aux[1] > 0)
		loop_draw_map(map, player, &sq, aux);
}

/*
 * Function to draw the upper part of the column
 *
 * aux=> 0 -> offset_x, 1 -> auxiliar, 2 -> y
 * params=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
*/
void	draw_column_up(t_map *map, t_player *player, t_line *line, int *aux)
{	
	t_4vertex		sq1;
	int				color;
	int				params[3];

	params[0] = aux[0];
	params[1] = map->semi_len - aux[2];
	params[2] = (int)player->pos_y - map->height;
	if (params[2] < 0)
		color = 0x000000FF;
	else
		check_color(map->map[params[2] / map->height][params[0]], &color);
	insert_point(&(sq1.p3), line->p0->x, line->p0->y);
	insert_point(&(sq1.p2), line->p1->x, line->p1->y);
	insert_point(&(sq1.p0), sq1.p3.x, sq1.p3.y - map->height);
	insert_point(&(sq1.p1), sq1.p2.x, sq1.p0.y);
	draw_square_filled(player->img, &sq1, color, 1);
	params[1] -= map->height;
	while (params[1] > 0)
		loop_column_up(map, player, &sq1, params);
}

/*
 *Function to draw the down part of the column
 * aux=> 0 -> offset_x, 1 -> auxiliar, 2 -> y
 * params=> 0 -> offset_x, 1 -> aux_2, 2 -> aux_3
 */
void	draw_column_down(t_map *map, t_player *player, t_line *line, int *aux)
{
	t_4vertex	sq1;
	int			color;
	int			params[3];

	params[0] = aux[0];
	params[1] = map->semi_len - (map->height - aux[2]);
	params[2] = (int)player->pos_y + map->height;
	if ((params[2] / map->height) >= map->rows)
		color = 0x000000FF;
	else
		check_color(map->map[params[2] / map->height][params[0]], &color);
	insert_point(&(sq1.p0), line->p1->x, line->p1->y);
	insert_point(&(sq1.p1), line->p0->x, line->p0->y);
	insert_point(&(sq1.p2), sq1.p1.x, sq1.p1.y + map->height);
	insert_point(&(sq1.p3), sq1.p0.x, sq1.p0.y + map->height);
	draw_square_filled(player->img, &sq1, color, 1);
	params[1] -= map->height;
	while (params[1] > 0)
		loop_column_down(map, player, &sq1, params);
}
