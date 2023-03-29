/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:21:02 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 22:35:19 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../player/Player.h"
# include "../map/Map.h"
# include "../../MLX42/include/MLX42/MLX42_Input.h"
# include "../../memory-leaks/include/memory_leaks.h"
# include "../shapes/Shapes.h"
# include "../parse/Parse.h"

typedef struct s_game
{
	mlx_t		*mlx;
	t_player	*player;
	t_map		*map;
}t_game;

//Structure to help drawing vertical lines in raycaster
typedef struct s_draw_vertical
{
	int		y0;
	int		y1;
	float	ratio;
	float	acc;
}t_draw_vertical;

typedef struct s_data_raycast
{
	int		izquierda;
	int		abajo;
	float	rads;
}t_data_raycast;

typedef struct s_texture
{
	int				x_texture;
	mlx_texture_t	*texture;	
}t_texture;
void	init_game(mlx_t *mlx, mlx_image_t *img,
			t_game *game, t_pars *parsing_str);
void	free_game(t_game *game);

//Function which performs paint algorithm
void	paint(t_game *game);

//Function responsible of casting rays
float	cast(t_game *game, float angle,
			t_point_f *p_ext, t_texture *texture);

//Function to calculate distance between 2 points
float	distancia(float p0x, float p0y, float p1x, float p1y);

//Function to limit the direction line in minimap
void	adjust_line(t_map *map, t_player *player,
			t_point_f *p_extremo, t_point *p_final);

void	key_advance_and_back_aux(void *param);
#endif
