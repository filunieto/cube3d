/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/16 20:30:03 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

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
	parsing_str->north = 0;
	parsing_str->south = 0;
	parsing_str->east = 0;
	parsing_str->west = 0;
	parsing_str->ground = 0;
	parsing_str->heaven = 0;
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
int  is_ext_cub(t_pars* parsing_str)
{
	char *file;
	size_t  leng_s;
	char	*extension;
	
	file = parsing_str->arg_1;
	leng_s =  strlen(file);
	if (leng_s < 4)
		return (0);
	extension = file + (leng_s - 1) - 3;
	if ( strcmp(extension, ".cub"))
		return (0);
	return (1);
}



//cuidado con el file qu elo estoy abriendo siempre por el findla
char **ft_parse(char *file_mup)
{
	t_pars parsing_str;
	//char **parsed_map;
	

	
	init_strc_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	if (!is_ext_cub(&parsing_str))
	{
		printf("extension no correctan, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	//open file
	parsing_str.arg_1 = file_mup;
	parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY, CHMOD);
	if (parsing_str.file_inp < 0)
	{
		printf("Problema apertura de archivo, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	read_file(&parsing_str); //domingo seguimos leyendo el archivo con gnline

	printf("extension correctan y archivo abierto, y lectura correcta palante\n");
	close(parsing_str.file_inp);
	return (NULL);

}