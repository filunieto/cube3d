/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsLine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:29 by anramire          #+#    #+#             */
/*   Updated: 2023/03/15 19:17:07 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shapes/Shapes.h"

//Function to get the integer part of a decimal number
int	i_part(float number)
{
	return (floor(number));
}

float	fractional_part(float number)
{
	return (number - i_part(number));
}

//Function to obtain the complementary to be value 1,
//i.e number + rfPart = 1
float	rf_part(float number)
{
	return (1 - fractional_part(number));
}

//Function to swap values
void	swap(int *n1, int *n2)
{
	int	aux;

	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

//Function to insert points into a line
void insert_points_line(t_line *line, t_point *p0, t_point *p1)
{
	if(!p0 || !p1)
		return;
	line->p0 = p0;
	line->p1 = p1;
}
