/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 18:56:01 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//por hacer . Dividir funcion. Los array declarar en 2 lineas
#include "../../inc/Screen.h"

void	free_parser(t_pars *parsing_str)
{
	free_split(&parsing_str->map);
	free_split(&parsing_str->map_normal);
}

// }
/**
 * @brief 
 * Function which , made the whole process of parsing.
 * At the end it will pass the verified parameters to the main structure. 
 * to continue running the game.
 * 
 * @param file_mup 
 * @return int 
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
		printf(" Algún probelma en la fucnion. Se ha hecho free y salimos\n"); //borrar
		return (EXIT_FAILURE);
	}
	//copy_struct(&parsing_str, t_struc *struct_generic);
	free_parser(&parsing_str);
	printf("acabdo ft_parser Todo ok. .free hecho y seguimos.\n"); //borrar
	return (EXIT_SUCCESS);
}
