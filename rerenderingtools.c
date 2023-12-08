/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerenderingtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:21:46 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/07 17:58:55 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*freee(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}


void player_movement(t_game_info *game, int x, int y)
{
	int i;
	int j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j] == 'P' && game->map[i + x][j + y] != '1' && game->map[i + x][j + y] != 'E')
			{
				if(game->map[i + x][j + y] == 'C')
					game->coins--;
				game->map[i][j] = '0';
				game->map[i + x][j + y] = 'P';
				game->movements += 1;
				printf("u moved %d times \n", game->movements);
				return ;
			}
			if(game->map[i][j] == 'P' && game->map[i + x][j + y] == 'E' && game->coins == 0)
			{
				printf("You Won!!");
				closewindow(game);
			}
			j++;
		}
		i++;
	}
}

int key_pressed(int key, t_game_info *game)
{
	int i = 0;
	t_assets *assets;

	i = 0;
	if(key == 53)
		closewindow(game);
	if (key == 123 || key == 126 || key == 124 || key == 125)
	{
		if (key == 126)
			player_movement (game, -1, 0);
		else if (key == 123)
			player_movement (game, 0, -1);
		else if (key == 125)
			player_movement (game, 1, 0);
		else if (key == 124)
			player_movement (game, 0, 1);
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	assets = malloc(sizeof(t_assets));
		if (!(assets))
			exit (0);
	load_images(game->mlx, assets);
	maprender(game, assets);
	free(assets);
	return 0;
}

int closewindow(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	freee(game->map);
	free(game->mlx);
	exit(0);
}