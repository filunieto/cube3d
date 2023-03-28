/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:03:54 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 18:05:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

void	init_pars_arr(t_pars *parsing_str)
{
	parsing_str->arg_1 = NULL;
	parsing_str->error_pars = false;
	parsing_str->map = NULL;
	parsing_str->file_inp = -1;
	parsing_str->line = NULL;
	parsing_str->nb_line = 0;
	parsing_str->nb_endline_map = 0;
	parsing_str->max_leng_map = 0;
	parsing_str->arg_ok = 0;
	parsing_str->nb_line_map = 0;
	parsing_str->player = 0;
	parsing_str->map_normal = NULL;
}

void	init_pars(t_pars *parsing_str)
{
	init_pars_arr(parsing_str);
	parsing_str->north.path = NULL;
	parsing_str->south.path = NULL;
	parsing_str->east.path = NULL;
	parsing_str->west.path = NULL;
	parsing_str->heaven.rgb = -1;
	parsing_str->ground.rgb = -1;
	parsing_str->arra_arg[0] = 0;
	parsing_str->arra_arg[1] = 0;
	parsing_str->arra_arg[2] = 0;
	parsing_str->arra_arg[3] = 0;
	parsing_str->arra_arg[4] = 0;
	parsing_str->arra_arg[5] = 0;
}
