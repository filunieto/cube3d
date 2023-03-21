/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:21:02 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 18:40:48 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if !defined (GAME_H)
#define GAME_H

# include "../player/Player.h"
# include "../map/Map.h"
# include "../../MLX42/include/MLX42/MLX42_Input.h"
# include "../../memory-leaks/include/memory_leaks.h"
# include "../shapes/Shapes.h"
typedef struct s_game{
	
	mlx_t *mlx;
	t_player *player;
	t_map *map;
}t_game;

void	init_game(mlx_t *mlx, mlx_image_t *img, t_game *game);
void	free_game(t_game *game);

//Function which performs paint algorithm
void	paint(t_game *game);

//Function responsible of casting rays
void	cast(t_map *map, t_player *player, float angle, t_point_f *p_ext);

//Function to calculate distance between 2 points
float distancia(float p0x, float p0y, float p1x, float p1y);

//Function to limit the direction line in minimap
void adjust_line(t_map *map, t_player *player, t_point_f *p_extremo, t_point *p_final);

#endif
