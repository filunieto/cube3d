/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:42:06 by anramire          #+#    #+#             */
/*   Updated: 2022/04/28 00:14:28 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*get_str(int *num, size_t len, int neg);
static char	*get_negative(int *num, size_t len);
static char	*get_positive(int *num, size_t len);

char	*ft_itoa(int n)
{
	int		number[10];
	size_t	i;
	int		neg;

	i = 0;
	neg = 1;
	if (n < 0)
	{
		neg = -1;
		n = n * (-1);
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		number[i] = n % 10;
		n = n / 10;
		i++;
	}
	return (get_str(number, i, neg));
}

static char	*get_str(int *num, size_t len, int neg)
{
	if (neg < 0)
		return (get_negative(num, len));
	return (get_positive(num, len));
}

static char	*get_negative(int *num, size_t len)
{
	char	*num_str;
	size_t	i;

	num_str = (char *)malloc((len + 2) * sizeof(char));
	if (num_str == NULL)
		return (NULL);
	num_str[0] = '-';
	i = 1;
	while ((int)len > 0)
	{
		num_str[i] = num[len - 1] + '0';
		len--;
		i++;
	}
	num_str[i] = '\0';
	return (num_str);
}

static char	*get_positive(int *num, size_t len)
{
	char	*num_str;
	size_t	i;

	num_str = (char *)malloc((len + 1) * sizeof(char));
	if (num_str == NULL)
		return (NULL);
	i = 0;
	while ((int)len > 0)
	{
		num_str[i] = num[len - 1] + '0';
		len--;
		i++;
	}
	num_str[i] = '\0';
	return (num_str);
}
