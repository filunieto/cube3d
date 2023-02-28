#include "../inc/Screen.h"

int	init_window(void)
{	
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_point		p1;
	t_point		p2;

	mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "Cub3D", true);
	if (!mlx)
	{
		printf("Error initializing window!!!\n");
		return (-1);
	}
	img = mlx_new_image(mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	p1.x = 1000;
	p1.y = 900;
	p2.x = 450;
	p2.y = 900;
	draw_line(img, &p1, &p2, 0x0000FFFF);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
