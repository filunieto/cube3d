/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anramire <anramire@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:52:01 by anramire          #+#    #+#             */
/*   Updated: 2023/03/08 21:36:12 by anramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/shapes/Shapes.h"

static int check_square(t_4vertex *square);

void draw_square(mlx_image_t *img, t_4vertex *square, int color)
{
		draw_line(img, &(square->p0), &(square->p1), color);	
		draw_line(img, &(square->p1), &(square->p2), color);
		draw_line(img, &(square->p2), &(square->p3), color);
		draw_line(img, &(square->p3), &(square->p0), color);
}

void draw_square_filled(mlx_image_t *img, t_4vertex *sq, int color, int filled)
{
	t_point top;
	t_point bottom;
	
	if(check_square(sq) < 0)
		return ;
	if(filled == 0)
	{
		draw_square(img, sq, color);
	}
	else
	{
		
		insert_point(&top, sq->p0.x, sq->p0.y);
		insert_point(&bottom, sq->p2.x, sq->p2.y);
		while(top.y < bottom.y)
		{
			top.x = sq->p0.x;
			while(top.x < bottom.x)
			{
				mlx_put_pixel(img, top.x, top.y, color);
				top.x++;
			}
			top.y++;
		}
	}
}

void	draw_square_pos(mlx_image_t *img, t_point *pos, int tam, int color)
{
	tam = tam / 2;
	t_4vertex square;
	insert_point(&(square.p0), pos->x  - tam, pos->y - tam);
	insert_point(&(square.p1), pos->x + tam, pos->y - tam);
	insert_point(&(square.p2), pos->x  + tam, pos->y + tam);
	insert_point(&(square.p3), pos->x  - tam, pos->y +  tam);
	draw_square_filled(img, &square, color, 1);
}
static int check_square(t_4vertex *square)
{	
	if(square->p0.y != square->p1.y || square->p1.x != square->p2.x
			|| square->p2.y != square->p3.y || square->p3.x != square->p0.x)
	{
		printf("Error 1: Points passed do not correspond to any square\n");
		return -1;
	}else if(square->p0.x >= square->p1.x || square->p1.y >= square->p2.y
			|| square->p2.x <= square->p3.x || square->p3.y <= square->p0.y)
	{	
		printf("Error 2: Points passed do not correspond to any square\n");
		return -1;
	}

	return 0;
}


