/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rerenderingtools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:21:46 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 13:31:55 by asnaji           ###   ########.fr       */
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

void	player_movement(t_game_info *game, int x, int y, int i)
{
	int	j;

	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P' && game->map[i + x][j + y] != '1'
				&& game->map[i + x][j + y] != 'E')
			{
				if (game->map[i + x][j + y] == 'C')
					game->coins--;
				game->map[i][j] = '0';
				game->map[i + x][j + y] = 'P';
				game->movements += 1;
				return ;
			}
			if (game->map[i][j] == 'P' && game->map[i + x][j + y] == 'E'
				&& game->coins == 0)
			{
				ft_putstr("You Won!!\n", 1);
				closewindow(game);
			}
		}
	}
}

int	key_pressed(int key, t_game_info *game)
{
	int			i;

	i = 0;
	if (key == 53)
		closewindow(game);
	if (key == 0 || key == 13 || key == 2 || key == 1)
	{
		if (key == 13)
			player_movement (game, -1, 0, -1);
		else if (key == 0)
			player_movement (game, 0, -1, -1);
		else if (key == 1)
			player_movement (game, 1, 0, -1);
		else if (key == 2)
			player_movement (game, 0, 1, -1);
	}
	mlx_clear_window(game->mlx, game->mlx_win);
	maprender(game);
	return (0);
}

int	closewindow(t_game_info *game)
{
	ft_putstr("Window closed\n", 1);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	freee(game->map);
	free(game->mlx);
	exit(0);
}

void	printmovement(t_game_info *game)
{
	char	*str1;
	char	*str2;
	char	*nb;
	char	*res;

	nb = ft_itoa(game->movements);
	str1 = "You moved ";
	str2 = " times";
	if (!nb)
		return ;
	res = malloc(strlen(str1) + strlen(nb) + strlen(str2) + 1);
	if (!res)
	{
		free(nb);
		return ;
	}
	ft_strlcpy(res, str1, 50);
	ft_strlcat(res, nb, 50);
	ft_strlcat(res, str2, 50);
	mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0x009900FF, res);
	free(nb);
	free(res);
}
