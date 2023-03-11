/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/11 20:58:17 by fnieves-         ###   ########.fr       */
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
 * 
 * @param parsing_str 
 * @return true 
 * @return false 
 */
bool	read_file(t_pars* parsing_str)
{
	
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
	read_file(&parsing_str); //domingo seguimos leyendo el archivo con gnline
	printf("extension correctan, palante\n");
	return (parsed_map);
	
}