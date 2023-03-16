/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:57 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/16 20:03:20 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../Screen.h"

# define CHMOD		0644
# define SPACE_STR		" \t"
# define SPACE		' '
# define NORTH		"NO"
# define SOUTH		"SO"
# define EAST		"EA"
# define WEST		"WE"
# define HEAVEN 	"H"
# define GROUND		"G"

typedef struct s_pars
{
	char	**map;
	bool	error_pars;
	char	*arg_1;
	int		file_inp;
	char 	*line;
	size_t	nb_line;
	size_t	max_leng_line;
	int		north;
	int		south;
	int		east;
	int		west;
	int		heaven;
	int		ground;
}	t_pars;


char	**ft_parse(char *file_mup);
void	init_strc_pars(t_pars* parsing_str);
int		is_ext_cub(t_pars* parsing_str);
int		read_file(t_pars* parsing_str); //seria necesario NULL
int		check_lines(t_pars* parsing_str);




#endif