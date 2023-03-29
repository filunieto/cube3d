/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:48 by anramire          #+#    #+#             */
/*   Updated: 2023/03/29 12:37:05 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../inc/Screen.h"

void	check_leaks(void)
{
	system("leaks -q cub3d");
}

int	main(int argc, char **argv)
{
	t_pars	parsing_str;

	if (argc != 2)
		return (print_error(ERRNBINP_MES, ERRNBINP));
	if (ft_parse(argv[1], &parsing_str))
		return (EXIT_FAILURE);
	init_window(&parsing_str);
	return (EXIT_SUCCESS);
}
