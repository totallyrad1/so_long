/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:48:31 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/07 17:34:37 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <complex.h>
#include <stdlib.h>



void checkifmapvalid(char *filename, t_game_info *game)
{
	if (doesmapexist(filename) != 1)
	{	
		write(1, "Error\nInvalid file", 19);
		exit(0);
	}
	char **map = read_map(filename);
	if (validcomponentscheck(map, game, 1 , 1) != 1)
	{
		write(1, "Error\nInvalid component in map/missing component", 49);
		exit(0);
	}
	if (checkifmaprectangular(map) != 1 || surroundedwalls(map) != 1)
	{
		write(1, "Error\nthe map isnt surrounded by walls / not rectangular", 57);
		exit(0);
	}
	game->map2 = read_map(filename);
	flood_fill(&game, get_i(game->map2), get_j(game->map2));
	if  (backtrackingcheck(game) == 0)
	{
		write(1,"Error\nmake sure the the player can get to collectible/exit in your map", 71);
		exit(0);
	}
	freee(map);
	free(game->map2);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		t_assets	*assets;
		t_game_info	game;
		
		assets = malloc(sizeof(t_assets));
		if (!(assets))
			return (0);
		checkifmapvalid(av[1], &game);
		game.map = read_map(av[1]);
		game.mlx = mlx_init();
		game.height = getheight(game.map);
		game.width = getwidth(game.map[1]);
		game.mlx_win = mlx_new_window(game.mlx, game.width * 60, game.height * 60, "lo3ba");
		load_images(game.mlx, assets);
		maprender(&game, assets);
		mlx_hook(game.mlx_win, 2, 0, &key_pressed, &game);
		mlx_hook(game.mlx_win, 17, 0, &closewindow, &game);
		mlx_loop(game.mlx);
	}
}

