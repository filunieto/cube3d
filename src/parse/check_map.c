/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:05 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/27 01:17:15 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/*
	vamos a l aprimera linea donde aparezca el mapa. 
	A partir de ahí , verificamos que los caracteres sean los correctso 
	que este cerrado por 1. que solo haya un jugador
*/
int	check_map(t_pars *parsing_str)
{
	if (find_init(parsing_str))
		return (print_error(ERR_MAP10_MES, ERR_MAP10));
	parsing_str->nb_endline_map = find_end(parsing_str);
	parsing_str->max_leng_map = find_max_line(parsing_str);
	printf("->nb_line_map: %zu , ->nb_endline_map  %zu, max leng %zu\n Linea inicio map : 0 y final %zu\n"
	,parsing_str->nb_line_map, parsing_str->nb_endline_map ,parsing_str->max_leng_map, parsing_str->nb_endline_map - parsing_str->nb_line_map );
	if (parsing_str->nb_endline_map - parsing_str->nb_line_map < 2)
		return (print_error(ERR_MAP0_MES, ERR_MAP0));
	if (parsing_str->nb_line_map < 6)
		return (print_error(ERR_MAP10_MES, ERR_MAP10));
	if (is_map_consistent(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_consistent(t_pars *parsing_str)
{
	if (map_char(parsing_str))
		return (EXIT_FAILURE);
	if (one_player(parsing_str))
		return (EXIT_FAILURE);
	if (map_closed(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


//qeu pasa si despues de lo sparametros , solo tenemos espacios y no hay mapa??
/**
 * @brief 
 * Encuentra la primera línea del map. No verifica consistencia, contando desde 0
 * @param parsing_str 
 * @return int valor de comienzo
 */

int	find_init(t_pars *parsing_str)
{
	char	*trimmed_spac;
	int		leng_strim;

	while (parsing_str->map[parsing_str->nb_line_map])
	{
		trimmed_spac = ft_strtrim(parsing_str->map[parsing_str->nb_line_map],
				SPACE_STR);
		leng_strim = ft_strlen(trimmed_spac);
		free(trimmed_spac);
		if (leng_strim == 0)
			parsing_str->nb_line_map++;
		else
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * @brief 
 * Encuentra la última línea del map. No verifica consistencia, contando desde 0
 * @param parsing_str 
 * @return int valor del final
 */

int	find_end(t_pars *parsing_str)
{
	int		i;
	char	*trimmed_spac;
	int		end;
	int		leng_line;

	end = parsing_str->nb_line - 2;
	i = 0;
	while (end >= (int)parsing_str->nb_line_map)
	{
		trimmed_spac = ft_strtrim(parsing_str->map[end], SPACE_STR);
		leng_line = ft_strlen(trimmed_spac);
		free(trimmed_spac);
		if (leng_line == 0)
			i++;
		else
			break ;
		end--;
	}
	return (end);
}

/**
 * @brief 
 * Devuelve la longitud máxima del map para calcular la 
 * matriz normalizada. Nop inclouye el salto de linea
 * @param parsing_str 
 * @return int 
 */
int	find_max_line(t_pars *parsing_str)
{
	size_t	max_leng_map;
	size_t	leng_line;
	int		i;

	max_leng_map = 0;
	i = parsing_str->nb_line_map;
	while (i <= (int)parsing_str->nb_endline_map)
	{
		leng_line = ft_strlen(parsing_str->map[i]);
		if (leng_line > max_leng_map)
			max_leng_map = leng_line;
		i++;
	}
	return (max_leng_map - 1);
}
