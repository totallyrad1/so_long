/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:15:04 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 12:45:01 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validcomponent(char c)
{
	if (c == 'E')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'C')
		return (1);
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	doesmapexist(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (ft_strcmp(&map[i - 4], ".ber") != 0)
		return (0);
	return (1);
}

char	**read_map(char *map)
{
	char	*line;
	char	**fullmap;
	int		len;
	int		i;
	int		fd;

	fd = open(map, O_RDONLY);
	len = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		len++;
		line = get_next_line(fd);
	}
	close(fd);
	fullmap = (char **)malloc((len + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	while (i < len)
		fullmap[i++] = get_next_line(fd);
	fullmap[len] = NULL;
	close(fd);
	return (fullmap);
}

int	validcomponentscheck(char **check, t_game_info *game, int e, int p)
{
	int	j;
	int	i;

	game->coins = 0;
	j = -1;
	i = -1;
	if (!check[0])
		return (0);
	while (check[++j])
	{
		i = -1;
		while (check[j][++i])
		{
			if (validcomponent(check[j][i]) == 1)
			{
				if (check[j][i] == 'C')
					game->coins++;
				update_e_and_p(check[j][i], &e, &p);
			}
			else
				return (0);
		}
	}
	return (checkcomponents(game->coins, e, p));
}

int	checkifmaprectangular(char **str)
{
	int	len;
	int	j;

	if (!str[0])
		return (0);
	j = 0;
	len = linelen(str[j]);
	while (str[j])
	{
		if (len == linelen(str[j]))
			j++;
		else
			return (0);
	}
	return (1);
}
