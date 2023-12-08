#include "so_long.h"
#include <stdlib.h>

void load_images(void *mlx, t_assets *assets)
{
	int	width;
	int	height;

	height = 0;
	width = 0;
	assets->wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &width, &height);
    assets->player = mlx_xpm_file_to_image(mlx, "./textures/player.xpm", &width, &height);
    assets->coin = mlx_xpm_file_to_image(mlx, "./textures/coin.xpm", &width, &height);
    assets->door = mlx_xpm_file_to_image(mlx, "./textures/door.xpm", &width, &height);
    assets->floor = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", &width, &height);
	if(!assets->door || !assets->player || !assets->coin || !assets->wall || !assets->floor)
	{
		write(1, "Error\ninvalid assets",21);
		exit(0);
	}
}

void	put_img(t_game_info *game, char *ptr, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, ptr, j * 60, i * 60);
}

void maprender(t_game_info *game, t_assets *assets)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
		{
			j = 0;
			while(game->map[i][j])
			{
					put_img(game, assets->floor, j, i);
				if(game->map[i][j] == 'P')
					put_img(game, assets->player, j, i );
				if(game->map[i][j] == 'C')
					put_img(game, assets->coin, j, i);
				if(game->map[i][j] == 'E')
					put_img(game, assets->door, j, i);
				if(game->map[i][j] == '1')
					put_img(game, assets->wall, j, i);
				j++;
			}
			i++;
		}
}
