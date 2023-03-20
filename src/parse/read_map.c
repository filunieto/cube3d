/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:16:23 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/21 00:33:22 by fnieves          ###   ########.fr       */
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
		return(print_error(ERR_OPEN_FD_MES , ERR_OPEN_FD));
	}
	i = 0;
	while (1)
	{
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
 */
int	read_file(t_pars* parsing_str)
{
	while (1) //esto casi mejor hacer una funcion aparte, para acortar, solo sive para contar lineas
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
	if (copy_file(parsing_str))
	{
		//hacer free del parsing_str->map, aunque igual no es muy necesario
		return (1);
	}
	//copy_file(parsing_str); //meter algun error para asegurarse >>> (if copy_file(parsing_str))
	if (check_lines(parsing_str))
	{
		//hacer free del parsing_str->map
		printf("Probelmas antes de parsear solo el mapa. Borra este mensaje em read_line\n");
		return (1);
	}
	printf("lineas coorectas: miramos el map\n");

	if (check_map(parsing_str))
	{
		//hacer free del parsing_str->map
		printf("Probelmas antes de parsear solo el mapa. Borra este mensaje em read_line\n");
		return (1);
	}
	//free(parsing_str->map);
	return (0);
	//como nos aseguramos que había llegado al final de linea y que no ha habido un error cualquiera (lectura)
}