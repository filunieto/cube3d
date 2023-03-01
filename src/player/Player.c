
#include "../../inc/player/Player.h"

void	pos_player(mlx_image_t *img, int x, int y)
{
	t_point pos;

	insert_point(&pos, x / 2, y / 2);
	draw_square_pos(img, &pos, 10, 0xE0E0E0FF);
}
