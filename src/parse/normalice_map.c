/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalice_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:48 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/22 18:23:30 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * parsing_str->map_normal : se maloquea la longitud más el 0/
 * @param parsing_str 
 * @return int 
 */

int normalize_map(t_pars* parsing_str)
{
	int i;
	int len_mllc;

	len_mllc = parsing_str->nb_endline_map - parsing_str->nb_line_map + 2;
	parsing_str->map_normal = ft_calloc(sizeof(char *), len_mllc);
	if (!parsing_str->map_normal)
		return(print_error(ERR_MALLO_MES, ERR_MALLO));
	i = -1;
	while (++i < len_mllc)
	{
		parsing_str->map_normal[i] = ft_calloc(sizeof(char), parsing_str->max_leng_map); //incluido el nullterm
		if (!parsing_str->map_normal[i])
			return(print_error(ERR_MALLO_MES, ERR_MALLO));
	}
	if (copy_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	copy_map(t_pars* parsing_str)
{
	int line_run;
	int last_lin;
	//int	i;

	line_run = parsing_str->nb_line_map;
	last_lin = parsing_str->nb_endline_map;
	//i = -1;
	while(line_run < (int)parsing_str->nb_endline_map)
	{
	
		//copy_char(parsing_str, parsing_str->map[line_run], parsing_str->map_normal[line_run - parsing_str->nb_line_map]);
		copy_char(parsing_str, line_run);
		line_run++;
	}
	//para cada liena desde el comienzo del map. Copiar char por char y si no encuentra nada o un espacio pone un .
	return (EXIT_SUCCESS);
}

int	copy_char(t_pars* parsing_str, int line_run) //esta funcion puedes ser un void
{
	int i;
	char *map;
	char *map_norml;
	
	map = parsing_str->map[line_run];
	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
	i = -1;
	printf("Principio de copy char: entra la linea %i. |%s|\n, ",line_run, map);
	while (++i < (int)parsing_str->max_leng_map)
	{
		
		if (map[i] == SPACE || !map[i])
		{
			map_norml[i] = PT;
		}
		else
		{
			map_norml[i] = map[i];
		}
	}
	printf(" final en copy char: linea del mapa_nomrliazado %lu. |%s|\n, ",line_run - parsing_str->nb_line_map, map_norml);
	return (EXIT_SUCCESS);
}