
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

//Anti-Clockwise = -1, Clockwise = 1
void rotate(t_player *player, int clockwise)
{
	int x;
	int y;
	double angle;

	angle = 0.12217304764;	
	if(clockwise == -1 || clockwise == 1)
	{
		x = player->direction->x;
		y = player->direction->y;	
		player->direction->x = round((x * cos(clockwise * angle)) - 
				(y * sin(clockwise * angle)));
		player->direction->y = round((x * sin(clockwise * angle)) 
				+ (y * cos(angle)));
		update_direction(player);
		//mlx_delete_image(player->mlx, player->img);
		//player->img = mlx_new_image(player->mlx, player->screen_x, player->screen_y);
		//mlx_image_to_window(player->mlx, player->img, 0, 0);
	}
}
