/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:53:10 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 18:53:12 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_loadtextures1(t_parsed *res)
{
	res->texwall.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/wall.xpm",
			&res->texwall.width, &res->texwall.height);
	if (!(res->texwall.ptr))
		ft_exit("Failed to allocate memory for the wall texture.");
	res->texwall.addr = mlx_get_data_addr(res->texwall.ptr, &res->texwall.bpp,
			&res->texwall.linelen, &res->texwall.endian);
	res->texpl.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/player.xpm",
			&(res->texpl.width), &(res->texpl.height));
	if (!(res->texpl.ptr))
		ft_exit("Failed to allocate memory for the player texture.");
	res->texpl.addr = mlx_get_data_addr(res->texpl.ptr, &res->texpl.bpp,
			&res->texpl.linelen, &res->texpl.endian);
}

void	ft_loadtextures2(t_parsed *res)
{
	res->texitem.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/soy.xpm",
			&(res->texitem.width), &(res->texitem.height));
	if (!(res->texitem.ptr))
		ft_exit("Failed to allocate memory for the item texture.");
	res->texitem.addr = mlx_get_data_addr(res->texitem.ptr, &res->texitem.bpp,
			&res->texitem.linelen, &res->texitem.endian);
	res->texexit.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/exit.xpm",
			&(res->texexit.width), &(res->texexit.height));
	if (!(res->texexit.ptr))
		ft_exit("Failed to allocate memory for the exit texture.");
	res->texexit.addr = mlx_get_data_addr(res->texexit.ptr, &res->texexit.bpp,
			&res->texexit.linelen, &res->texexit.endian);
	res->texfloor.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/floor.xpm",
			&(res->texfloor.width), &(res->texfloor.height));
	if (!(res->texfloor.ptr))
		ft_exit("Failed to allocate memory for the floor texture.");
	res->texfloor.addr = mlx_get_data_addr(res->texfloor.ptr,
			&res->texfloor.bpp, &res->texfloor.linelen, &res->texfloor.endian);
}

void	ft_loadtextures3(t_parsed *res)
{
	char	*temp;
	char	*frame;
	char	*xpm;

	res->texfire = malloc(40 * sizeof(t_img));
	res->i = 0;
	while (res->i < 40)
	{
		temp = ft_itoa(res->i);
		frame = ft_strjoin("img/fire/", temp);
		xpm = ft_strjoin(frame, ".xpm");
		res->texfire[res->i].ptr = mlx_xpm_file_to_image(res->scr.mlx, xpm,
				&(res->texfire[res->i].width), &(res->texfire[res->i].height));
		if (!(res->texfire[res->i].ptr))
			ft_exit("Failed to allocate memory for a fire frame.");
		res->texfire[res->i].addr = mlx_get_data_addr(res->texfire[res->i].ptr,
				&res->texfire[res->i].bpp, &res->texfire[res->i].linelen,
				&res->texfire[res->i].endian);
		free(xpm);
		free(frame);
		free(temp);
		res->i++;
	}
}

void	ft_loadtextures4(t_parsed *res)
{
	res->texwin.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/victory.xpm",
			&res->texwin.width, &res->texwin.height);
	if (!(res->texwin.ptr))
		ft_exit("Failed to allocate memory for the victory screen.");
	res->texwin.addr = mlx_get_data_addr(res->texwin.ptr, &res->texwin.bpp,
			&res->texwin.linelen, &res->texwin.endian);
	res->texloss.ptr = mlx_xpm_file_to_image(res->scr.mlx, "img/loss.xpm",
			&res->texloss.width, &res->texloss.height);
	if (!(res->texloss.ptr))
		ft_exit("Failed to allocate memory for the loss screen.");
	res->texloss.addr = mlx_get_data_addr(res->texloss.ptr, &res->texloss.bpp,
			&res->texloss.linelen, &res->texloss.endian);
}
