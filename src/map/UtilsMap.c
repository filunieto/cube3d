/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UtilsMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:56:52 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 20:33:05 by anramire         ###   ########.fr       */
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
		*color = 0xFF0000FF;
	else if (c == ' ')
		*color = 0x000000FF;
	else
		*color = 0x0000FFFF;
}
