/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:01 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/18 17:20:49 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/*
	en general , hagamos las funciones como caso de exito el retorno será 0, sino otro valor
*/

int	print_error(char *error_msg, int return_val)
{
	printf(ERR_MS);
	write(1, error_msg, ft_strlen(error_msg)); //cambiar la funcion a ft_strnlen libft
	// printf(USAGE); no hace falta
	return (return_val);
}