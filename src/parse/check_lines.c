/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:23:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/20 12:59:08 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"





/**
 * @brief 
 * 
 * @param parsing_str 
 * @return int 
 REcuerda que el segundo elemento acaba en \n
Elementos de Línea i 1 , j 0, finalkes spliteaod y lipios:----|SO|---
Elementos de Línea i 1 , j 1, finalkes spliteaod y lipios:----|./ruta_a_la_textura_sur
|---
 */

int	check_lines(t_pars* parsing_str)
{
	int	i;

	i = -1;
	char *s_trimmed;
	char **s_splited_cleaned;
	while (parsing_str->map[++i])
	{
		s_trimmed = ft_strtrim(parsing_str->map[i], SPACE_STR);
		if ( ft_strlen(s_trimmed)) //en caso contrario hay que hacer free?? no hay nada en la linea
		{
			s_splited_cleaned =  ft_split(s_trimmed, SPACE);
			if (check_arguments(parsing_str, s_splited_cleaned))
			{
				free_split(&s_splited_cleaned);
				printf("Parametros de colores o texturas jodido. borra este mensaje y dejar solo free y return. Mesnaje de erro serñaprevio\n");
				return (1);
			}
			free_split(&s_splited_cleaned);
		}
		free(s_trimmed);
		s_trimmed = NULL;
	}
	return (0);
}

/*
	chequear la ruta tambien , si existe. Que a est funcion no llegue una linea vacia. Verificar antes
	crear u parametro all_arg ok (pra decir que los valores no están repetidos, las rutas se abren y los colores son correctos)
*/
int	check_arguments(t_pars* parsing_str, char **s_splited_cleaned)
{
	int id;

	id = check_identifier(parsing_str, s_splited_cleaned[0]);
	if (id == 0)
	{
		return(print_error(ERR_INP_MAP_MES , ERR_INP_MAP));
	}
	if (id >= NORTH &&  id <= WEST)
	{
		if (check_textur_path(parsing_str, &s_splited_cleaned[1], id)) 
		{
			return(1); //?
		}
		parsing_str->arg_ok += 1;
	}
	if (id == GROUND ||  id == HEAVEN) //mas facil dividir en 
	{
		if (check_colours(parsing_str, &s_splited_cleaned[1], id)) //verificar qeu solo haya 2 elementos
		{
			return (1);
		}
		parsing_str->arg_ok += 1;
	}
	//creo qeu no hago nada
	return (0);
	
}

/*
	va a verificar si el token es corretco y ademas no está repetido
	Igual puedo dividr la funcion para identificar el error de mnaera más explicita
	modificar
*/

int	check_identifier(t_pars* parsing_str, char *line_splitd)
{
	if (!parsing_str->north.name && !ft_strcmp(line_splitd, NORTH_STR) ) //if (!parsing_str->cardinal[1].name)
	{
		return (parsing_str->north.name = NORTH); //parsing_str->cardinal[1].name = NORTH;
	}
	else if (!parsing_str->south.name &&  !ft_strcmp(line_splitd, SOUTH_STR))
		return (parsing_str->south.name = SOUTH);
	else if (!parsing_str->east.name &&  !ft_strcmp(line_splitd, EAST_STR))
		return (parsing_str->east.name = EAST);
	else if (!parsing_str->west.name &&  !ft_strcmp(line_splitd, WEST_STR))
		return (parsing_str->west.name = WEST);
	else if (!parsing_str->heaven.part &&  !ft_strcmp(line_splitd, HEAVEN_STR))
		return (parsing_str->heaven.part = HEAVEN);
	else if (!parsing_str->ground.part &&  !ft_strcmp(line_splitd, GROUND_STR))
		return (parsing_str->ground.part = GROUND);
	// pasar esta condicion al otro programa ar au erro mas especifico (ft_strlen(ft_strtrim(line_splitd, MAP_STR)) == 0)
	else if (parsing_str->arg_ok == 6 &&  (ft_strlen(ft_strtrim(line_splitd, MAP_STR)) == 0)  ) 
		return (MAP); 
	else
		return (0);
}

int	check_textur_path(t_pars* parsing_str, char **s_splited_cleaned, int id)
{
	int fd;
	int fd2; //este es de prueba

	if (s_splited_cleaned[1] != NULL) //hay más argumentos de la cuenta NO ./text xxx
		return(print_error(ERR_TEXT_INP_MES, ERR_TEXT_INP));
	fd = open(s_splited_cleaned[0], O_RDONLY, CHMOD);
	fd2 = open(s_splited_cleaned[0], O_RDONLY);
	if (fd < 0)
	{
		printf("archivo para abrir |%s| y valores f %i y f2 %i. Seguimos aunque hay que revisar\n",s_splited_cleaned[0], fd, fd2 );
		//return(print_error(ERR_TEXT_PATH_MES, ERR_TEXT_PATH)); //funcion generica de error , que imprima y retorne NULL(todo en una linea)
	}
	if (id == NORTH)
	{
		//recuerda hacer close en algún momento de los archivos
		//parsing_str->north.path = open(s_splited_cleaned[0], O_RDONLY); //mos quedamos con el archivo en file si es posible 
		parsing_str->north.file = fd;
	}
	else if (id == SOUTH)
		parsing_str->south.file = fd;
	else if (id == EAST)
		parsing_str->east.file = fd;
	else if (id == WEST)
		parsing_str->west.file = fd;
	return (EXIT_SUCCESS);
}

