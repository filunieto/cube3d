/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:01 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/10 16:20:28 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/headers.h"

int	print_error(char *error_msg, int return_val)
{
	//printf(error_msg);
	write(1, error_msg, strlen(error_msg)); //cambiar la funcion a ft_strnlen
	// printf(USAGE);
	return (return_val);
}