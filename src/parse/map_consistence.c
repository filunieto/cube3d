/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_consistence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:29:19 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/22 17:44:30 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

// int		map_upper_closed(t_pars* parsing_str)
// {
// 	int	j;
// 	int leng;
// 	char *line_1;
// 	char *line_2;

// 	j = 0;
// 	leng = parsing_str->max_leng_map;
// 	line_1 = parsing_str->map[parsing_str->nb_line_map];
// 	line_2 = parsing_str->map[parsing_str->nb_line_map + 1];
// 	if (line_1[j] == '0')
// 		if (line_2[j] != '1'  || line_1[j + 1] != '1')
// 			return(print_error(ERR_MAP3_MES, ERR_MAP3));
// 	if (line_1[j + leng - 1] == '0') //se supone que estamos en un caracter antes del \n, por eso restamos 1 (0 +len)
// 		if (line_2[j + leng - 1 ] != '1'  || line_1[j + leng - 2] != '1')
// 			return(print_error(ERR_MAP3_MES, ERR_MAP3));
// 	while (line_1[++j] != '\n')
// 	{
// 		if (line_1[j] == '0')
// 		{
// 			if (line_2[j - 1 ] != '1' || line_2[j] != '1' || line_2[j + 1] != '1');
// 				printf("no se´que pasa en esta condicon1\n");
// 			//return;
// 			printf("no se´que pasa en esta condicon 2\n");
// 		}
// 		j++;
// 	}
// 	return (EXIT_SUCCESS);
// }


//una vez aquí: Solo hay un jugador y todos los caracteres son correctos en el mapa
int		map_closed(t_pars* parsing_str) //hay que verificar que denajo de un 1 siempre haya otro 1 
{
	if(normalize_map(parsing_str))
		return (EXIT_FAILURE);
		 //seguir por aqui
	// if (map_upper_closed(parsing_str))
	// 	return (ERR_MAP3);
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

	i = parsing_str->nb_line_map - 1; //le restamos 
	while (++i <= (int)parsing_str->nb_endline_map)
	{
		trimmed_map = ft_strtrim(parsing_str->map[i], MAP_STR);
		if (ft_strlen(trimmed_map) != 0)
		{
			free(trimmed_map);
			return(print_error(ERR_MAP1_MES, ERR_MAP1));
		}
		free(trimmed_map);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief
 * Chequea que el primer elemento de las lineas de las lineas izq
 * exterior, sea 1
 * 
 * @param parsing_str 
 * @return int valor diferente de 0, error
 */

int		map_left_closed(t_pars* parsing_str)
{

	int	i;
	char	*one_side;
	char	*trimmed;
	
	i = parsing_str->nb_line_map;
	while (++i < (int)parsing_str->nb_endline_map)
	{
		trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		one_side = ft_strchr(trimmed, ONE);
		if (one_side != trimmed)
		{
			free(trimmed);
			return(print_error(ERR_MAP5_MES, ERR_MAP5));
		}
		free(trimmed);
	}
	return (EXIT_SUCCESS);
}


/**
 * @brief
 * Chequea que el primer elemento de las lineas por debajo de la superior
 * y encima de la inferior sea 1, mediante aritmetica de punteros
 * 
 * @param parsing_str 
 * @return int valor diferente de 0, error
 */

int		map_right_closed(t_pars* parsing_str)
{

	int	i;
	char	*one_side;
	char	*trimmed;
	int		leng_line;
	
	i = parsing_str->nb_line_map;
	while (++i < (int)parsing_str->nb_endline_map)
	{
		trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		leng_line = ft_strlen(trimmed);
		one_side = ft_strrchr(trimmed, ONE);
		if (one_side != trimmed + leng_line - 1)
		{
			free(trimmed);
			return(print_error(ERR_MAP6_MES, ERR_MAP6));
		}
		free(trimmed);
	}
	return (EXIT_SUCCESS);
}



/**
 * @brief 
 * Verificamos que en la linea superior e inferiro todo sea 1
 * Despues llamamos a una funcion que compreube los laterales
 * @param parsing_str 
 * @return int 
 */

int		map_closed2(t_pars* parsing_str) //hay que verificar que denajo de un 1 siempre haya otro 1
{
	char *trimmed_one;
	size_t leng_trimm;

	trimmed_one = ft_strtrim(parsing_str->map[parsing_str->nb_line_map], ONES_STR);
	leng_trimm = ft_strlen((trimmed_one));
	free(trimmed_one);
	if (leng_trimm)
		return(print_error(ERR_MAP3_MES, ERR_MAP3));
	trimmed_one = ft_strtrim(parsing_str->map[parsing_str->nb_endline_map], ONES_STR);
	leng_trimm = ft_strlen((trimmed_one));
	free(trimmed_one);
	if (leng_trimm)
		return(print_error(ERR_MAP4_MES, ERR_MAP4));
	if (map_left_closed(parsing_str))
		return (ERR_MAP5);
	if (map_right_closed(parsing_str))
		return (ERR_MAP6);
	return (EXIT_SUCCESS);
}
