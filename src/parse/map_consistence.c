/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_consistence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/27 15:46:21 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

//en  esta funcion cuando la usamos , en la ultima linea intenamos acceder a algo que no podemos
//revisar con mapas con 2 islas, y en char per char. Será la /n?
//no debería entrar en al última fila
 void draw_normalize(t_pars* parsing_str)
{
	int i = 0;

	while (parsing_str->map_normal[i])
	{
		printf("%s\n",parsing_str->map_normal[i] );
		i++;
	}
	printf("\n");
}

 void draw_normalize2(t_pars* parsing_str)
{
	int i = 0;
	int j;

	while (parsing_str->map_normal[i])
	{
		j = 0;
		while (parsing_str->map_normal[i][j])
		{
			printf("%c", parsing_str->map_normal[i][j]);
			j++;
		}
		printf("\n");
		//printf("Fila %i	:%s\n",i,parsing_str->map_normal[i] );
		i++;
	}
	//printf("\n");
}

//una vez aquí: Solo hay un jugador y todos los caracteres son correctos en el mapa
int		map_closed(t_pars* parsing_str) //hay que verificar que denajo de un 1 siempre haya otro 1 
{
	if (normalize_map(parsing_str))
		return (EXIT_FAILURE);
	//draw_normalize(parsing_str);
	//draw_normalize2(parsing_str);
	//printf("despues de draw\n");	
	if (char_per_char_map(parsing_str)) //aqui me esta dando algo
		return (EXIT_FAILURE);
	//printf("segmentatin fault after che per char\n");	
	return (EXIT_SUCCESS);
}




/**
 * @brief 
 * Esta función verifica que solo tengamos los caracteres 1 , 0, W
 * E, W, N.
 * 
 * @param parsing_str 
 * @return int 0 sí los caracteres son corretcos
 * otro valor en caso contrario
 */

int		map_char(t_pars* parsing_str)
{
	char	*trimmed_map;
	int		i;

	i = parsing_str->nb_line_map; //le restamos par aahorrar en lineas y emprezar desde -1
	while (i <= (int)parsing_str->nb_endline_map)
	{
		trimmed_map = ft_strtrim(parsing_str->map[i], MAP_STR);
		if (ft_strlen(trimmed_map) != 0)
		{
			free(trimmed_map);
			return(print_error(ERR_MAP1_MES, ERR_MAP1));
		}
		free(trimmed_map);
		i++;
	}
	return (EXIT_SUCCESS);
}



int	char_per_char_map(t_pars* parsing_str) //verificar donde entra
{
	int i;
	int j;

	i = -1;
	//printf("char_per_char_map 1\n");	

	while (parsing_str->map_normal[++i])
	{
		j = -1;
		while (parsing_str->map_normal[i][++j])
		{
			if (parsing_str->map_normal[i][j] == '0' 
			|| parsing_str->map_normal[i][j] == parsing_str->player) //creo que hay que añadir el player, además dle 0
				if (check_around(parsing_str, i , j)) //si encuentra un space alrededor que devuelva int
					return(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

//	printf("linea inicio: %zu , liena final %zu, max leng %zu\n",
// parsing_str->nb_line_map, parsing_str->nb_endline_map ,parsing_str->max_leng_map );
int	check_around(t_pars* parsing_str, int i , int j) //comprobar aqui los seg fault , punto por punto. Entra donde no debe? sabado 25 mar
{
	//printf("check around: punto i %i, j %i y char %c \n", i , j, parsing_str->map_normal[i][j]);	
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