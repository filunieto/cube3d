/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/28 10:48:04 by fnieves-         ###   ########.fr       */
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
	atexit(check_leaks);
	if (ft_parse(argv[1])) //PASAR LA ESTRUCTURA GENERAL DE ANDRES, previa inicialización
		return (EXIT_FAILURE);
	/* FElipe */
	//init_window();
	return (EXIT_SUCCESS);
}
