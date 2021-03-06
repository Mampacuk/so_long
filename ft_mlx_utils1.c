/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:45:59 by aisraely          #+#    #+#             */
/*   Updated: 2022/07/11 21:19:08 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_pixel_set(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->linelen + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->linelen + x * (image->bpp / 8));
	return (*(unsigned int *)dst);
}

void	ft_mlx_draw_unit(t_parsed *res, int i, int j)
{
	res->x = 0;
	while (res->x < res->unitsize)
	{
		res->y = 0;
		while (res->y < res->unitsize)
		{
			if (res->player.x == res->exit.x
				&& res->player.y == res->exit.y
				&& i == res->player.x && j == res->player.y)
				res->sprite = res->texexit;
			else
				res->sprite = res->texfloor;
			ft_putspritepixel(res, i, j);
			ft_selectsprite(res, i, j);
			ft_putspritepixel(res, i, j);
			res->y++;
		}
		res->x++;
	}
}

void	ft_selectsprite(t_parsed *res, int i, int j)
{
	if (res->map.m[i][j] == '1')
		res->sprite = res->texwall;
	else if (res->map.m[i][j] == 'C')
		res->sprite = res->texitem;
	else if (res->map.m[i][j] == 'P')
		res->sprite = res->texpl;
	else if (res->map.m[i][j] == 'E')
		res->sprite = res->texexit;
	else if (res->map.m[i][j] == 'F')
		res->sprite = res->texfire[res->frame];
}

void	ft_putspritepixel(t_parsed *res, int i, int j)
{
	res->texx = (int)((float)res->y / res->unitsize * res->sprite.width);
	res->texy = (int)((float)res->x / res->unitsize * res->sprite.height);
	if (res->map.m[i][j] != 'F')
	{
		if (ft_mlx_pixel_get(&res->sprite, res->texx, res->texy) != 0xFF000000)
			ft_mlx_pixel_set(&res->scr.img, j * res->unitsize + res->y,
				i * res->unitsize
				+ res->x, ft_mlx_pixel_get(&res->sprite, res->texx, res->texy));
	}
	else
	{
		ft_mlx_pixel_set(&res->scr.img, j * res->unitsize + res->y,
			i * res->unitsize
			+ res->x, ft_mlx_pixel_get(&res->sprite, res->texx, res->texy));
	}
}
