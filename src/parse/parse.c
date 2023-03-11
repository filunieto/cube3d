/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:58 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/11 16:25:06 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers.h"

/**
 * @brief 
 * Inicializamos valores en la estructura
 * 
 * @param parsing_str 
 */
void	init_strc_pars(t_pars* parsing_str)
{
	parsing_str->arg_1 = NULL;
	parsing_str->error_pars = false;
	parsing_str->map = NULL;
}

void ft_parse(char *file_mup)
{
	t_pars parsing_str;

	init_strc_pars(&parsing_str);
	parsing_str.arg_1 = file_mup;
	printf("aqui hacemos el parser\n");
}