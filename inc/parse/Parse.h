/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:57 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/13 20:01:53 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../Screen.h"

# define CHMOD		0644

typedef struct s_pars
{
	char **map;
	bool error_pars;
	char *arg_1;
	int	file_inp;
	char *line;
	size_t	nb_line;
	size_t	max_leng_line;
}	t_pars;


char	**ft_parse(char *file_mup);
void	init_strc_pars(t_pars* parsing_str);
bool	is_ext_cub(t_pars* parsing_str);
bool	read_file(t_pars* parsing_str); //seria necesario NULL



#endif