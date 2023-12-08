#include "so_long.h"

int surroundedwalls(char **map)
{
	int j;
	int len;
	int i;

	if(!map)
		return 0;
	j = 0;
	i = 0;
	len = linelen(map[j]);
	if (checkfullwall(map[j]) == 1)
		j++;
	else
	 	return (0);
	while(map[j])
	{
		if(map[j][len] == '1' && map[j][0] == '1')
			j++;
		else
		 	return 0;
	}
	if (checkfullwall(map[j - 1]) == 1)
		j++;
	else
	 	return 0;
	return 1;
}

void flood_fill(t_game_info **game, int i, int j)
{
	int n = getwidth((*game)->map2[0]);
	int m = getheight((*game)->map2);
	if(i < 0 || i >= m  || j < 0 || j >= n  || (*game)->map2[i][j] == '1' || (*game)->map2[i][j] == 'F')
	{
		return ;
	}
	else
		(*game)->map2[i][j] = 'F';
	flood_fill(game, i + 1,j);
	flood_fill(game, i - 1,j);
	flood_fill(game, i,j + 1);
	flood_fill(game, i,j - 1);
}

int backtrackingcheck(t_game_info *game)
{
	int i = 0;
	int j = 0;
	while(game->map2[i])
	{
		j = 0;
		while(game->map2[i][j])
		{
			if(game->map2[i][j] == 'E' || game->map2[i][j] == 'C')
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int get_i(char **map)
{
	int i = 0;
	int j;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
				return i;
			j++;
		}
		i++;
	}
	return i;
}

int get_j(char **map)
{
	int i = 0;
	int j;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
				return j;
			j++;
		}
		i++;
	}
	return j;
}