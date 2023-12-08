/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:15:04 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/07 16:00:24 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validcomponent(char c)
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

int doesmapexist(char *map)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != '.')
		i++;
	if (ft_strcmp(&map[i], ".ber") != 0)
		return (0);
	return (1);
}

char **read_map(char *map)
{
	char *line;
	char **fullmap;
	int len = 0;
	int i = 0;
	int fd = open(map, O_RDONLY);
	while((line = get_next_line(fd))!= NULL)
	{
		free(line);
		len++;
	}
	close(fd);
	fullmap = (char **)malloc((len + 1) * sizeof(char *));
	fd = open(map, O_RDONLY);
	while(i < len)
		fullmap[i++] = get_next_line(fd);
	fullmap[len] = NULL;
	close(fd);
	return (fullmap);
}

int validcomponentscheck(char **check, t_game_info *game, int e, int p)
{
	int i = -1;
	int j = -1;
	if(!check[0])
		return 0;
	while(check[++j])
	{
		i = 0;
		while(check[j][++i])
		{
			if(validcomponent(check[j][i]) == 1)
			{
				if(check[j][i] == 'C')
					game->coins++;
				if(check[j][i] == 'E')
					e--;
				if(check[j][i] == 'P')
					p--;
			}
			else
				return 0;
		}
	}
	if(game->coins != 0 && e == 0 && p == 0)
		return 1;
	return 0;
}

int checkifmaprectangular(char **str)
{
	int len;
	int j;

	if(!str[0])
		return 0;
	j = 0;
	len = linelen(str[j]);
	while(str[j])
	{
		if(len == linelen(str[j]))
			j++;
		else
		 return 0;
	}
	return 1;
}