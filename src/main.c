/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/26 17:17:41 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/Screen.h"

void	check_leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int argc, char** argv)
{
	/* FElipe */
	//(void) argv;
	if (argc != 2)
		return (print_error(ERRNBINP_MES, ERRNBINP));
	if (ft_parse(argv[1])) //PASAR LA ESTRUCTURA GENERAL DE ANDRES, previa inicialización
		return (EXIT_FAILURE);
	/* FElipe */
	//init_window();
	//atexit(check_leaks);
	return (EXIT_SUCCESS);
}
