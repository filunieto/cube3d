/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:56:52 by anramire          #+#    #+#             */
/*   Updated: 2023/03/16 19:31:34 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/map/Map.h"

void	show_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->rows)
	{
		printf("%s\n", map->map[i]);//we use this printf!!!!!!!!!!!!,
									//instead ft_p should be used
		i++;
	}	
}

void	free_map(t_map *map)
{	
	unsigned int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		i++;
	}
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
