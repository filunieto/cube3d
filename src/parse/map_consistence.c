/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_consistence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/21 16:43:29 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Esta función verifica que solo tengamos los caracteres 1 , 0, W
 * E, W, N.
 * 
 * @param parsing_str 
 * @return int 0 sí los caracteres son corretcos
 * otro valor en caso contrario
 */

int		map_char(t_pars* parsing_str)
{
	//char	*trimmed_spac;
	char	*trimmed_map;
	int		i;

	i = parsing_str->nb_line_map - 1;
	while (++i <= (int)parsing_str->nb_endline_map)
	{
		trimmed_map = ft_strtrim(parsing_str->map[i], MAP_STR);
		//printf(" despues de trimear linea %i, chars si long 0 |%s| y su longitud %zu\n",i ,trimmed_map, ft_strlen(trimmed_map));
		if (ft_strlen(trimmed_map) != 0)
		{
			free(trimmed_map);
			return(print_error(ERR_MAP1_MES, ERR_MAP1));
		}
		free(trimmed_map);
	}
	
	return (EXIT_SUCCESS);
}

/**
 * @brief
 * Chequea que el primer elemento de las lineas por debajo de la superior
 * y encima de la inferior sea 1, mediante aritmetica de punteros
 * 
 * @param parsing_str 
 * @return int valor diferente de 0, error
 */

int		map_left_closed(t_pars* parsing_str)
{

	int	i;
	char	*one_side;
	char	*trimmed;
	
	i = parsing_str->nb_line_map;
	while (++i < (int)parsing_str->nb_endline_map)
	{
		//printf("para los laterales string = %s \n", parsing_str->map[i]);
		trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		one_side = ft_strchr(trimmed, ONE);
		if (one_side != trimmed)
		{
			free(trimmed);
			return(print_error(ERR_MAP5_MES, ERR_MAP5));
		}
		free(trimmed);
	}
	return (EXIT_SUCCESS);
}


/**
 * @brief
 * Chequea que el primer elemento de las lineas por debajo de la superior
 * y encima de la inferior sea 1, mediante aritmetica de punteros
 * 
 * @param parsing_str 
 * @return int valor diferente de 0, error
 */

int		map_right_closed(t_pars* parsing_str)
{

	int	i;
	char	*one_side;
	char	*trimmed;
	int		leng_line;
	
	i = parsing_str->nb_line_map;
	while (++i < (int)parsing_str->nb_endline_map)
	{
		trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		leng_line = ft_strlen(trimmed);
		one_side = ft_strrchr(trimmed, ONE);
		if (one_side != trimmed + leng_line - 1)
		{
			free(trimmed);
			return(print_error(ERR_MAP6_MES, ERR_MAP6));
		}
		free(trimmed);
	}
	return (EXIT_SUCCESS);
}



/**
 * @brief 
 * Verificamos que en la linea superior e inferiro todo sea 1
 * Despues llamamos a una funcion que compreube los laterales
 * @param parsing_str 
 * @return int 
 */

int		map_closed(t_pars* parsing_str)
{
	char *trimmed_one;
	size_t leng_trimm;

	trimmed_one = ft_strtrim(parsing_str->map[parsing_str->nb_line_map], ONES_STR);
	leng_trimm = ft_strlen((trimmed_one));
	free(trimmed_one);
	if (leng_trimm)
		return(print_error(ERR_MAP3_MES, ERR_MAP3));
	trimmed_one = ft_strtrim(parsing_str->map[parsing_str->nb_endline_map], ONES_STR);
	leng_trimm = ft_strlen((trimmed_one));
	free(trimmed_one);
	if (leng_trimm)
		return(print_error(ERR_MAP4_MES, ERR_MAP4));
	if (map_left_closed(parsing_str))
		return (ERR_MAP5);
	if (map_right_closed(parsing_str))
		return (ERR_MAP6);
	return (EXIT_SUCCESS);
}
