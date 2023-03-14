/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsPoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:52:21 by anramire          #+#    #+#             */
/*   Updated: 2023/03/14 22:51:59 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shapes/Shapes.h"

void	insert_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

int	check_points(t_point *p1, t_point *p2)
{
	if (!p1 || !p2)
	{
		printf("Error in points passed\n");
		return (-1);
	}
	return (0);
}
