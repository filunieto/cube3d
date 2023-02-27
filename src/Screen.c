
#include "../inc/Screen.h"

int init_window(void)
{
	
	mlx_t *mlx = mlx_init(INITIAL_WIDTH, INITIAL_HEIGHT, "Cub3D", true);

	if(!mlx)
	{
		printf("Error initializing window!!!\n");
		return -1;
	}

	mlx_image_t *img = mlx_new_image(mlx, INITIAL_WIDTH, INITIAL_HEIGHT);
	t_point p1, p2;
	p1.x = 1000;
	p1.y = 230;
	p2.x = 200;
	p2.y = 900;
	drawLine(img, &p1, &p2);

	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);

	return 0;
}
