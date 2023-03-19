/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:43:56 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/19 22:36:46 by fnieves          ###   ########.fr       */
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


static bool	check_invalid_chars(char *str) //cambiar un poco esta funcion
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
	i = -1;
	while (*rgb[++i])
	{
		*rgb[i] = ft_strtrim(*rgb[i], SPACE_STR);
		rgb_array[i] = ft_rgb_atoi(*rgb[i]);
		if (rgb_array[i] < 0 )
		{
			free(*rgb[i]);
			return(print_error(ERR_COLOR_INP3_MES, ERR_COLOR_INP3));
		}
		free(*rgb[i]);
	}
	
	// convertir el RGB
	return (0);
	
}