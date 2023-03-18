/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:08 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/18 17:13:28 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "../Screen.h"

/* Error messages */
#define ERR_MS "Error\n"
#define ERRNBINP_MES	"Wrong number of inputs\n" //añadir mensaje de Usage si es necesario para tener una funcion generica
#define USAGE	"Please provide correct format \
<./cube3d> <file>'\n"

#define ERR_MAP_INPT_MES	"The input map , has a problem \
as above message indicates'\n"

/* Error codes return values */

enum	code_error
{
	ERRNBINP = 10,
	ERR_MAP_INPT ,
	DRAFT,

};


int	print_error(char *error_msg, int return_val);


#endif