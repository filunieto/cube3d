#include "../../inc/shapes/Shapes.h"

//Functions defined in utilsLine.c
extern int		i_part(float n);
extern float	fractional_part(float n);
extern float	rf_part(float n);
extern void		swap(int *n1, int *n2);

static int		handle_first_endpoint(mlx_image_t *img, t_end_point *fep);
static int		handle_second_endpoint(mlx_image_t *img, t_end_point *sep);
static void		main_loop(mlx_image_t *img, t_end_point *fep, t_end_point *sep);
static void		init_variables_line(t_point *p1, t_point *p2, t_end_point *fep);

void	draw_line(mlx_image_t *img, t_point *p1, t_point *p2, int color)
{
	t_end_point	*fep;
	t_end_point	*sep;

	sep = (t_end_point *)malloc(sizeof(t_end_point));
	fep = (t_end_point *)malloc(sizeof(t_end_point));
	init_variables_line(p1, p2, fep);
	fep->p = p1;
	sep->p = p2;
	fep->color = color;
	sep->color = fep->color;
	if (!p1 || !p2)
	{
		printf("Error in points passed\n");
		return ;
	}
	sep->steep = fep->steep;
	sep->gradient = fep->gradient;
	fep->xpxl = handle_first_endpoint(img, fep);
	sep->xpxl = handle_second_endpoint(img, sep);
	main_loop(img, fep, sep);
	free(fep);
	free(sep);
}

static void	init_variables_line(t_point *p1, t_point *p2, t_end_point *fep)
{
	int	dx;
	int	dy;

	fep->steep = 0;
	if (fabs((double)p2->y - p1->y) > fabs((double)p2->x - p1->x))
		fep->steep = 1;
	if (fep->steep == 1)
	{
		swap(&p1->x, &p1->y);
		swap(&p2->x, &p2->y);
	}
	if (p1->x > p2->x)
	{
		swap(&p1->x, &p2->x);
		swap(&p1->y, &p2->y);
	}	
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (dx == 0)
		fep->gradient = 1.0;
	else
		fep->gradient = (float)dy / dx;
}

static int	handle_first_endpoint(mlx_image_t *img, t_end_point *fep)
{
	int		xend;
	float	yend;
	int		ypxl1;

	xend = round(fep->p->x);
	yend = (float)fep->p->y + (fep->gradient * (xend - fep->p->x));
	ypxl1 = i_part(yend);
	if (fep->steep == 1)
	{
		mlx_put_pixel(img, ypxl1, xend, fep->color);
		mlx_put_pixel(img, ypxl1 + 1, xend, fep->color);
	}
	else
	{	
		mlx_put_pixel(img, xend, ypxl1, fep->color);
		mlx_put_pixel(img, xend, ypxl1 + 1, fep->color);
	}
	fep->intery = fep->gradient + yend;
	return (xend);
}

static int	handle_second_endpoint(mlx_image_t *img, t_end_point *sep)
{
	int		xend;
	float	yend;
	int		ypxl2;

	xend = round(sep->p->x);
	yend = sep->p->y + (sep->gradient * (xend - sep->p->x));
	ypxl2 = i_part(yend);
	if (sep->steep == 1)
	{
		mlx_put_pixel(img, ypxl2, xend, sep->color);
		mlx_put_pixel(img, ypxl2 + 1, xend, sep->color);
	}
	else
	{	
		mlx_put_pixel(img, xend, ypxl2, sep->color);
		mlx_put_pixel(img, xend, ypxl2, sep->color);
	}
	return (xend);
}

static void	main_loop(mlx_image_t *img, t_end_point *fep, t_end_point *sep)
{	
	if (fep->steep == 1)
	{
		fep->xpxl = fep->xpxl + 1;
		while (fep->xpxl <= sep->xpxl - 1)
		{	
			mlx_put_pixel(img, i_part(fep->intery), fep->xpxl, fep->color);
			mlx_put_pixel(img, i_part(fep->intery) + 1, fep->xpxl, fep->color);
			fep->intery = fep->intery + fep->gradient;
			fep->xpxl++;
		}
	}
	else
	{	
		fep->xpxl = fep->xpxl + 1;
		while (fep->xpxl <= sep->xpxl - 1)
		{	
			mlx_put_pixel(img, fep->xpxl, i_part(fep->intery), fep->color);
			mlx_put_pixel(img, fep->xpxl, i_part(fep->intery) + 1, fep->color);
			fep->intery = fep->intery + fep->gradient;
			fep->xpxl++;
		}
	}
}
