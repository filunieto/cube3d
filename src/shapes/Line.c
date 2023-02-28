
#include "../../inc/shapes/Shapes.h"

//Functions defined in utilsLine.c
extern int integerPart(float n);
extern float fractionalPart(float n);
extern float rfPart(float n);
extern void swap(int *n1, int *n2);

void drawLine (mlx_image_t *img, t_point *p1, t_point *p2)
{
	int steep;
	int dx;
	int dy;
	float gradient;
	int xend;
	float yend;
	int xpxl1;
	int ypxl1;
	int xpxl2;
	int ypxl2;

	float intery;

	if(!p1 || !p2)
	{
		printf("Error in points passed\n");
		return ;
	}

	steep = 0;
	if (fabs((double)p2->y - p1->y) > fabs((double)p2->x - p1->x))
		steep = 1;
	//Swap step
	if(steep == 1)
	{
		swap(&p1->x, &p1->y);
		swap(&p2->x, &p2->y);
	}
	if(p1->x > p2->x)
	{
		swap(&p1->x, &p2->x);
		swap(&p1->y, &p2->y);
	}
	
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;

	if(dx == 0)
		gradient = 1.0;
	else
		gradient = (float)dy / dx;

	//handle first endpoint
	xend = round(p1->x);
	yend = (float)p1->y + (gradient * (xend - p1->x));
	xpxl1 = xend;
	ypxl1 = integerPart(yend);

	if(steep == 1)
	{
		mlx_put_pixel(img, ypxl1, xpxl1, 0x00FF00FF);
		mlx_put_pixel(img, ypxl1 + 1, xpxl1, 0x00FF00FF);
	}
	else
	{	
		mlx_put_pixel(img, xpxl1, ypxl1, 0x00FF00FF);
		mlx_put_pixel(img, xpxl1, ypxl1 + 1, 0x00FF00FF);
	}

	intery = yend + gradient;

	//handle second endpoint
	xend = round(p2->x);
    yend = p2->y + (gradient * (xend - p2->x));
    xpxl2 = xend; //this will be used in the main loop
    ypxl2 = integerPart(yend);

	if(steep == 1)
	{
		
		mlx_put_pixel(img, ypxl2, xpxl2, 0x00FF00FF);
		mlx_put_pixel(img, ypxl2 + 1, xpxl2, 0x00FF00FF);
	}
	else
	{	
		mlx_put_pixel(img, xpxl2, ypxl2, 0x00FF00FF);
		mlx_put_pixel(img, xpxl2, ypxl2, 0x00FF00FF);
	}

	//Main loop
	if(steep == 1)
	{
		for(int x = xpxl1 + 1; x <= xpxl2 - 1; x++)
		{	
			mlx_put_pixel(img, integerPart(intery), x , 0x00FF00FF);
			mlx_put_pixel(img, integerPart(intery) + 1, x , 0x00FF00FF);
			intery = intery + gradient;
		}
	}
	else
	{	
		for(int x = xpxl1 + 1; x <= xpxl2 - 1; x++)
		{	
			mlx_put_pixel(img, x, integerPart(intery), 0x00FF00FF);
			mlx_put_pixel(img, x, integerPart(intery) + 1, 0x00FF00FF);
			intery = intery + gradient;
		}
	}
}
