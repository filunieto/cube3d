/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:01 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 11:22:58 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * @param error_msg 
 * @param return_val 
 * @return int 
 */

int	print_error(char *error_msg, int return_val)
{
	write(2, ERR_MS, 6);
	write(2, error_msg, ft_strlen(error_msg));
	return (return_val);
}
