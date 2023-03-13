/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/13 13:08:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/headers.h"

/**
 * @brief 
 * 
 */

void	check_leaks(void)
{
	system("leaks -q cub3d");
}

/**
 * @brief 
 * Funcion de error, imprima y devuelva algún valor: return (error_print) (tipo hoomen)
 
 * Hacer una estructura (donde llevaremos el file).
 Inicializamos lo que necesitemos en la estructura y si , algo falla pasamos el parametro a null , para despues comprobar si ha habido 
 algún problmea 
 
 *Abrir archivos :
	Comprobar que la extension sea .cub
	Hay que verificar cada linea NO, SO, F, C y el mapa

Para Andres. Dejar todo listo y funcionando en la estructira del programa
	
 * @param argc 
 * @param argv 
 * @return int 
 */


int	main(int argc, char** argv)
{
	/* FElipe */
	char **map;
	// declarar una variable char **map , y si ok se le as
	if (argc != 2)
		return(print_error(ERRNBINP_MES, ERRNBINP));
	//map = ft_parse(argv[1]); //check_parse : return NULL (e imprime mensaje  especifico) si alguna parte no cuadra. En otro caso retorna el array de arrays en el formato necesario
	map = ft_parse(argv[1]);
	if (map == NULL) 
		return(print_error(ERR_MAP_INPT_MES, ERR_MAP_INPT));


	/* **************************** */
	/* Andres */
	// init_window();
	atexit(check_leaks);
	return (0);
}
