#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

#define TILE_SIZE 32
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 320

char g_map[MAP_HEIGHT][MAP_WIDTH + 1] =
{
	"1111111111",
	"1000000001",
	"1011111101",
	"1000000001",
	"1001111001",
	"1001001001",
	"1000000001",
	"1011111101",
	"1000000001",
	"1111111111"
};

void	render_map(void *mlx, void *win)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = -1;
	while (++y < MAP_HEIGHT)
	{
		x = -1;
		while (++x < MAP_WIDTH)
		{
			int colour = (g_map[y][x] == '1') ? 0xFFFFFF : 0x000000;
			i = -1;
			while (++i < TILE_SIZE)
			{
				j = -1;
				while (++j < TILE_SIZE)
					mlx_pixel_put(mlx, win, x * TILE_SIZE + j, y * TILE_SIZE + i, colour);
			}
		}
	}
}

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "2D Map");
	render_map(mlx, win);
	mlx_loop(mlx);
	return (0);
}