/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:05 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/21 00:57:46 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

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
	return(0);
}

/*
	vamos a l aprimera linea donde aparezca el mapa. A partir de ahí , verificamos que los caracteres sean los correctso 
	que este cerrado por 1. que solo haya un jugador
*/
int		check_map(t_pars* parsing_str) //is_map_ok : podemos llamar a al afuncion
{

	parsing_str->nb_line_map = find_init(parsing_str); //podría guardar este parametro en la estructura?
	//printf(" linea del mapa en check_map: %i, %s", init, parsing_str->map[init]);
	if (is_map_consistent(parsing_str))
	{
		printf("el mapa está jodio. Borrar este mensaje");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		is_map_consistent(t_pars* parsing_str)
{
	if (map_char(parsing_str))
	{
		return (print_error(ERR_MAP1_MES, ERR_MAP1));
	}
	if (map_closed(parsing_str))
	{
		return (print_error(ERR_MAP2_MES, ERR_MAP2));
	}
	return (EXIT_FAILURE);
}

/*
	Seguir por aquí mñana martes
*/
int		map_char(t_pars* parsing_str)
{
	return (EXIT_FAILURE);
}

// int	check_lines2(t_pars* parsing_str)
// {
// 	int	i;

// 	i = -1;
// 	char *s_trimmed;
// 	char **s_splited_cleaned;
// 	while (parsing_str->map[++i])
// 	{
// 		s_trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
// 		if ( ft_strlen(s_trimmed)) //en caso contrario hay que hacer free?? no hay nada en la linea
// 		{
// 			s_splited_cleaned =  ft_split(s_trimmed, SPACE);
// 			if (check_arguments(parsing_str, s_splited_cleaned))
// 			{
// 				free_split(&s_splited_cleaned);
// 				printf("Parametros de colores o texturas jodido. borra este mensaje y dejar solo free y return. Mesnaje de erro serñaprevio\n");
// 				return (1);
// 			}
// 			free_split(&s_splited_cleaned);
// 		}
// 		free(s_trimmed);
// 		s_trimmed = NULL;
// 	}
// 	return (0);
// }
