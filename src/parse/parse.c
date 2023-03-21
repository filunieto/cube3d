/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/21 16:00:02 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Inicializamos valores en la estructura
 * No sé si habría que iniciliazar los int de RGB, de momento no
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
	parsing_str->nb_endline_map = 0;
	parsing_str->max_leng_line = 0;
	

	// while (++i <= 4) // NO me quedo con esto de los cardinales
	// {
	// 	parsing_str->cardinal[i].name = 0;
	// 	parsing_str->cardinal[i].path = NULL;
	// }
	parsing_str->north.name = 0;
	parsing_str->south.name = 0;
	parsing_str->east.name = 0;
	parsing_str->west.name = 0;
	parsing_str->north.path = NULL;
	parsing_str->south.path = NULL;
	parsing_str->east.path = NULL;
	parsing_str->west.path = NULL;
	
	parsing_str->ground.part = 0;
	parsing_str->ground.r = -1; //creo que estos no hacen falta
	parsing_str->ground.g = -1;
	parsing_str->ground.b = -1;
	parsing_str->heaven.part = 0;
	parsing_str->heaven.r = -1;
	parsing_str->heaven.g = -1;
	parsing_str->heaven.b = -1;
	parsing_str->heaven.rgb = -1;
	parsing_str->ground.rgb = -1;

	parsing_str->arg_ok = 0;
	parsing_str->nb_line_map = 0;
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
	if (leng_s <= 4)
		return (1);
	extension = file + (leng_s - 1) - 3;
	if (ft_strcmp(extension, ".cub"))
		return (1);
	return (EXIT_SUCCESS);
}


/*
//Creo que el prototipo final de la funcion sería como input 
la estructutra generica , y el file de entrada.
y int como salida para verificar el error. (0 si todo va bien )
En los errores usar la misma funcion de salida
*/

/*
	Probelmas. apertura de path a textura
	Hablar on andres para integrar la estructura 
	Buscar función  libft con calloc (ft_split)
*/

char **ft_parse(char *file_mup)
{
	t_pars parsing_str;
	//char **parsed_map;
	
	init_strc_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	if (is_ext_cub(&parsing_str))
	{
		printf("extension no correctan, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	//open file
	parsing_str.arg_1 = file_mup;
	//parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY, CHMOD); //no es necesario
	parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY);
	if (parsing_str.file_inp < 0)
	{
		printf("Problema apertura de archivo, STOP\n"); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
		return (NULL);
	}
	read_file(&parsing_str);
	//printf("extension correctan y archivo abierto, y lectura correcta palante\n");
	close(parsing_str.file_inp);
	//aqui al final puedo pasar todos los parametros de la estructura pars a la  estructura ppal
	// entre ellos estructuras
	return (NULL);

}