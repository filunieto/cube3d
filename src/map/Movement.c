/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:56:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 21:27:31 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	check_collision(t_map *map, t_player *player, int advance_x, int advance_y);
static void	check_horizontal_collision(t_map *map, t_player *player, int advance_x);
static void	check_vertical_collision(t_map *map, t_player *player, int advance_y);
static void check_diagonal_collision(t_map *map, t_player *player, int advance_x, int advance_y);


int check_left_up_player(t_player *player, t_map *map, int advance_x, int advance_y);
int check_right_up_player(t_player *player, t_map *map, int advance_x, int advance_y);
int check_left_down_player(t_player *player, t_map *map, int advance_x, int advance_y);
int check_right_down_player(t_player *player, t_map *map, int advance_x, int advance_y);

//Function to move player in the direction of direction vector
void player_advance(t_map *map, t_player *player, int direction)
{
	float angle;
	float advance_x;
	float advance_y;
	angle = (player->angle * M_PI) / 180;
	if(direction == -1 || direction == 1)
	{
		advance_x = (float)direction * player->vel * cos(angle);
		advance_y = (float)direction * player->vel * sin(angle);
		check_collision(map, player, round(advance_x), round(advance_y));
	}
}


//Function to check collision
void	check_collision(t_map *map, t_player *player, int advance_x, int advance_y)
{
	
	if(advance_y !=  0 && advance_x == 0)
		check_vertical_collision(map, player, advance_y);
	else if(advance_x != 0 && advance_y == 0)
		check_horizontal_collision(map, player, advance_x);
	else if(advance_x != 0 && advance_y != 0)
		check_diagonal_collision(map, player, advance_x, advance_y);
}

static void	check_vertical_collision(t_map *map, t_player *player, int advance_y)
{

	unsigned int provisional_pos_y;
	int aux_advance;
	
	provisional_pos_y = player->pos_y + advance_y;
	aux_advance = 0;
	if(advance_y < 0)
	{
		printf("arriba coord_y: %d\n", (int)(provisional_pos_y - (player->tam / 2)) / map->height);
		if(check_left_up_player(player, map, 0, advance_y) == 0 && 
				check_right_up_player(player, map, 0, advance_y) == 0)
			aux_advance = advance_y;
		else
			aux_advance = -1 * ((player->pos_y - (player->tam / 2 )) % map->height);
	}
	else
	{
		printf("abajo coord_y: %d\n", (int)(provisional_pos_y + (player->tam / 2)) / map->height);
		if(check_left_down_player(player, map, 0, advance_y) == 0 && 
				check_right_down_player(player, map, 0, advance_y) == 0)
			aux_advance = advance_y;
		else	
			aux_advance = map->height - player->tam - ((player->pos_y - (player->tam / 2 )) % map->height);
	}
		player->pos_y += aux_advance;

}
static void	check_horizontal_collision(t_map *map, t_player *player, int advance_x)
{
	
	unsigned int provisional_pos_x;
	int aux_advance;

	provisional_pos_x = player->pos_x + advance_x;
	if(advance_x < 0)
	{
		printf("izquierda coord_x: %d\n", (int)(provisional_pos_x - (player->tam / 2)) / map->width);
		if(check_left_up_player(player, map, advance_x, 0) == 0 &&
				check_left_down_player(player, map, advance_x, 0) == 0)
		aux_advance = advance_x;
		else
			aux_advance = -1 * ((player->pos_x - (player->tam / 2 )) % map->width);
	}
	else
	{
		if(check_right_up_player(player, map, advance_x, 0) == 0 &&
				check_right_down_player(player, map, advance_x, 0) == 0)
			aux_advance = advance_x;
		else
			aux_advance = map->width - player->tam - ((player->pos_x - (player->tam / 2 )) % map->width);
		printf("derecha coord_x: %d\n", (int)(provisional_pos_x + (player->tam / 2)) / map->width);
	}
		player->pos_x += aux_advance;
	printf("Player pos=> x: %d, y: %d\n", player->pos_x, player->pos_y);

}

