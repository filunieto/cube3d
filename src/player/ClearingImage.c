

#include "../../inc/player/Player.h"

void clear_image(t_player *player)
{
	unsigned int x;
	unsigned int y;
	
	y = 0;
	while(y < player->screen_y)
	{
		x = 0;
		while(x < player->screen_x)
		{
			mlx_put_pixel(player->img, x, y, 0x4a4747FF);
			x++;
		}
		y++;
	}
}
