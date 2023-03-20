/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:43:56 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/20 12:39:52 by fnieves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/*
	
	Using bit shifting , we transform the 3 RGB int into one single RGB parameter
	which  is always an int, represented as HEX Value 
*/
static int	rgb_to_color_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

//si retorna 0 exito si no 1.. Lamarla son digitos
static bool	check_invalid_chars(char *str) //cambiar un poco esta funcion quitar true y cabiar nombre 
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len > 3)
		return (true); //true, es invalido (cambiar por -1)
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == false)
			return (true);
		i++;
	}
	return (false);
}

int	ft_rgb_atoi(char *str) //cambiar a atoi_rgb
{
	int		i;
	int		res;
	bool	str_invalid;

	str_invalid = check_invalid_chars(str);
	if (str_invalid == true)
		return (-1);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	if (res < 0 || res > 255)
		return (-1);
	else
		return (res);
}



int	check_values_rgb(t_pars* parsing_str, char ***rgb, int id)
{
	int i;
	int rgb_array[3];
	char **intervalo_rgb = *rgb;

	i = 0;
	while (intervalo_rgb[i])
	{
		//printf("11 check_values_rgb para i: %i. string : %s \n", i , intervalo_rgb[i]);
		//intervalo_rgb[i] = ft_strtrim(intervalo_rgb[i], SPACE_STR); //no es necesario el strim , sihay un espacio detras de l acoma lo considera un spleiteado previamente
		rgb_array[i] = ft_rgb_atoi(intervalo_rgb[i]);
		if (rgb_array[i] < 0 )
		{
			//free(intervalo_rgb[i]); no necesario
			return(print_error(ERR_COLOR_INP3_MES, ERR_COLOR_INP3));
		}
		//free(intervalo_rgb[i]); no necesario por no trimear
		i++;
	}
	i = rgb_to_color_hex(rgb_array[0], rgb_array[1], rgb_array[2]);
	//printf("el numero RGB queda  : %X \n", i );
	if (id == HEAVEN)
		parsing_str->heaven.rgb = i;
	if (id == GROUND)
		parsing_str->ground.rgb = i;
	if (parsing_str->heaven.rgb == parsing_str->ground.rgb) //creo que ambas condicoens no son necesarias. Probar (parsing_str->heaven.rgb == parsing_str->ground.rgb && parsing_str->heaven.rgb != -1)
		return(print_error(ERR_COLOR_INP4_MES, ERR_COLOR_INP4));
	return (0);
}

int	check_colours(t_pars* parsing_str, char **s_splited_cleaned, int id)
{
	int	i;
	char **rgb; 
	
	i = 0;
	if (s_splited_cleaned[1] != NULL) //Solo hay 2 argumentos : WE ./text xxx 
		return(print_error(ERR_COLOR_INP_MES, ERR_COLOR_INP));

	rgb = ft_split(s_splited_cleaned[0], COMMA); //hay que liberar: malloc free
	i = 0;
	while (rgb[i])
		i++;
	i = 0;
	while (rgb[i])
		i++;
	if (i  != 3) //tenemos más d e3 valores
	{
		// free split rgb
		return(print_error(ERR_COLOR_INP2_MES, ERR_COLOR_INP2)); 
	}
	if (check_values_rgb(parsing_str, &rgb, id) )
	{
		// free split rgb
		return(ERR_COLOR_INP2); //cambiar, pero hacer un free de RGB  el mensaje
	}
	// hacer un free, de split
	return (EXIT_SUCCESS);
}