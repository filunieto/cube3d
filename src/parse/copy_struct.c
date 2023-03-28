/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:30:43 by fnieves-          #+#    #+#             */
/*   Updated: 2023/03/28 18:39:35 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

// void	copy_struct(t_pars *parsing_str, t_struc *struct_generic)
// {
// //	printf("linea inicio: %zu , liena final %zu, max leng %zu\n",
// // parsing_str->nb_line_map, parsing_str->nb_endline_map ,parsing_str->max_leng_map );
// 	//pimero malloquear solo oel array de chars como en al funcion: normalize_map
// 	//copiar con el str_up, cad alinea  que estará acabada en 0 (automaticamente), y la ultima liena la cabamos en 0
// pasamos el resto de parametros. El path  con strdup, para poder borrar todo, sin probelmas