/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:51:01 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 18:51:02 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_triggervictory(t_parsed *res)
{
	res->scr.victory = mlx_new_window(res->scr.mlx, res->texwin.width,
			res->texwin.height, "so long... and thanks for all the fish!");
	mlx_hook(res->scr.victory, 2, 1L << 0, ft_mlx_pressed, &res->keys);
	mlx_put_image_to_window(res->scr.mlx, res->scr.victory,
		res->texwin.ptr, 0, 0);
	res->state = 0;
}

void	ft_triggerloss(t_parsed *res)
{
	res->scr.loss = mlx_new_window(res->scr.mlx, res->texloss.width,
			res->texloss.height, "YOU SUCK");
	mlx_hook(res->scr.loss, 2, 1L << 0, ft_mlx_pressed, &res->keys);
	mlx_put_image_to_window(res->scr.mlx, res->scr.loss,
		res->texloss.ptr, 0, 0);
	res->state = 0;
}

int	ft_check_extension(char *path, char *ext)
{
	int	pathlen;
	int	extlen;

	pathlen = ft_strlen(path);
	extlen = ft_strlen(ext);
	if (!(extlen == 4) || !(pathlen > 4))
		return (0);
	return (*(path + pathlen - 1) == *(ext + extlen - 1)
		&& *(path + pathlen - 2) == *(ext + extlen - 2)
		&& *(path + pathlen - 3) == *(ext + extlen - 3)
		&& *(path + pathlen - 4) == *(ext + extlen - 4));
}
