
#ifndef SHAPES_H_
#define SHAPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../MLX42/include/MLX42/MLX42.h"
//Structure to store a point in cartesians
typedef struct s_point {
	//Define coords of a point
	int x;
	int y;
}t_point;

//Structure to handle endpoints in Xiaolin Wu algorithm
typedef struct s_end_point
{
	int steep;
	float gradient;
	t_point *p;
	float intery;
	int xpxl;
	int color;

}t_end_point;

void draw_line (mlx_image_t *img, t_point *p1, t_point *p2, int color);

#endif
