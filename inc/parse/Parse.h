/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:57 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/12 19:43:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../headers.h"

typedef struct s_pars
{
	char **map;
	bool error_pars;
	char *arg_1;
	int file_inp;
}	t_pars;


char **	ft_parse(char *file_mup);
void	init_strc_pars(t_pars* parsing_str);



#endif