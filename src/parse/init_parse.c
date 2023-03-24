/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:03:54 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/23 23:54:28 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Inicializamos valores en la estructura
 * No sé si habría que iniciliazar los int de RGB, de momento no
 * @param parsing_str 
 */
void	init_strc_pars(t_pars* parsing_str)
{

	int i = 0;
	while (i)
	{
		parsing_str->arra_arg[i] = 0;
		i++;
	}
	parsing_str->arg_1 = NULL;
	parsing_str->error_pars = false;
	parsing_str->map = NULL;
	parsing_str->file_inp = -1;
	parsing_str->line = NULL;
	parsing_str->nb_line = 0;
	parsing_str->nb_endline_map = 0;
	parsing_str->max_leng_map = 0;


	parsing_str->north.name = 0;
	parsing_str->south.name = 0;
	parsing_str->east.name = 0;
	parsing_str->west.name = 0;
	parsing_str->north.path = NULL;
	parsing_str->south.path = NULL;
	parsing_str->east.path = NULL;
	parsing_str->west.path = NULL;
	
	parsing_str->ground.part = 0;
	parsing_str->ground.r = -1; //creo que estos no hacen falta. Tenemos el entero
	parsing_str->ground.g = -1;
	parsing_str->ground.b = -1;
	parsing_str->heaven.part = 0;
	parsing_str->heaven.r = -1;
	parsing_str->heaven.g = -1;
	parsing_str->heaven.b = -1;
	parsing_str->heaven.rgb = -1;
	parsing_str->ground.rgb = -1;

	parsing_str->arg_ok = 0;
	parsing_str->nb_line_map = 0;
	parsing_str->player = 0;
	parsing_str->map_normal = NULL;
	
}
