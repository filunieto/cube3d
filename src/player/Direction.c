
#include "../../inc/player/Player.h"

void	init_direction(t_player *player)
{	
	player->length_direction = 50;
	player->direction = (t_point *) malloc(sizeof(t_point));	
	player->absolute_direction = (t_point *) malloc(sizeof(t_point));
	insert_point(player->direction, 0 , 
			- player->length_direction);
	insert_point(player->absolute_direction,
			player->center_point->x + player->direction->x,
			player->center_point->y + player->direction->y);
}


void update_direction(t_player *player)
{	
	insert_point(player->absolute_direction,
			player->center_point->x + player->direction->x,
			player->center_point->y + player->direction->y);
}
