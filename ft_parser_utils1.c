/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:05:35 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 19:05:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_getworldmap(char *mappath, t_parsed *res)
{
	int		fd;
	char	*line;
	int		r;
	int		x;

	fd = open(mappath, O_RDONLY);
	ft_setup_map(res, mappath);
	x = 0;
	while (1)
	{
		r = get_next_line(fd, &line);
		ft_writerow(line, res, x++);
		if (!r)
			break ;
	}
	if (res->player.x < 0 || res->player.y < 0)
		ft_exit("The player is missing.");
	if (res->player.goal < 1)
		ft_exit("Too few collectibles to start the game.");
	ft_checkwalls(res->map.m, res->map.h, res->map.w);
	free(line);
	close(fd);
}

int	ft_getmapheight(char *mappath)
{
	int		fd;
	char	*line;
	int		height;
	int		r;
	int		exit;

	height = 0;
	exit = 0;
	fd = open(mappath, O_RDONLY);
	line = NULL;
	while (1)
	{
		r = get_next_line(fd, &line);
		height++;
		if (ft_strchr(line, 'E'))
			exit = 1;
		if (!r)
			break ;
	}
	if (!exit)
		ft_exit("No exit present on the map.");
	free(line);
	close(fd);
	return (height);
}

int	ft_getmapwidth(char *mappath)
{
	int		fd;
	char	*line;
	int		width;
	int		r;

	width = 0;
	fd = open(mappath, O_RDONLY);
	while (1)
	{
		r = get_next_line(fd, &line);
		if (!(ft_ismaprow(line)))
			ft_exit("Invalid map row.");
		if (!width)
			width = ft_strlen(line);
		if (ft_strlen(line) != width)
			ft_exit("The map must be rectangular.");
		if (!r)
			break ;
	}
	free(line);
	close(fd);
	return (width);
}

static void	ft_setmatrixentry(char *line, t_parsed *res, int x, int i)
{
	if (*(line + i) == '0')
		res->map.m[x][i] = '0';
	else if (*(line + i) == '1')
		res->map.m[x][i] = '1';
	else if (*(line + i) == 'C')
	{
		res->player.goal++;
		res->map.m[x][i] = 'C';
	}
	else if (*(line + i) == 'E')
	{
		ft_initexit(res, x, i);
		res->map.m[x][i] = 'E';
	}
	else if (*(line + i) == 'P')
	{
		ft_initplayer(res, x, i);
		res->map.m[x][i] = 'P';
	}
	else if (*(line + i) == 'F')
	{
		res->map.m[x][i] = 'F';
	}
}

void	ft_writerow(char *line, t_parsed *res, int x)
{
	int	i;

	i = 0;
	while (*(line + i))
	{
		ft_setmatrixentry(line, res, x, i);
		i++;
	}
}
