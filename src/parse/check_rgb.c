/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:43:56 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/20 01:38:30 by fnieves          ###   ########.fr       */
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
		printf("10 miramo sel spliteado: %i. string : %s \n", i , intervalo_rgb[i]);
		i++;
	}
	i = 0;
	while (*rgb[i])
	{
		printf("11 check_values_rgb para i: %i. string : %s \n", i , *rgb[i]);
		*rgb[i] = ft_strtrim(*rgb[i], SPACE_STR);
		rgb_array[i] = ft_rgb_atoi(*rgb[i]);
		printf("12 rgb_array[i]: %i \n" , rgb_array[i]);
		if (rgb_array[i] < 0 )
		{
			printf("12.5 check_values_rgb\n");
			free(*rgb[i]);
			return(print_error(ERR_COLOR_INP3_MES, ERR_COLOR_INP3));
		}
		printf("13 check_values_rgb\n");
		free(*rgb[i]);
		printf("14 check_values_rgb\n");
		i++;
	}
	

	i = rgb_to_color_hex(rgb_array[0], rgb_array[1], rgb_array[2]);
	if (id == HEAVEN)
		parsing_str->heaven.rgb = i;
	printf("12 check_values_rgb\n");
	if (id == GROUND)
		parsing_str->ground.rgb = i;
	printf("13 check_values_rgb\n");

	if (parsing_str->heaven.rgb == parsing_str->ground.rgb) //creo que ambas condicoens no son necesarias. Probar (parsing_str->heaven.rgb == parsing_str->ground.rgb && parsing_str->heaven.rgb != -1)
		return(print_error(ERR_COLOR_INP4_MES, ERR_COLOR_INP4));
	printf("14 check_values_rgb\n");

	return (0);
}