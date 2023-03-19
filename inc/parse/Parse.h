/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:57 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/19 22:30:31 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../Screen.h"

# define CHMOD		0644
# define SPACE_STR		" \t\n"
# define SPACE		' '
# define NORTH_STR		"NO"
# define SOUTH_STR		"SO"
# define EAST_STR		"EA"
# define WEST_STR		"WE"
# define HEAVEN_STR 	"C"
# define GROUND_STR		"F"
# define MAP_STR		"01NSEW"

# define CARDINALS		"NSEW"
# define TEXTURE		"HG"
# define NORTH		1
# define SOUTH		2
# define EAST		3
# define WEST		4
# define HEAVEN 	5
# define GROUND		6
# define MAP		7

# define COMMA	','

// enum	code_error
// {
// 	ERRNBINP = 10,
// 	ERR_MAP_INPT ,
// 	DRAFT,

// };

typedef struct s_textur
{
	int		name;
	char	*path;
	int		file;
}	t_textur;


typedef struct s_colour
{
	int		part;
	int		r;
	int		g;
	int 	b;
}	t_colour;

typedef struct s_pars
{
	char	**map;
	bool	error_pars;
	char	*arg_1;
	int		file_inp;
	char 	*line;
	int		arg_ok;
	size_t	nb_line_map;
	size_t	nb_line;
	size_t	max_leng_line;
	//t_textur	cardinal[4]; No me hace falta
	t_textur	north;
	t_textur	south;
	t_textur	east;
	t_textur	west;
	t_colour	heaven; //inicializar los char a 0
	t_colour	ground;
}	t_pars;




char	**ft_parse(char *file_mup);
void	init_strc_pars(t_pars* parsing_str);
int		is_ext_cub(t_pars* parsing_str);
int		read_file(t_pars* parsing_str); //seria necesario NULL
int		check_lines(t_pars* parsing_str);
int		check_arguments(t_pars* parsing_str, char **s_splited_cleaned);
int		check_identifier(t_pars* parsing_str, char *line_splitd);
int		check_textur_path(t_pars* parsing_str, char **s_splited_cleaned, int id);
int		check_colours(t_pars* parsing_str, char **s_splited_cleaned, int id);
int		check_values_rgb(t_pars* parsing_str, char ***rgb, int id);



int	ft_strcmp(char *s1, char *s2);






#endif