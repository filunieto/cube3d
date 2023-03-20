/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/20 13:05:54 by fnieves          ###   ########.fr       */
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
	{
		printf("imprimir error  de mensaje. argumentos incoorrectos"); //se puede poner en una sola línea esta función
		return (1);
	}
	ft_parse(argv[1]);
	
	/* FElipe */
	//init_window();
	//atexit(check_leaks);
	return (0);
}
