
#ifndef SHAPES_H_
#define SHAPES_H_

#include <stdio.h>
#include <math.h>
#include "../../MLX42/include/MLX42/MLX42.h"
//Structure to store a point in cartesians
typedef struct s_point {
	//Define coords of a point
	int x;
	int y;
}t_point;

void drawLine (mlx_image_t *img, t_point *p1, t_point *p2);

#endif
