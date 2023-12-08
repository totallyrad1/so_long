#include "so_long.h"

int	getwidth(char *str)
{
	int i = 0;
	if(!str)
		return 0;
	while (str[i] && str[i] != '\n')
		i++;
	return i;
}

int	getheight(char **str)
{
	int i = 0;
	if(!str)
		return 0;
	while (str[i])
		i++;
	return i;
}

