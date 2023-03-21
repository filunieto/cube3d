/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:05 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/21 20:04:59 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"



/*
	vamos a l aprimera linea donde aparezca el mapa. A partir de ahí , verificamos que los caracteres sean los correctso 
	que este cerrado por 1. que solo haya un jugador
*/
int		check_map(t_pars* parsing_str) //is_map_ok : podemos llamar a al afuncion
{
	parsing_str->nb_line_map = find_init(parsing_str); //podría guardar este parametro en la estructura?
	parsing_str->nb_endline_map = find_end(parsing_str);
	parsing_str->max_leng_map = find_max_line(parsing_str);
	if (parsing_str->nb_endline_map - parsing_str->nb_line_map < 2)
		return(print_error(ERR_MAP0_MES, ERR_MAP0));
	if (is_map_consistent(parsing_str))
	{
		printf("el mapa está jodio. Borrar este mensaje despues");
		return (EXIT_FAILURE);
	}
	printf("En check map , map consisten d emomento\n");
	return (EXIT_SUCCESS);
}

int		is_map_consistent(t_pars* parsing_str)
{
	if (map_char(parsing_str))
		return (EXIT_FAILURE);
	if (one_player(parsing_str))
		return (EXIT_FAILURE);
	if (map_closed(parsing_str)) //si lo que rodea a 1 0 es un espacio 
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



/**
 * @brief 
 * Encuentra la primera línea del map. No verifica consistencia
 * @param parsing_str 
 * @return int valor de comienzo
 */

int		find_init(t_pars* parsing_str)
{
	int i;
	
	char *trimmed_spac;
	char *trimmed_map;
	i = -1;
	while (parsing_str->map[++i])
	{
		trimmed_spac = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if (ft_strlen(trimmed_spac)) //si no es espacios entra
		{
			trimmed_map = ft_strtrim(trimmed_spac, MAP_STR);
			if (ft_strlen(trimmed_map) == 0)
			{
				free(trimmed_spac);
				free(trimmed_map);
				return (i);
			}
			free(trimmed_map);
		}
		free(trimmed_spac);
	}
	return(EXIT_SUCCESS);
}

/**
 * @brief 
 * Encuentra la última línea del map.  No verifica consistencia
 * @param parsing_str 
 * @return int valor del final
 */

int		find_end(t_pars* parsing_str)
{
	int i;
	char *trimmed_spac;
	int end;
	
	end = 0;
	i = parsing_str->nb_line_map -1;
	while (parsing_str->map[++i])
	{
		trimmed_spac = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if (ft_strlen(trimmed_spac)) //si no es espacios entra
			end++;
		free(trimmed_spac);
	}
	return(end + parsing_str->nb_line_map - 1);
}

int		find_max_line(t_pars* parsing_str) // de vuelve la long sin  incluir   \n
{
	size_t	max_leng_map;
	size_t	leng_line;
	int	i;

	max_leng_map = 0;
	i = parsing_str->nb_line_map;
	while (i < (int)parsing_str->nb_endline_map)
	{
		leng_line = ft_strlen(parsing_str->map[i]);
		if (leng_line > max_leng_map)
			max_leng_map = leng_line;
		i++;
	}
	return (max_leng_map - 1);
}