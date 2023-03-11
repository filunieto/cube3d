/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/11 17:05:17 by fnieves-         ###   ########.fr       */
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
 * @param argc 
 * @param argv 
 * @return int 
 */


int	main(int argc, char** argv)
{
	/* FElipe */
	if (argc != 2)
		return(print_error(ERRNBINP_MES, ERRNBINP));

	ft_parse(argv[1]);
	/* **************************** */
	/* Andres */
	// init_window();
	//atexit(check_leaks);
	return (0);
}
