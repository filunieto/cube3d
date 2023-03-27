/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalice_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:48 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/27 15:34:15 by fnieves          ###   ########.fr       */
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
	//printf("leng de malloc para el map _norm: %i\n", len_mllc);
	parsing_str->map_normal = ft_calloc(sizeof(char *), len_mllc);
	if (!parsing_str->map_normal)
		return(print_error(ERR_MALLO_MES, ERR_MALLO));
	i = -1;
	while (++i < len_mllc - 1)
	{
		parsing_str->map_normal[i] = ft_calloc(sizeof(char), parsing_str->max_leng_map); //incluido el nullterm
		if (!parsing_str->map_normal[i])
			return(print_error(ERR_MALLO_MES, ERR_MALLO));
	}
	parsing_str->map_normal[i] = NULL;
	if (copy_map(parsing_str))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	copy_map(t_pars* parsing_str)
{
	int line_run;

	line_run = parsing_str->nb_line_map;
	while(line_run <= (int)parsing_str->nb_endline_map)
	{
		copy_char(parsing_str, line_run);
		line_run++;
	}
	return (EXIT_SUCCESS);
}

//Esta fincion está dando probelmas cuando hay espacios o tabuladores encima dle map. Verificar la primer alínea. Ni zorra que pasa
//funcion que da probelmas : si acabamos en la ultima linea sin EOF. Mirar en MAc
void	copy_char(t_pars* parsing_str, int line_run) //esta funcion puedes ser un void
{
	size_t i;
	char *map;
	char *map_norml;
	
	map = parsing_str->map[line_run];
	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
	i = -1;
	// si la longitud maxima (con \n) es menor que las lineas maximas. Vamos copiando todo y si encuentra salto de linea o nada o espacio va ellenando con puntos
	if (ft_strlen(map) < parsing_str->max_leng_map + 1) //ambas miembros incluyen salto de linea
	{
		while (++i < ft_strlen(map))
		{
			if (map[i] == SPACE || map[i] == EOL)
				map_norml[i] = PT;
			else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
				map_norml[i] =  map[i];
		}
		while (i < parsing_str->max_leng_map)
		{
			// printf(" Lineas mayor que max:map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
			// printf ("indice %zu en de linea %u \n", i, line_run);
			map_norml[i] = PT;
			i++;
		}
		map_norml[++i] = 0;
	}
	else
	{
		while (++i < parsing_str->max_leng_map)
		{
			if (map[i] == SPACE)
				map_norml[i] = PT;
			else
				map_norml[i] = map[i];
		}
		map[i] = 0;
	}
	//printf("Principio de copy char: entra la linea %i. |%s|\n, ",line_run + 1, map);
	// //printf("\nPrincipio de copy char: entra la linea %i.len= %zu,  |%s|, \n, ",line_run + 1,ft_strlen(map),  map );	
	// //printf("\nPrincipio de copy char: entra la linea %i.len= %zu,  |%s|, \n , Calloc |%s|\n",line_run + 1,ft_strlen(map),  map , map_norml);
	// while (++i < ft_strlen(map) && ft_strlen(map) != parsing_str->max_leng_map) //cuidado aiqo
	// {
	// 	// if (i > ft_strlen(map) - 3 && line_run > (int) parsing_str->nb_endline_map - 1)
	// 	// {
	// 	// 	printf(" 1er while:map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
	// 	// 	printf ("indice %zu en de linea %u \n", i, line_run);
	// 	// }
	// 	if (map[i] == SPACE || map[i] == EOL)
	// 		map_norml[i] = PT;
	// 	else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
	// 		map_norml[i] =  map[i];
	// 	else
	// 		printf("caracter raro residual %c\n", map[i]);
	
	// }
	// //printf("len= %zu y longitud maxima mapa %zu\n", ft_strlen(map), parsing_str->max_leng_map);
	// //printf("Iterador antes %zu\n",i);
	// while (i < parsing_str->max_leng_map)
	// {
	// 	if (i > parsing_str->max_leng_map - 2 && line_run > (int) parsing_str->nb_endline_map - 1)
	// 	{
	// 		printf("2 o while: map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
	// 		printf ("indice %zu en de linea %u \n", i, line_run);
	// 	}
	// 	//printf ("indice i %zu en segundo  while\n", i);
	// 	 //esto es lo que eestaba
	// 	// if (map[i] == SPACE || map[i] == EOL || !map[i] )
	// 	// 	map_norml[i] = PT;
	// 	// else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
	// 	// 	map_norml[i] =  map[i];
	// 	i++;
	// }
	// //printf(" final en copy char: linea del mapa_nomrliazado %lu. |%s|\n, ",line_run - parsing_str->nb_line_map, map_norml);
	// //printf("longitud %zu,", ft_strlen(map_norml));
	// //printf("Iterador despues  %zu\n",i);
	// //printf("%s\n", map_norml);
}


// void	copy_char3(t_pars* parsing_str, int line_run) //esta funcion puedes ser un void
// {
// 	int i;
// 	char *map;
// 	char *map_norml;
	
// 	map = parsing_str->map[line_run];
// 	map_norml = parsing_str->map_normal[line_run - parsing_str->nb_line_map];
// 	i = -1;
// 	while (++i < ft_strlen(map) - 1) //cuidado aiqo
// 	{
// 		if (i > ft_strlen(map) - 3 && line_run > (int) parsing_str->nb_endline_map - 1)
// 		{
// 			printf(" 1er while:map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
// 			printf ("indice %zu en de linea %u \n", i, line_run);
// 		}
// 		if (map[i] == SPACE || map[i] == EOL)
// 			map_norml[i] = PT;
// 		else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
// 			map_norml[i] =  map[i];
// 		else
// 			printf("caracter raro residual %c\n", map[i]);
	
// 	}
// 	while (i < parsing_str->max_leng_map)
// 	{
// 		if (i > parsing_str->max_leng_map - 2 && line_run > (int) parsing_str->nb_endline_map - 1)
// 		{
// 			printf("2 o while: map[i] %c, map_norml[i] \n%c" ,map[i] , map_norml[i]);
// 			printf ("indice %zu en de linea %u \n", i, line_run);
// 		}
// 		//printf ("indice i %zu en segundo  while\n", i);
// 		//map_norml[i] = PT; esto es lo que eestaba
// 		if (map[i] == SPACE || map[i] == EOL || !map[i] )
// 			map_norml[i] = PT;
// 		else if (map[i] == '1' || map[i] == '0' || map[i] == parsing_str->player)
// 			map_norml[i] =  map[i];
// 		i++;
// 	}
// }