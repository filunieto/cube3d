/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:23:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/18 20:39:56 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/*
	Por qué no está
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	if (s1[i] == s2[i])
		return (0);
	return (1);
}



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
		// free(parsing_str->map[i]); de mmento me quedo con esto para reutilizarlo una vex todos los arg sean ok
		// parsing_str->map[i] = NULL; 
		if (ft_strlen(s_trimmed)) //en caso contrario hay que hacer free?? no hay nada en la linea
		{
			s_splited_cleaned =  ft_split(s_trimmed, SPACE);
			int j = 0;
			while (s_splited_cleaned[j]) //esta funcion se deja para borrar los elementos espliteados una vez pasadps 
			{
				printf ("\nAntes d echequear los tokens. Elementos de Línea i %i , j %i, finalkes spliteaod y lipios:----|%s|---", i, j, s_splited_cleaned[j]);
				j++;
			}
			
			if (check_arguments(parsing_str, s_splited_cleaned)) //añadir una condicion para que no entre si la linea esta vacia
			{
				printf("si la funcion anterior ha devuelto un valor diferente de 0 algo en colores o textura esta jodido. hacer free\n");
				//si entra aqui hay que liberer el spliteado ..Hacer una función qu eluego repetiremos
				return (1);
			}
			// el //check_map();
			
			j = 0;
			while (s_splited_cleaned[j]) //esta funcion se deja para borrar los elementos espliteados una vez pasadps 
			{
				printf ("\nya chequeados, podemos borrar i %i , j %i, finalkes spliteaod y lipios:----|%s|---", i, j, s_splited_cleaned[j]);
				free(s_splited_cleaned[j]); //borrra , es solo para chequear leaks
				j++;
			}
			free(s_splited_cleaned);

		}
		free(s_trimmed);
		s_trimmed = NULL;
	}
	free(parsing_str->map);
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
		printf ("id ninguno de NO, EAS, F, G or repetead o mapa con caracteres erroneos"); //funcion error argument, con mensaje "error"
		return (1);
	}
	//comprobar si son  cardinales la ruta y si son colores o si es un 1(en este ultimo caso hay que verificar que odo está ok)
	if (id >= NORTH &&  id <= WEST)
	{
		// if (check_tetx_path(parsing_str, s_splited_cleaned)) //verificar qeu solo haya 2 elementos
		// {
		// 	printf ("o la ruta no se puede abrir o hay más elemntos de la cuenta");
		// 	return (1);
		// }
		parsing_str->arg_ok += 1;
		
	}
	if (id == GROUND ||  id == HEAVEN)
	{
		// if (check_colours(parsing_str, s_splited_cleaned)) //verificar qeu solo haya 2 elementos
		// {
		// 	printf ("colores regu o hay más elemntos de la cuenta");
		// 	return (1);
		// }
		parsing_str->arg_ok += 1;
	}
	// if (id == MAP && ) //creo qeu no hago nada
	return (0);
	
}

/*
	va a verificar si el token es corretco y ademas no está repetido
*/

int	check_identifier(t_pars* parsing_str, char *line_splitd)
{
	if (!parsing_str->north.name && !ft_strcmp(line_splitd, NORTH_STR) )
	{
		// printf ("ha encontrado north y no  esta repetido");
		return (parsing_str->north.name = NORTH);
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
	// ft_strlen(ft_strtrim(line_splitd, MAP_STR)) == 0 >>> significa que en la linea solo hay caracteres ok
	else if (parsing_str->arg_ok == 6 &&  (ft_strlen(ft_strtrim(line_splitd, MAP_STR)) == 0)  ) //habría que chequear toda la linea con 1,0, N, S, E y W cuando todos los argumentos están om previamente 
		return (MAP); //intentar anotar la primera vez que entra  aqui , para saber cuando empieza el mapa
	//otra condicion de si encuentra un 1? ( ya está en el map)
	else
		return (0);
}