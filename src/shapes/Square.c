
#include "../../inc/shapes/Shapes.h"

void draw_square(mlx_image_t *img, t_4vertex *square, int color)
{
	if(square->p0.y != square->p1.y || square->p1.x != square->p2.x
			|| square->p2.y != square->p3.y || square->p3.x != square->p0.x)
	{
		printf("Points passed do not correspond to any square\n");
		return ;
	}else if(square->p0.x >= square->p1.x || square->p1.y >= square->p2.y
			|| square->p2.x <= square->p3.x || square->p3.y <= square->p0.y)
	{	
		printf("Points passed do not correspond to any square\n");
		return;
	}
	else
	{(void)color;
		draw_line(img, &(square->p0), &(square->p1), color);	
		draw_line(img, &(square->p1), &(square->p2), color);
		draw_line(img, &(square->p2), &(square->p3), color);
		draw_line(img, &(square->p3), &(square->p0), color);
	}
}
