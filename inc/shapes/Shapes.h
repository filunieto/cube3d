/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:43:01 by anramire          #+#    #+#             */
/*   Updated: 2023/03/21 18:06:39 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../../memory-leaks/include/memory_leaks.h"
# include "../../MLX42/include/MLX42/MLX42.h"

//Structure to store a point in cartesians with integer precision
typedef struct s_point {
	int	x;
	int	y;
}t_point;

//Structure to store a point in cartesions with floating point precision
typedef struct s_point_f {
	float x;
	float y;
}t_point_f;

//Structure to store a line defined with 2 points
typedef struct s_line
{
	t_point *p0;
	t_point *p1;
}t_line;

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

//Methods to introduce a point inside the structure
void insert_point(t_point *p, int x, int y);
void insert_point_f(t_point_f *p, float x, float y);
//Function to insert points into a line
void insert_points_line(t_line *line, t_point *p0, t_point *p1);

//Method to draw lines
void	draw_line(mlx_image_t *img, t_point *p1, t_point *p2, int color);

//Method to check if points are valid
int	check_points(t_point *p1, t_point *p2);

//Method to draw a square
void	draw_square(mlx_image_t *img, t_4vertex *square, int color);
void	draw_square_filled(mlx_image_t *img, t_4vertex *sq, int color, int filled);
void	draw_square_pos(mlx_image_t *img, t_point *pos, int tam, int color);

//Methods to convert an angle given in grades to rads and viceversa
float	grades_to_rads(float grades);
float	rads_to_grades(float rads);

#endif
