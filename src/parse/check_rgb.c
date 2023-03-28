/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:43:56 by fnieves           #+#    #+#             */
/*   Updated: 2023/03/28 19:39:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Screen.h"

/**
 * @brief 
 * Using bit shifting , we transform the 3 RGB int into one single RGB parameter
 * which  is always an int, represented as HEX Value 
 * @param r 
 * @param g 
 * @param b 
 * @return int 
 */

static int	rgb_to_color_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

static int	check_invalid_rgb(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (len > 3)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == false)
			return (-1);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	atoi_rgb(char *str)
{
	int		i;
	int		res;

	if (check_invalid_rgb(str))
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

int	check_values_rgb(t_pars *parsing_str, char ***rgb, int id)
{
	int		i;
	int		rgb_array[3];
	char	**intervalo_rgb;

	intervalo_rgb = *rgb;
	i = 0;
	while (intervalo_rgb[i])
	{
		rgb_array[i] = atoi_rgb(intervalo_rgb[i]);
		if (rgb_array[i] < 0)
			return (print_error(ERR_COLOR_INP3_MES, ERR_COLOR_INP3));
		i++;
	}
	i = rgb_to_color_hex(rgb_array[0], rgb_array[1], rgb_array[2]);
	if (id == HEAVEN)
		parsing_str->heaven.rgb = i;
	if (id == GROUND)
		parsing_str->ground.rgb = i;
	if (parsing_str->heaven.rgb == parsing_str->ground.rgb)
		return (print_error(ERR_COLOR_INP4_MES, ERR_COLOR_INP4));
	return (EXIT_SUCCESS);
}

int	check_colours(t_pars *parsing_str, char **s_splited_cleaned, int id)
{
	int		i;
	char	**rgb;

	i = -1;
	if (s_splited_cleaned[1] != NULL)
		return (print_error(ERR_COLOR_INP_MES, ERR_COLOR_INP));
	rgb = ft_split(s_splited_cleaned[0], COMMA);
	while (rgb[++i])
		i++;
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (free_split_rgb(&rgb, ERR_COLOR_INP2_MES));
	if (check_values_rgb(parsing_str, &rgb, id))
		return (free_split_rgb(&rgb, NULL));
	free_split_rgb(&rgb, NULL);
	return (EXIT_SUCCESS);
}
