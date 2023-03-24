/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:57:55 by anramire          #+#    #+#             */
/*   Updated: 2023/03/24 18:44:52 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shapes/Shapes.h"

float	grades_to_rads(float grades)
{
	float rads;

	rads = grades * ((float)M_PI / 180.0);
	return (rads);
}

float	rads_to_grades(float rads)
{
	float grades;

	grades = rads * ((float)180.0 / M_PI);

	return grades;
}

float normalize_angle (float angle)
{
	float new_angle;
	new_angle = angle;

	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 360)
		angle = angle - 360;
	return angle;
}
