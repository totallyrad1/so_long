/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:31 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 13:31:04 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkifmapvalid(char *filename, t_game_info *game)
{
	char	**map;

	if (doesmapexist(filename) != 1)
	{
		ft_putstr("Error\nInvalid file", 2);
		exit(0);
	}
	map = read_map(filename);
	if (validcomponentscheck(map, game, 1, 1) != 1
		|| checkifmaprectangular(map) != 1 || surroundedwalls(map) != 1)
	{
		ft_putstr("Error\nthe map isnt surrounded by walls / not rectangular", 2);
		ft_putstr("/or invalid components", 2);
		freee(map);
		exit(0);
	}
	game->map2 = read_map(filename);
	flood_fill(&game, get_i(game->map2), get_j(game->map2));
	if (backtrackingcheck(game) == 0)
	{
		ft_putstr("Error\nmake sure the the player can get to collectible/exit", 2);
		exit(0);
	}
	freee(map);
}

int	main(int ac, char **av)
{
	t_game_info	game;

	if (ac == 2)
	{
		game.movements = 0;
		checkifmapvalid(av[1], &game);
		game.map = read_map(av[1]);
		game.mlx = mlx_init();
		game.h = getheight(game.map) + 1;
		game.w = getwidth(game.map[1]);
		if (game.h > 23 || game.w > 42)
		{
			ft_putstr("map too big", 2);
			exit(0);
		}
		game.mlx_win = mlx_new_window(game.mlx, game.w * 60, game.h * 60, "l");
		load_images(game.mlx, &game);
		maprender(&game);
		mlx_hook(game.mlx_win, 2, 0, &key_pressed, &game);
		mlx_hook(game.mlx_win, 17, 0, &closewindow, &game);
		mlx_loop(game.mlx);
	}
}
