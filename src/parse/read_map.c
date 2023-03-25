/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:16:23 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/25 14:15:43 by fnieves          ###   ########.fr       */
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

int copy_file(t_pars* parsing_str)
{
	int		i;
	char	*line;

	parsing_str->file_inp = open(parsing_str->arg_1, O_RDONLY, CHMOD);
	if (parsing_str->file_inp < 0)
		return(print_error(ERR_OPEN_FILE2 , 1));
	i = 0;
	while (1)
	{
		line = get_next_line(parsing_str->file_inp);
		parsing_str->map[i] = line; 
		i++;
		if (!line)
			break;
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
int	lets_beggin_parse(t_pars* parsing_str)
{
	
	if (read_copy_file (parsing_str) )
		return (EXIT_FAILURE);
	if (check_lines(parsing_str))
		return (EXIT_FAILURE);
	printf("lineas ok. Vamos a ver el map\n");
	if (check_map(parsing_str))
		return (EXIT_FAILURE);
	printf("mapa consistente a bprrar todo y free\n");	
	// el free lo hacemos en parse
	return (EXIT_SUCCESS);
	//como nos aseguramos que había llegado al final de linea y que no ha habido un error cualquiera (lectura)
}

/**
 * @brief 
 * Leemos el archivo para malloquear. Desopu'es podemos copiar toda 
 * la informaci'on en nuestra estructura
 * 
 * @param parsing_str 
 * @return int 
 */

int	read_copy_file(t_pars* parsing_str)
{
	while (1)
	{
		parsing_str->line = get_next_line(parsing_str->file_inp);
		parsing_str->nb_line += 1;
		if (!parsing_str->line)
			break;
		free(parsing_str->line);
	}
	parsing_str->map = ft_calloc(sizeof (*parsing_str->map), parsing_str->nb_line + 1);
	if (!parsing_str->map)
		return (print_error(ERR_MALLO_MES, 1));
	close(parsing_str->file_inp);
	if (copy_file(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
podemos borrao despues
*/
// void draw_copied_map(t_pars* parsing_str) //funcion solo para verificar
// {
	
// 	int i = -1;
// 	while(parsing_str->map[++i])
// 	{
// 		printf("linea de map: %i: %s", i, parsing_str->map[i]);
// 	}
// 	if (!parsing_str->map[i])
// 		printf("\nesto se imprime porque la ultima linea es null\n");
// }
