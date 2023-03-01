/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:01 by anramire          #+#    #+#             */
/*   Updated: 2023/03/01 18:54:48 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../../memory-leaks/include/memory_leaks.h"
# include "../../MLX42/include/MLX42/MLX42.h"
//Structure to store a point in cartesians
typedef struct s_point {
	int	x;
	int	y;
}t_point;

//Structure to store a square, it goes clockwise i.e. first point is
//up left
typedef struct s_4vertex{
	t_point	p0;
	t_point	p1;
	t_point	p2;
	t_point	p3;
}t_4vertex;

//Structure to handle endpoints in Xiaolin Wu algorithm
typedef struct s_end_point
{
	int		steep;
	float	gradient;
	t_point	*p;
	float	intery;
	int		xpxl;
	int		color;

}t_end_point;

void	draw_line(mlx_image_t *img, t_point *p1, t_point *p2, int color);
#endif
