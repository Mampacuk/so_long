/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:11:44 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 19:11:45 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_parsed *res)
{
	if (res->state)
	{
		ft_receiveinput1(res);
		ft_receiveinput2(res);
		ft_receiveinput3(res);
		ft_receiveinput4(res);
	}
	res->i = 0;
	while (res->i < res->map.h)
	{
		res->j = 0;
		while (res->j < res->map.w)
		{
			ft_mlx_draw_unit(res, res->i, res->j);
			ft_animatefire(res);
			res->j++;
		}
		res->i++;
	}
	mlx_put_image_to_window(res->scr.mlx, res->scr.win, res->scr.img.ptr, 0, 0);
	ft_putmoves(res);
	mlx_do_sync(res->scr.mlx);
	return (0);
}

void	ft_putmoves(t_parsed *res)
{
	char	*num;
	char	*line;

	num = ft_itoa(res->player.moves);
	line = ft_strjoin("Move Count: ", num);
	mlx_string_put(res->scr.mlx, res->scr.win, 10, 10, 0xFFFFFF, line);
	free(line);
	free(num);
}

void	ft_animatefire(t_parsed *res)
{
	if ((double)(clock()) / CLOCKS_PER_SEC - res->time
		>= (double)1 / 10)
	{
		res->frame++;
		res->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (res->frame > 39)
		res->frame = 0;
}
