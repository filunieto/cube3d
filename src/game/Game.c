
#include "../../inc/game/Game.h"

void	resize_func(int x, int y, void *param);

void	init_game(mlx_t *mlx, mlx_image_t *img, t_game *game)
{
	game->mlx = mlx;
	game->player = (t_player *) malloc (sizeof(t_player));
	init_player(mlx, img, game->player);
	mlx_resize_hook(game->mlx, resize_func, game);
}

void free_game(t_game *game)
{
	free_player(game->player);
	free(game->player);
}


void	resize_func(int x, int y, void *param)
{
	t_game *game = (t_game *)param;
	mlx_image_t *img = game->player->img;
	game->player->img = mlx_new_image(game->player->mlx, x, y);
	mlx_delete_image(game->player->mlx, img);
	insert_point(game->player->center_point, x / 2, y / 2);
	mlx_image_to_window(game->player->mlx, game->player->img, 0, 0);
	update_direction(game->player);
	paint_player(game->player);
}