static void check_diagonal_collision(t_map *map, t_player *player, int advance_x, int advance_y)
{
	int aux_advance_y;
	int aux_advance_x;
	int aux_x;
	int aux_y;
	
	aux_x = player->pos_x;
	aux_y = player->pos_y;
	printf("Diagonal\n");
	if(advance_x < 0 && advance_y < 0)
	{
		printf("Arriba izquierda\n");
		if(check_right_up_player(player, map, advance_x, advance_y) == 0 &&
			check_left_up_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_y += advance_y;
		}
		else
		{
			aux_advance_y = ((player->pos_y - (player->tam / 2 )) % map->height);
			printf("Ceil: %d\n",((player->pos_y - (player->tam / 2 )) % map->height) );
			if(aux_advance_y <= (int)(player->tam / 2) && aux_advance_y <= (-1 * advance_y)
					&& aux_advance_y != 0)
			{
				printf("Entrando\n");
				aux_y -= aux_advance_y;
			}
			else if(check_right_up_player(player, map, 0, advance_y) == 0 && 
					check_left_up_player(player, map, 0, advance_y) == 0)
			{
				printf("New advance_y: %d\n", advance_y);
				aux_y += advance_y;	
			}
			printf("Down alternative aux_advance_y: %d, and advance_y: %d, player_tam: %d\n", aux_advance_y, advance_y, (int)(player->tam / 2));

		}

		//----------
				if(check_left_down_player(player, map, advance_x, advance_y) == 0 &&
			check_left_up_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_x += advance_x;
		}
		else
		{
			aux_advance_x = ((player->pos_x - (player->tam / 2)) % map->width);
			if(aux_advance_x <= (int)(player->tam / 2) && aux_advance_x <= (-1 * advance_x)
					&& aux_advance_x != 0)
			{
				printf("Entrando\n");
				aux_x -= aux_advance_x;
			}
			else if(check_left_down_player(player, map, advance_x, 0) == 0 && 
					check_left_down_player(player, map, advance_x, 0) == 0)
			{
				printf("New advance_x: %d\n", advance_x);
				aux_x += advance_x;	
			}
			printf("Down alternative aux_advance_x: %d, and advance_x: %d, player_tam: %d\n", aux_advance_x, advance_x, (int)(player->tam / 2));
		}
	}
	else if(advance_x > 0 && advance_y < 0)
	{
		printf("Arriba derecha\n");
		if(check_right_up_player(player, map, advance_x, advance_y) == 0 &&
			check_left_up_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_y += advance_y;
		}
		else
		{
			printf("Right: %d\n",check_right_up_player(player, map, 0, advance_y));
			printf("Left: %d\n",check_left_up_player(player, map, 0, advance_y));
			aux_advance_y = ((player->pos_y - (player->tam / 2 )) % map->height);
			if(aux_advance_y <= (int)(player->tam / 2) && aux_advance_y <= (-1 * advance_y)
					&& aux_advance_y != 0)
			{
				printf("Entrando\n");
				aux_y -= aux_advance_y;
			}
			else if(check_right_up_player(player, map, 0, advance_y) == 0 && 
					check_left_up_player(player, map, 0, advance_y) == 0)
			{
				printf("New advance_y: %d\n", advance_y);
				aux_y += advance_y;	
			}
			printf("Down alternative aux_advance_y: %d, and advance_y: %d, player_tam: %d\n", aux_advance_y, advance_y, (int)(player->tam / 2));
		}
	//-------------	
		if(check_right_down_player(player, map, advance_x, advance_y) == 0 &&
			check_right_up_player(player, map, advance_x, advance_y) == 0)
		{
			aux_x += advance_x;
		}
		else
		{

			aux_advance_x = map->width - ((player->pos_x + (player->tam / 2)) % map->width);
			if(aux_advance_x <= (int)(player->tam / 2) && aux_advance_x <= advance_x 
					&& aux_advance_x != 0)
			{
				printf("Entrando\n");
				aux_x += aux_advance_x;
			}
			else if(check_right_down_player(player, map, advance_x, 0) == 0 && 
					check_left_down_player(player, map, advance_x, 0) == 0)
			{
				printf("New advance_x: %d\n", advance_x);
				aux_x += advance_x;	
			}
		}

	}
	else if(advance_x < 0 && advance_y > 0)
	{
		printf("Abajo izquierda\n");
		if(check_right_down_player(player, map, advance_x, advance_y) == 0 &&
			check_left_down_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_y += advance_y;
		}
		else
		{
			aux_advance_y = map->height - ((player->pos_y + (player->tam / 2)) % map->height);
			if(aux_advance_y <= (int)(player->tam / 2) && aux_advance_y <= advance_y
					&& aux_advance_y != 0)
			{
				printf("Entrando\n");
				aux_y += aux_advance_y;
			}
			else if(check_right_down_player(player, map, 0, advance_y) == 0 && 
					check_left_down_player(player, map, 0, advance_y) == 0)
			{
				printf("New advance_y: %d\n", advance_y);
				aux_y += advance_y;	
			}
		}

		//-------------
		if(check_left_down_player(player, map, advance_x, advance_y) == 0 &&
			check_left_up_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_x += advance_x;
		}
		else
		{
			aux_advance_x = ((player->pos_x - (player->tam / 2)) % map->width);
			if(aux_advance_x <= (int)(player->tam / 2) && aux_advance_x <= (-1 * advance_x)
					&& aux_advance_x != 0)
			{
				printf("Entrando\n");
				aux_x -= aux_advance_x;
			}
			else if(check_left_down_player(player, map, advance_x, 0) == 0 && 
					check_left_up_player(player, map, advance_x, 0) == 0)
			{
				printf("New advance_x: %d\n", advance_x);
				aux_x += advance_x;	
			}
			printf("Down alternative aux_advance_x: %d, and advance_x: %d, player_tam: %d\n", aux_advance_x, advance_x, (int)(player->tam / 2));
		}


	}
	else if(advance_x > 0 && advance_y > 0)
	{
		printf("Abajo derecha\n");

		if(check_right_down_player(player, map, advance_x, advance_y) == 0 &&
			check_left_down_player(player, map, advance_x, advance_y) == 0)
		{	
			aux_y += advance_y;
		}
		else
		{
			printf("Right: %d\n",check_right_down_player(player, map, 0, advance_y));
			printf("Left: %d\n",check_left_down_player(player, map, 0, advance_y));
			aux_advance_y = map->height - ((player->pos_y + (player->tam / 2)) % map->height);
			if(aux_advance_y <= (int)(player->tam / 2) && aux_advance_y <= advance_y
					&& aux_advance_y != 0)
			{
				printf("Entrando\n");
				aux_y += aux_advance_y;
			}
			else if(check_right_down_player(player, map, 0, advance_y) == 0 && 
					check_left_down_player(player, map, 0, advance_y) == 0)
			{
				printf("New advance_y: %d\n", advance_y);
				aux_y += advance_y;	
			}

			printf("Down alternative aux_advance_y: %d, and advance_y: %d, player_tam: %d\n", aux_advance_y, advance_y, (int)(player->tam / 2));
		}
	
		if(check_right_down_player(player, map, advance_x, advance_y) == 0 &&
			check_right_up_player(player, map, advance_x, advance_y) == 0)
		{
			aux_x += advance_x;
		}
		else
		{
			aux_advance_x = map->width - ((player->pos_x + (player->tam / 2)) % map->width);
			if(aux_advance_x <= (int)(player->tam / 2) && aux_advance_x <= advance_x
					&& aux_advance_x != 0)
			{
				printf("Entrando\n");
				aux_x += aux_advance_x;
			}
			else if(check_right_down_player(player, map, advance_x, 0) == 0 && 
					check_left_down_player(player, map, advance_x, 0) == 0)
			{
				printf("New advance_x: %d\n", advance_x);
				aux_x += advance_x;	
			}
	printf("Down alternative aux_advance_x: %d, and advance_x: %d, player_tam: %d\n", aux_advance_x, advance_x, (int)(player->tam / 2));

		}

	}
	player->pos_x = aux_x;
	player->pos_y = aux_y;
	printf("Player pos=> x: %d, y: %d\n", player->pos_x, player->pos_y);

}

int check_left_up_player(t_player *player, t_map *map, int advance_x, int advance_y)
{
	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x - (player->tam / 2) + 1 ;
	aux_y = player->pos_y + advance_y - (player->tam / 2) + 1;

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}

int check_right_up_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x + (player->tam / 2) - 1;
	aux_y = player->pos_y + advance_y - (player->tam / 2) + 1;

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}


int check_left_down_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x - (player->tam / 2) + 1;
	aux_y = player->pos_y + advance_y + (player->tam / 2) - 1;

	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}
int check_right_down_player(t_player *player, t_map *map, int advance_x, int advance_y)
{

	int aux_x;
	int aux_y;

	aux_x = player->pos_x + advance_x + (player->tam / 2) - 1;
	aux_y = player->pos_y + advance_y + (player->tam / 2) - 1;
	
	if(map->map[aux_y / map->height][aux_x / map->width] == '1')
		return -1;
	return 0;
}
