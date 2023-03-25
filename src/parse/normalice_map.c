/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalice_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:48 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/25 13:11:45 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * parsing_str->map_normal : se maloquea la longitud más el 0/
 * @param parsing_str 
 * @return int 
 */

int normalize_map(t_pars* parsing_str)
{
	int i;
	int len_mllc;

	len_mllc = parsing_str->nb_endline_map - parsing_str->nb_line_map + 2;
	parsing_str->map_normal = ft_calloc(sizeof(char *), len_mllc);
	if (!parsing_str->map_normal)
		return(print_error(ERR_MALLO_MES, ERR_MALLO));
	i = -1;
	while (++i < len_mllc)
	{
		parsing_str->map_normal[i] = ft_calloc(sizeof(char), parsing_str->max_leng_map); //incluido el nullterm
		if (!parsing_str->map_normal[i])
			return(print_error(ERR_MALLO_MES, ERR_MALLO));
	}
	if (copy_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	copy_map(t_pars* parsing_str)
{
	int line_run;
	//int last_lin;

	line_run = parsing_str->nb_line_map;
	//last_lin = parsing_str->nb_endline_map;
	while(line_run <= (int)parsing_str->nb_endline_map)
	{
		copy_char(parsing_str, line_run);
		line_run++;
	}
	return (EXIT_SUCCESS);
}

//Esta fincion está dando probelmas cuando hay espacios o tabuladores encima dle map. Verificar la primer alínea. Ni zorra que pasa
void	copy_char(t_pars* parsing_str, int line_run) //esta funcion puedes ser un void
{
	size_t i;
	char *map;
	char *map_norml;
	
	map = parsing_str->map[line_run];
	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
	i = -1;
	//printf("Principio de copy char: entra la linea %i. |%s|\n, ",line_run + 1, map);
	//printf("\nPrincipio de copy char: entra la linea %i.len= %zu,  |%s|, \n, ",line_run + 1,ft_strlen(map),  map );	
	//printf("\nPrincipio de copy char: entra la linea %i.len= %zu,  |%s|, \n , Calloc |%s|\n",line_run + 1,ft_strlen(map),  map , map_norml);
	while (++i < ft_strlen(map) - 1) //no consideramos 
	{
		//printf("map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
		//printf ("indice i %zu en primer  while\n", i);
		if (map[i] == SPACE || map[i] == EOL)
			map_norml[i] = PT;
		else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
			map_norml[i] =  map[i];
		else
			printf("caracter raro residual %c\n", map[i]);
	
	}
	//printf("len= %zu y longitud maxima mapa %zu\n", ft_strlen(map), parsing_str->max_leng_map);
	//printf("Iterador antes %zu\n",i);
	while (i < parsing_str->max_leng_map)
	{
		//printf ("indice i %zu en segundo  while\n", i);
		map_norml[i] = PT;
		i++;
	}
	//printf(" final en copy char: linea del mapa_nomrliazado %lu. |%s|\n, ",line_run - parsing_str->nb_line_map, map_norml);
	//printf("longitud %zu,", ft_strlen(map_norml));
	//printf("Iterador despues  %zu\n",i);
	//printf("%s\n", map_norml);
}


int	char_per_char_map(t_pars* parsing_str)
{
	int i;
	int j;
	//char c;

	i = -1;
	while (parsing_str->map_normal[++i])
	{
		j = -1;
		while (parsing_str->map_normal[i][++j])
		{
			if (parsing_str->map_normal[i][j] == '0' || parsing_str->map_normal[i][j] == parsing_str->player) //creo que hay que añadir el player, además dle 0
			{
				if (check_around(parsing_str, i , j)) //si encuentra un space alrededor que devuelva int
					return(EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

//	printf("linea inicio: %zu , liena final %zu, max leng %zu\n",
// parsing_str->nb_line_map, parsing_str->nb_endline_map ,parsing_str->max_leng_map );
int	check_around(t_pars* parsing_str, int i , int j)
{
	if (i == 0)
		return(print_error(ERR_MAP3_MES, ERR_MAP3));
	if (i == (int)(parsing_str->nb_endline_map - parsing_str->nb_line_map))
		return(print_error(ERR_MAP4_MES, ERR_MAP4));
	if (j == 0)
		return(print_error(ERR_MAP5_MES, ERR_MAP5)); 
	if (j == (int)parsing_str->max_leng_map - 1)
		return(print_error(ERR_MAP6_MES, ERR_MAP6));
	if (parsing_str->map_normal[i - 1][j] == PT || parsing_str->map_normal[i][j - 1] == PT || 
	parsing_str->map_normal[i][j + 1] == PT || parsing_str->map_normal[i + 1][j] == PT)
		return(print_error(ERR_MAP2_MES, ERR_MAP2));
	return (EXIT_SUCCESS);
}