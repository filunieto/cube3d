/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/10 16:16:58 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/headers.h"

/**
 * @brief 
 * 
 */

void	check_leaks(void)
{
	system("leaks -q ./cub3d");
}

/**
 * @brief 
 * Funcion de error, imprima y devuelva algún valor: return (error_print) (tipo hoomen)
 
 * Hacer una estructura (donde llevaremos el file).
 Inicializamos lo que necesitemos en la estructura y si , algo falla pasamos el parametro a null , para despues comprobar si ha habido 
 algún problmea 
 
 *Abrir archivos : contar líneas ... 
 * @param argc 
 * @param argv 
 * @return int 
 */


int	main(int argc, char** argv)
{
	/* FElipe */
	
	if (argc != 2)
	{

		printf("imprimir error  de mensaje. Este no pertenece a la función.  argumentos incoorrectos"); //se puede poner en una sola línea esta función
		print_error(ERRNBINP_MES, ERRNBINP);
	}
	argv[1] = NULL;
	//ft_parse(argv[1]);
	
	/* FElipe */
	
	// init_window();
	atexit(check_leaks);
	return (0);
}
