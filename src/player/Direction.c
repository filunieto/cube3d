
#include "../../inc/player/Player.h"

void	init_direction(t_player *player)
{
	player->angle = 270;	
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
	if(clockwise == 1)
		player->angle += 6;
	else if(clockwise == -1)
		player->angle -= 6;

	if(player->angle < 0)
		player->angle = 360 + player->angle;
	else if(player->angle > 360)
		player->angle = player->angle % 360;
	
	angle = (player->angle * M_PI) / 180;
	
	if(clockwise == -1 || clockwise == 1)
	{
		x = player->direction->x;
		y = player->direction->y;
		player->direction->x = player->length_direction * cos(angle);
		player->direction->y = player->length_direction * sin(angle);	
		update_direction(player);
		/*player->direction->x = round((x * cos(clockwise * angle)) - 
				(y * sin(clockwise * angle)));
		player->direction->y = round((x * sin(clockwise * angle)) 
				+ (y * cos(angle)));*/
		//mlx_delete_image(player->mlx, player->img);
		//player->img = mlx_new_image(player->mlx, player->screen_x, player->screen_y);
		//mlx_image_to_window(player->mlx, player->img, 0, 0);
	}
}