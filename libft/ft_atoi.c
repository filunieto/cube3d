/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:17:13 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 23:10:03 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_first_pos(const char *str);
static size_t	get_last_pos(const char *str, size_t first_position);
static size_t	get_length(const char *str);
static int		get_number(const char *str, size_t first_pos, size_t last_pos);

int	ft_atoi(const char *nptr)
{
	size_t	f_pos;
	size_t	pos;
	int		sign;

	sign = 1;
	f_pos = get_first_pos(nptr);
	pos = 0;
	if ((f_pos != 0) || ((f_pos == 0) && (nptr[f_pos] <= '9')
			&& (nptr[f_pos] >= '0')))
	{
		while (pos < f_pos)
		{
			if (nptr[pos] == '-')
				sign = -1;
			pos++;
		}
		if (((get_last_pos(nptr, f_pos) - f_pos) >= 18) && (sign == -1))
			return (0);
		if (((get_last_pos(nptr, f_pos) - f_pos) >= 18) && (sign != -1))
			return (-1);
		return (sign * get_number(nptr, f_pos, get_last_pos(nptr, f_pos)));
	}
	return (0);
}

static int	get_number(const char *str, size_t first_pos, size_t last_pos)
{
	int	number;
	int	diff;
	int	aux;
	int	height;

	height = 1;
	diff = (int)last_pos - (int)first_pos;
	number = 0;
	while (first_pos <= last_pos)
	{
		aux = diff;
		while (diff > 0)
		{
			height = height * 10;
			diff--;
		}
		number += (height * (str[first_pos] - '0'));
		height--;
		first_pos++;
		diff = aux - 1;
		height = 1;
	}
	return (number);
}

static size_t	get_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

static size_t	get_first_pos(const char *str)
{
	size_t	pos;
	size_t	len_str;
	size_t	count;

	pos = 0;
	count = 0;
	len_str = get_length(str);
	while (pos < len_str)
	{
		if ((count == 1) && !((str[pos] >= '0') && (str[pos] <= '9')))
			break ;
		if ((str[pos] >= '0') && (str[pos] <= '9'))
			return (pos);
		if ((str[pos] == '+' ) || (str[pos] == '-'))
			count++;
		if ((count > 1) || ((str[pos]) != '\t' && (str[pos] != '\n')
				&& (str[pos] != '\r') && (str[pos] != '\f')
				&& (str[pos] != '\v') && (str[pos] != ' ')
				&& (str[pos] != '-') && (str[pos] == '-'))
			|| (str[pos] == '\e') || ((str[pos] <= 'z') && (str[pos] >= 'a')))
			break ;
		pos++;
	}
	return (0);
}

static size_t	get_last_pos(const char *str, size_t first_position)
{
	size_t	l_pos;

	l_pos = first_position;
	while (str[l_pos] != '\0')
	{
		if (!((str[l_pos] >= '0') && (str[l_pos] <= '9')))
			return (l_pos - 1);
		l_pos++;
	}
	if (str[l_pos] == '\0')
		return (l_pos - 1);
	return (0);
}
