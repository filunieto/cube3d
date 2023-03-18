/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:16:23 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/18 18:06:00 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/*
podemos borrao despues
*/
void draw_copied_map(t_pars* parsing_str) //funcion solo para verificar
{
	
	int i = -1;
	while(parsing_str->map[++i])
	{
		printf("linea de map: %i: %s", i, parsing_str->map[i]);
	}
	if (!parsing_str->map[i])
		printf("\nesto se imprime porque la ultima linea es null\n");
}

/*
	Esta funcion copia 
*/

int copy_file(t_pars* parsing_str)
{
	int i;
	char *line;

	parsing_str->file_inp = open(parsing_str->arg_1, O_RDONLY, CHMOD);
	if (parsing_str->file_inp < 0)
	{
		printf("Problema apertura de archivo, STOP\n"); //Usar la función de error y verficar si hay que hacer free
		return (1);
	}
	i = 0;
	while (1)
	{
		//atencion al orden
		line = get_next_line(parsing_str->file_inp);
		parsing_str->map[i] = line; //si el ultimo elemento es Null, lo nultermina
		i++;
		if (!line)
			break;
		line = NULL;
	}
	//draw_copied_map(parsing_str);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * Función que va a leer todo el archivo y calculara el array de punteros
 * Quiza sería mejor que retornara un int
 * @param parsing_str 
 * @return true 
 * @return false 
 */
int	read_file(t_pars* parsing_str)
{
	while (1)
	{
		parsing_str->line = get_next_line(parsing_str->file_inp);
		parsing_str->nb_line += 1;
		
		if (!parsing_str->line)
		{
			break;
		}
		free(parsing_str->line);
	}
	parsing_str->map = calloc(sizeof (*parsing_str->map), parsing_str->nb_line + 1); //libft
	if (!parsing_str->map)
		return (1); //habría que liberar algo más? (poner un int de output)
	close(parsing_str->file_inp);
	copy_file(parsing_str); //meter algun error para asegurarse >>> (if copy_file(parsing_str))
	if (check_lines(parsing_str))
	{
		printf("faltan tokens antes de empezar el map");
	}
	//free(parsing_str->map);
	return (0);
	//como nos aseguramos que había llegado al final de linea y que no ha habido un error cualquiera (lectura)
}