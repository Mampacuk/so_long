/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:06:15 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 19:06:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setup_map(t_parsed *res, char *mappath)
{
	res->map.h = ft_getmapheight(mappath);
	res->map.w = ft_getmapwidth(mappath);
	if (res->map.h < 4 || res->map.w < 4)
		ft_exit("Dimensions cannot be less than 4.");
	res->i = 0;
	res->map.m = malloc(res->map.h * sizeof(char *));
	while (res->i < res->map.h)
		res->map.m[(res->i)++] = ft_calloc(res->map.w, sizeof(char));
}

void	ft_initplayer(t_parsed *res, int posx, int posy)
{
	if (!(res->player.x < 0 && res->player.y < 0))
		ft_exit("Multiple players are not permitted.");
	res->player.x = posx;
	res->player.y = posy;
}

void	ft_initexit(t_parsed *res, int posx, int posy)
{
	if (!(res->exit.x < 0 && res->exit.y < 0))
		ft_exit("Multiple exits are not permitted.");
	res->exit.x = posx;
	res->exit.y = posy;
}

void	ft_initparser(t_parsed *res)
{
	res->scr.mlx = mlx_init();
	res->frame = 0;
	res->exit.x = -1;
	res->exit.y = -1;
	res->player.x = -1;
	res->player.y = -1;
	res->player.items = 0;
	res->player.goal = 0;
	res->player.moves = 0;
	res->time = 0;
	res->state = 1;
	res->keys.check = 1;
}

void	ft_setunitsize(t_parsed *res)
{
	int	nativeh;
	int	nativew;

	mlx_get_screen_size(res->scr.mlx, &nativew, &nativeh);
	if (res->map.h >= res->map.w)
		res->unitsize = (int)(nativeh * 0.80 / res->map.h);
	else
		res->unitsize = (int)(nativew * 0.80 / res->map.w);
}
