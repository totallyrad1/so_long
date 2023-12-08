/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderingtools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:07:54 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 00:30:10 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void *mlx, t_game_info *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	game->wall = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(mlx, "./textures/play.xpm", &w, &h);
	game->coin = mlx_xpm_file_to_image(mlx, "./textures/coin.xpm", &w, &h);
	game->door = mlx_xpm_file_to_image(mlx, "./textures/door.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(mlx, "./textures/floor.xpm", &w, &h);
	if (!game->door || !game->player
		|| !game->coin || !game->wall || !game->floor)
	{
		write(1, "Error\ninvalid assets", 21);
		exit(0);
	}
}

void	put_img(t_game_info *game, char *ptr, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, ptr, j * 60, i * 60);
}

void	maprender(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_img(game, game->floor, j, i);
			if (game->map[i][j] == 'P')
				put_img(game, game->player, j, i);
			if (game->map[i][j] == 'C')
				put_img(game, game->coin, j, i);
			if (game->map[i][j] == 'E')
				put_img(game, game->door, j, i);
			if (game->map[i][j] == '1')
				put_img(game, game->wall, j, i);
			j++;
		}
		i++;
	}
}
