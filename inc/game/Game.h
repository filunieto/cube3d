
#if !defined (GAME_H)
#define GAME_H

# include "../player/Player.h"

typedef struct s_game{
	
	mlx_t *mlx;	
	t_player *player;

}t_game;

void	init_game(mlx_t *mlx, mlx_image_t *img, t_game *game);
void	free_game(t_game *game);
#endif
