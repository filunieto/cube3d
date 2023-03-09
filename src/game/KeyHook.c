
# include "../../inc/game/Game.h"

void key_func(mlx_key_data_t keydata, void *param)
{
	t_game *game = (t_game *)param;
	if(keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		player_advance(game->player, 1);
		paint(game);
	}else if(keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		player_advance(game->player, -1);
		paint(game);
	}

	if(keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		player_advance(game->player, 1);
		paint(game);
	}else if(keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		player_advance(game->player, -1);
		paint(game);
	}

	if(keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		rotate(game->player, -1);
		paint(game);
	}
	else if(keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		rotate(game->player, 1);
		paint(game);
	}
	if(keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		rotate(game->player, -1);
		paint(game);
	}
	else if(keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		rotate(game->player, 1);
		paint(game);
	}
}
