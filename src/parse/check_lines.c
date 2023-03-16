/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:23:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/16 20:49:51 by fnieves-         ###   ########.fr       */
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
		free(parsing_str->map[i]);
		parsing_str->map[i] = NULL; 
		//printf ("string de linea %i, limpio de espacioas y tabs: |%s|\n", i, s_trimmed);
		s_splited_cleaned =  ft_split(s_trimmed, SPACE);
		free(s_trimmed);
		s_trimmed = NULL;
		/* comprobar que todo esta bien . Podemos borrar */
		int j = 0;
		while (s_splited_cleaned[j])
		{
			printf ("\nElementos de Línea i %i , j %i, finalkes spliteaod y lipios:----|%s|---", i, j, s_splited_cleaned[j]);
			free(s_splited_cleaned[j]); //borrra , es solo para chequear leaks
			j++;
		}
		free(s_splited_cleaned);

		//verificar que están todos los parametros , guardar la posicion dónde empiezan los 1 y los 0 , para hacer free de todo lo anterior
		//is_parameter()
	}
	//free(s_splited_cleaned);
	free(parsing_str->map);
	return (1);
}