/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:56:52 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 22:43:45 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

static void	set_direction_aux(t_map *map, t_pars *parsing_str,
				t_player *player, int i);

void	set_direction(t_map *map, t_player *player, t_pars *parsing_str)
{
	unsigned int	i;

	i = 0;
	while (i <= map->rows)
	{	
		map->map[i] = ft_strdup(parsing_str->map_normal[i]);
		set_direction_aux(map, parsing_str, player, i);
		i++;
	}
}

void	free_map(t_map *map)
{	
	unsigned int	i;

	i = 0;
	while (i <= map->rows)
	{
		free(map->map[i]);
		i++;
	}
	mlx_delete_texture(map->no);
	mlx_delete_texture(map->so);
	mlx_delete_texture(map->ea);
	mlx_delete_texture(map->we);
	free(map->map);
}

void	check_color(char c, int *color)
{
	if (c == '1')
		*color = COLOR_WALLS;
	else if (c == 'N' || c == 'E' || c == 'W' || c == 'S' || c == '0')
		*color = COLOR_FREE_SPACES;
	else
		*color = 0x000000FF;
}

static void	set_direction_aux(t_map *map, t_pars *parsing_str,
				t_player *player, int i)
{
	unsigned int	j;

	j = 0;
	while (parsing_str->map_normal[i][j] != '\0')
	{
		if (parsing_str->map_normal[i][j] == 'N'
			|| parsing_str->map_normal[i][j] == 'S'
			|| parsing_str->map_normal[i][j] == 'E'
			|| parsing_str->map_normal[i][j] == 'W')
		{
			if (parsing_str->map_normal[i][j] == 'N')
				player->angle = 270;
			else if (parsing_str->map_normal[i][j] == 'S')
				player->angle = 90;
			else if (parsing_str->map_normal[i][j] == 'W')
				player->angle = 180;
			else if (parsing_str->map_normal[i][j] == 'E')
				player->angle = 0;
			player->pos_x = (j * map->width) + (map->width / 2);
			player->pos_y = (i * map->height) + (map->height / 2);
			break ;
		}
		j++;
	}
}
