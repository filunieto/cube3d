/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:25:05 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/20 18:57:51 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

int		find_init(t_pars* parsing_str)
{
	int i;
	
	char *trimmed_spac;
	char *trimmed_map;
	i = 0;
	while (parsing_str->map[i])
	{
		
		trimmed_spac = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if (ft_strlen(trimmed_spac)) //si no es espacios entra
		{
			trimmed_map = ft_strtrim(trimmed_spac, MAP_STR);
			if (ft_strlen(trimmed_map) == 0)
			{
				printf("hemos llegado a la primera linea del mapa: %i", i);
				//hacer free de los 2  trims aqui dentro
				return (i);
			}
			//hacer free de trimmed_map
		}
		//hacer free de trimmed_spac de espacios
		i++;
	}
}

/*
	vamos a l aprimera linea donde aparezca el mapa. A partir de ahí , verificamos que los caracteres sean los correctso 
	que este cerrado por 1. que solo haya un jugador
*/
int		check_map(t_pars* parsing_str) //is_map_ok : podemos llamar a al afuncion
{
	// no hace falta ni split ni trim
	//encontremos el primer elemnto del mapa, y pasemos ese punteroa otra funcion que verificara todo, y guaradra , linea ppio y final del mapa
	int	init;
	int final;

	init = find_init(parsing_str);
	int i = -1;

	return (EXIT_SUCCESS);
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
