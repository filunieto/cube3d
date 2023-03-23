/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/23 13:56:10 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"



/*
//Creo que el prototipo final de la funcion sería como input 
la estructutra generica , y el file de entrada.
y int como salida para verificar el error. (0 si todo va bien )
En los errores usar la misma funcion de salida
*/

/*
	Probelmas. apertura de path a textura
	Verificar extension
	Hablar on andres para integrar la estructura 
	Error cuando no hay mapa o el mapa está al principiop 
	REpasar. los free y leaks

*/

int	ft_parse(char *file_mup)
{
	t_pars parsing_str;

	init_strc_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	if (is_ext_cub(&parsing_str))
		return (EXIT_FAILURE);
	parsing_str.arg_1 = file_mup;
	//parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY, CHMOD); //no es necesario
	parsing_str.file_inp = open(parsing_str.arg_1, O_RDONLY);
	if (parsing_str.file_inp < 0)
		return (print_error(ERR_OPEN_FILE, 1));
	lets_beggin_parse(&parsing_str);
	//Aqiu hay que gacer un free de todo , ya que todo salio bien , pero primero hay que copiatr datos entre las estructuras
	return (EXIT_SUCCESS);
}