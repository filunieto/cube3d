/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:57 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/29 12:23:11 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

// # include "../Screen.h"

# define CHMOD		0644
# define SPACE_STR		" \t\n"
# define NORTH_STR		"NO"
# define SOUTH_STR		"SO"
# define EAST_STR		"EA"
# define WEST_STR		"WE"
# define HEAVEN_STR 	"C"
# define GROUND_STR		"F"
# define MAP_STR		" 01NSEW\n"
# define NO_PLAYER_STR		" 01\n"
# define ONES_STR		" 1\n"
# define ONE			'1'
# define PLAYER_N		'N'
# define PLAYER_S		'S'
# define PLAYER_E		'E'
# define PLAYER_W		'W'
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
# define PT	' '
# define SPACE	' '
# define EOL	'\n'

typedef struct s_textur
{
	char	*path;
}	t_textur;

typedef struct s_colour
{
	int		rgb;
}	t_colour;

typedef struct s_pars
{
	char		**map;
	char		**map_normal;
	char		*arg_1;
	int			file_inp;
	char		*line;
	int			arg_ok;
	size_t		nb_line_map;
	size_t		nb_endline_map;
	size_t		nb_line;
	size_t		max_leng_map;
	char		player;
	t_textur	north;
	t_textur	south;
	t_textur	east;
	t_textur	west;
	t_colour	heaven;
	t_colour	ground;
	int			arra_arg[6];
}	t_pars;

//src/parse/parse.c
int		ft_parse(char *file_mup, t_pars *parsing_str);
void	free_parser(t_pars *parsing_str);

//src/parse/init_parse.c
void	init_pars(t_pars *parsing_str);
void	init_pars_arr(t_pars *parsing_str);

//src/parse/parse_tools.c
int		is_ext_cub(t_pars *parsing_str);
//int		ft_strcmp(char *s1, char *s2);
int		free_split_rgb(char ***rgb, char *message);
void	free_split(char ***s_splitted);

//src/parse/read_map.c
int		lets_beggin_parse(t_pars *parsing_str);
int		read_copy_file(t_pars *parsing_str);
int		copy_file(t_pars *parsing_str);

//src/parse/check_lines.c
int		check_lines(t_pars *parsing_str);
int		check_arguments(t_pars *parsing_str, char **s_splited_cleaned);
int		check_identifier(t_pars *parsing_str, char *line_splitd);
int		check_textur_path(t_pars *parsing_str,
			char **s_splited_cleaned, int id);

//src/parse/check_map.c
int		check_map(t_pars *parsing_str);
int		is_map_consistent(t_pars *parsing_str);
int		find_end(t_pars *parsing_str);
int		find_init(t_pars *parsing_str);
int		find_max_line(t_pars *parsing_str);

//src/parse/check_rgb.c
int		check_colours(t_pars *parsing_str, char **s_splited_cleaned, int id);
int		check_values_rgb(t_pars *parsing_str, char ***rgb, int id);

//src/parse/normalice_map.c
int		normalize_map(t_pars *parsing_str);
int		copy_map(t_pars *parsing_str);
int		print_error(char *error_msg, int return_val);
int		copy_char1(t_pars *parsing_str, int line_run);
int		copy_char2(t_pars *parsing_str, int line_run);

//src/parse/map_consistence.c
int		map_closed(t_pars *parsing_str);
int		map_char(t_pars *parsing_str);
int		char_per_char_map(t_pars *parsing_str);
int		check_around(t_pars *parsing_str, int i, int j);

//src/parse/map_one_player.c
int		one_player(t_pars *parsing_str);
void	define_cardinal(char **card_arr);
void	define_error(char **error_ar);
void	define_card_char(char *card_char);
void	draw_normalize2(t_pars *parsing_str);

#endif
