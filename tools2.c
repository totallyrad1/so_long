/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asnaji <asnaji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:45:04 by asnaji            #+#    #+#             */
/*   Updated: 2023/12/09 12:49:51 by asnaji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcomponents(int coins, int e, int p)
{
	if (coins != 0 && e == 0 && p == 0)
		return (1);
	return (0);
}

void	update_e_and_p(char c, int *e, int *p)
{
	if (c == 'E')
		(*e)--;
	if (c == 'P')
		(*p)--;
}

int	checkfullwall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
