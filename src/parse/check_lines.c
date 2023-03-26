/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:23:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/26 14:31:52 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Vamos a verficar que los argumentos colores/textura , stén al principio 
 * y podamos abrir los path /colores. No verificamos consistencia de map
 * 
 * @param parsing_str 
 * @param s_splited_cleaned array de elmentos de linea sin espacios
 * @return int 
 */
int	check_arguments(t_pars* parsing_str, char **s_splited_cleaned) //seguir aqui despues cafe
{
	int id;

	id = check_identifier(parsing_str, s_splited_cleaned[0]);
	if (id == 0)
		return(EXIT_FAILURE);
	if (id >= NORTH &&  id <= WEST)
	{
		if (check_textur_path(parsing_str, &s_splited_cleaned[1], id)) 
			return(EXIT_FAILURE); //?
		parsing_str->arg_ok += 1;
	}
	if (id == GROUND ||  id == HEAVEN) //mas facil dividir en 
	{
		if (check_colours(parsing_str, &s_splited_cleaned[1], id)) //verificar qeu solo haya 2 elementos
			return (EXIT_FAILURE);
		parsing_str->arg_ok += 1;
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param parsing_str 
 * @param line_splitd : elemento 0 de la linea , sin espacios 
 * @return int 
 */
int	check_identifier(t_pars* parsing_str, char *line_splitd) 
{
	int i;

	i = -1;
	char	*card_arr[6] = { NORTH_STR, SOUTH_STR, EAST_STR, WEST_STR , HEAVEN_STR , GROUND_STR };
	char	*error_ar[6] = { ERR_REPET_NO,ERR_REPET_SO, ERR_REPET_EA, ERR_REPET_WE, ERR_REPET_F, ERR_REPET_G};
	char 	card_char[6] = { NORTH, SOUTH, EAST, WEST , HEAVEN , GROUND};
	if (parsing_str->arg_ok < 6) //que pasa si tengo todos los argumentos
	{
		while (++i < 6)
		{
			if (!ft_strcmp(line_splitd, card_arr[i])) // si nos llega un punto cardnal 
			{
				if (parsing_str->arra_arg[i] == 0) //y no está repetido
					return(parsing_str->arra_arg[i] = card_char[i]);
				else
					return(print_error(error_ar[i], 0)); //o ya lo teniamos
			}
		}
		return(print_error(ERR_MAP12_MES, 0)); //o ya lo teniamos
	}
	return (MAP);
}

/*
	este file hay que cerrarlo en algun sitio.
	No sé si pasar el path o el file. 
	Preguntar a ANdres. (mejor el path)
*/
int	check_textur_path(t_pars* parsing_str, char **s_splited_cleaned, int id)
{
	int fd;

	if (s_splited_cleaned[1] != NULL)
		return(print_error(ERR_TEXT_INP_MES, ERR_TEXT_INP));
	fd = open(s_splited_cleaned[0], O_RDONLY, CHMOD);
	if (fd < 0)
		return(print_error(ERR_TEXT_PATH_MES, ERR_TEXT_PATH));
	if (id == NORTH)
		parsing_str->north.file = fd;
	else if (id == SOUTH)
		parsing_str->south.file = fd;
	else if (id == EAST)
		parsing_str->east.file = fd;
	else if (id == WEST)
		parsing_str->west.file = fd;
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param parsing_str 
 * @return int 
 */
int	check_lines(t_pars* parsing_str)
{
	int	i;
	char *s_trimmed;
	char **s_splited_cleaned;
	
	i = -1;
	while (parsing_str->map[++i] && parsing_str->arg_ok < 6)
	{
		s_trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if (ft_strlen(s_trimmed)) //en caso contrario hay que hacer free?? no hay nada en la linea
		{
			s_splited_cleaned =  ft_split(s_trimmed, SPACE);
			if (check_arguments(parsing_str, s_splited_cleaned))
			{
				free(s_trimmed);
				free_split(&s_splited_cleaned);
				return (EXIT_FAILURE);
			}
			free_split(&s_splited_cleaned);
		}
		free(s_trimmed);
	}
	if (parsing_str->arg_ok < 6)
		return (print_error(ERR_MAP13_MES, 1));
	parsing_str->nb_line_map = i;
	return (EXIT_SUCCESS);
}
