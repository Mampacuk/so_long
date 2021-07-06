/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:49:53 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 18:49:54 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ismaprow(char *str)
{
	if (!str || *str == '\0')
		return (0);
	while (*str)
	{
		if (!(*str == '0' || *str == '1'
				|| *str == 'C' || *str == 'E' || *str == 'P'
				|| *str == 'F'))
			return (0);
		str++;
	}
	return (1);
}

static int	ft_isnotawall(char c)
{
	return (c == '0' || c == 'C' || c == 'E'
		|| c == 'P' || c == 'F');
}

static void	ft_checksides(char **map, int height, int width, int j)
{
	int	x;

	while (j < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[j][x] == '1')
				break ;
			if (ft_isnotawall(map[j][x]) || x == width - 1)
				ft_exit("The map is not closed from left.");
			x++;
		}
		x = width - 1;
		while (x >= 0)
		{
			if (map[j][x] == '1')
				break ;
			if (ft_isnotawall(map[j][x]) || x == 0)
				ft_exit("The map is not closed from right.");
			x--;
		}
		j++;
	}
}

static void	ft_checkabovebelow(char **map, int height, int width, int j)
{
	int	x;

	while (j < width)
	{
		x = 0;
		while (x < height)
		{
			if (map[x][j] == '1')
				break ;
			if (ft_isnotawall(map[x][j]) || x == height - 1)
				ft_exit("The map is not closed from above.");
			x++;
		}
		x = height - 1;
		while (x >= 0)
		{
			if (map[x][j] == '1')
				break ;
			if (ft_isnotawall(map[x][j]) || x == height - 1)
				ft_exit("The map is not closed from below.");
			x--;
		}
		j++;
	}
}

void	ft_checkwalls(char **map, int height, int width)
{
	ft_checkabovebelow(map, height, width, 0);
	ft_checksides(map, height, width, 0);
}
