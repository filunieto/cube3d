/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:16:23 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/27 01:05:46 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"




/**
 * @brief 
 * Una vez tenemos reservado el espacio, podemos copiar el archivo
 * en nuestra estructura.
 * @param parsing_str 
 * @return int 
 */

int	copy_file(t_pars *parsing_str)
{
	int		i;
	char	*line;

	parsing_str->file_inp = open(parsing_str->arg_1, O_RDONLY, CHMOD);
	if (parsing_str->file_inp < 0)
		return (print_error(ERR_OPEN_FILE2, 1));
	i = 0;
	while (1)
	{
		line = get_next_line(parsing_str->file_inp);
		parsing_str->map[i] = line;
		i++;
		if (!line)
			break ;
		line = NULL;
	}
	close(parsing_str->file_inp);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * Función que va a leer todo el archivo y calculara el array de punteros
 * Quiza sería mejor que retornara un int
 * @param parsing_str 
 */
int	lets_beggin_parse(t_pars *parsing_str)
{
	if (read_copy_file (parsing_str))
		return (EXIT_FAILURE);
	if (check_lines(parsing_str))
		return (EXIT_FAILURE);
	if (check_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * Leemos el archivo para malloquear. Desopu'es podemos copiar toda 
 * la informaci'on en nuestra estructura
 * 
 * @param parsing_str 
 * @return int 
 */

int	read_copy_file(t_pars *parsing_str)
{
	while (1)
	{
		parsing_str->line = get_next_line(parsing_str->file_inp);
		parsing_str->nb_line += 1;
		if (!parsing_str->line)
			break ;
		free(parsing_str->line);
	}
	close(parsing_str->file_inp);
	parsing_str->map = ft_calloc(sizeof (*parsing_str->map),
			parsing_str->nb_line + 1);
	if (!parsing_str->map)
		return (print_error(ERR_MALLO_MES, 1));
	if (copy_file(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
