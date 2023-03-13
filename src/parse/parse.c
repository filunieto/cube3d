/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/13 19:26:22 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers.h"

/**
 * @brief 
 * Inicializamos valores en la estructura
 * 
 * @param parsing_str 
 */
void	init_strc_pars(t_pars* parsing_str)
{
	parsing_str->arg_1 = NULL;
	parsing_str->error_pars = false;
	parsing_str->map = NULL;
	parsing_str->file_inp = -1;
	parsing_str->line = NULL;
	parsing_str->nb_line = 0;
	parsing_str->max_leng_line = 0;
	
}



/**
 * @brief 
 * Verify that the file extension is .cub
 * and that the extension is at least 4 characters long.
 * We will use pointer arithmetic.
 * 
 * @param parsing_str 
 * @return true:  if file extension is ".cub"
 * @return false: other case
 */
bool is_ext_cub(t_pars* parsing_str)
{
	char *file;
	size_t  leng_s;
	char	*extension;
	
	file = parsing_str->arg_1;
	leng_s =  strlen(file);
	if (leng_s < 4)
		return (false);
	extension = file + (leng_s - 1) - 3;
	//printf("puntero a extension recortada: %s\n", extension);
	if ( strcmp(extension, ".cub")) //libft
		return (false);
	return (true);
}


/**
 * @brief 
 * Función que va a leer todo el archivo y calculara el array de punteros
 * Quiza sería mejor que retornara un int
 * @param parsing_str 
 * @return true 
 * @return false 
 */
bool	read_file(t_pars* parsing_str)
{
	while (1)
	{
		parsing_str->line = get_next_line(parsing_str->file_inp);
		parsing_str->nb_line += 1;
		if (!parsing_str->line)
		{
			break;
		}
		printf("%s", parsing_str->line);
		free(parsing_str->line);
	}
	parsing_str->map = calloc(sizeof (*parsing_str->map), parsing_str->nb_line + 1); //libft
	if (!parsing_str->map)
		return (false); //habría que liberar algo más? (poner un int de output)
	free(parsing_str->map);
	return (true);
	//como nos aseguramos que había llegado al final de linea y que no ha habido un error cualquiera (lectura)
}


char **ft_parse(char *file_mup)
{
	t_pars parsing_str;
	char **parsed_map;
	
	char *para_borrar = "frase test";//para borrar 
	parsed_map = &para_borrar;//para borrar

	init_strc_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	if (!is_ext_cub(&parsing_str))
	{
		printf("extension no correctan, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	//open file
	parsing_str.file_inp = open(file_mup, O_RDONLY, CHMOD);
	if (parsing_str.file_inp < 0)
	{
		printf("Problema apertura de archivo, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	read_file(&parsing_str); //domingo seguimos leyendo el archivo con gnline
	
	printf("extension correctan y archivo abierto, y lectura correcta palante\n");
	close(parsing_str.file_inp);
	return (parsed_map);

}