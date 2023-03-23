/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:01 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/23 12:55:58 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Podemos anadir la estructura para que haga un free. Usar solo calloc. Buscar cada malloc y cambiar
 * podemos cambiar el parametro int por, la estructura y dejar solo mensaje de erorr
 * y devol;ver siempre 1
 * @param error_msg 
 * @param return_val 
 * @return int 
 */

int	print_error(char *error_msg, int return_val)
{
	printf(ERR_MS);
	write(1, error_msg, ft_strlen(error_msg));
	//free_pars()
	return (return_val);
}