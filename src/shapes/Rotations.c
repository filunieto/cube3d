/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:57:55 by anramire          #+#    #+#             */
/*   Updated: 2023/03/16 20:03:41 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shapes/Shapes.h"

float	grades_to_rads(float grades)
{
	float rads;

	rads = grades * ((float)M_PI / 180);
	return (rads);
}

float	rads_to_grades(float rads)
{
	float grades;

	grades = rads * ((float)180 / M_PI);

	return grades;
}
