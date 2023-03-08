
#include "../../inc/game/Game.h"

void paint(t_game *game)
{
	clear_image(game->player);
	draw_map(game->map, game->player);
	paint_player(game->player);
}
