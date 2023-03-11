/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:08 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/11 16:26:55 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#include "../headers.h"

/* Error messages */
#define ERRNBINP_MES	"Wrong number of inputs\n"
#define USAGE	"Please provide correct format \
<./cube3d> <file>'\n"


/* Error codes return values */

enum	code_error
{
	ERRNBINP = 10,
	DRAFT_MES,
	
};


int	print_error(char *error_msg, int return_val);


#endif