/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/27 00:55:24 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

void	free_parser(t_pars *parsing_str)
{
	free_split(&parsing_str->map);
	free_split(&parsing_str->map_normal);
}


/*
//Creo que el prototipo final de la funcion sería como input 
la estructutra generica , y el file de entrada.
y int como salida para verificar el error. (0 si todo va bien )
En los errores usar la misma funcion de salida
*/

/*
	Hablar on andres para integrar la estructura 
	Error cuando no hay mapa o el mapa está al principiop 
	Andres , hace free de su estructura prinicpal?
	usar strdup para copiar los paths si necesario a Andres
	Hacer un close del file si no est á hecho >>> creo que ok
	verifcar el reporte de valgrind 
	añadir la estructura generica de Andres como input
*/

int	ft_parse(char *file_mup)
{
	t_pars	parsing_str;

	init_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	if (is_ext_cub(&parsing_str))
		return (EXIT_FAILURE);
	parsing_str.arg_1 = file_mup;
	parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY);
	if (parsing_str.file_inp < 0)
		return (print_error(ERR_OPEN_FILE, 1));
	if (lets_beggin_parse(&parsing_str))
	{
		free_parser(&parsing_str);
		printf(" ha habido cualquier fallo en lets parser. ESte mensaje tiene que imprimirse siempre. significa qu epodemos hacer free.\n");
		return (EXIT_FAILURE);
	}
	//Antes  dle free funcion   primero para copiatr datos entre las estructuras
	free_parser(&parsing_str);
	printf("acabdo ft_parser .y free hecho.\n");
	return (EXIT_SUCCESS);
}