#include <stdio.h>
#include "../MLX42/include/MLX42/MLX42.h"

#define HEIGHT 500
#define WIDTH 450

int main(void)
{
    printf("hello world!!!\n");
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
    if(!mlx)
    {
        printf("Error creating an instance of mlx!!!\n");
        return -1;
    }

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return 0;
}
