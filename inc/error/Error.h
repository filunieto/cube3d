/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:25:08 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/10 15:46:13 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/* Error messages */
// Error number of inputs
#define ERRNBINP_MES	"Wrong number of inputs \
token`newline'\n"
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