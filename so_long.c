/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:16:30 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 19:16:31 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *str)
{
	write(1, "[so_long] ", 10);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_parsed	res;

	if (argc > 2 || argc == 1)
		ft_exit("Invalid number of arguments.");
	if (!(ft_check_extension(argv[1], ".ber")))
		ft_exit("Invalid file format.");
	res = ft_parser(argv[1]);
	res.scr.win = mlx_new_window(res.scr.mlx, res.unitsize * res.map.w,
			res.unitsize * res.map.h, "so long!");
	res.scr.img.ptr = mlx_new_image(res.scr.mlx,
			res.unitsize * res.map.w, res.unitsize * res.map.h);
	res.scr.img.addr = mlx_get_data_addr(res.scr.img.ptr,
			&res.scr.img.bpp, &res.scr.img.linelen, &res.scr.img.endian);
	mlx_hook(res.scr.win, 2, 1L << 0, ft_mlx_pressed, &(res.keys));
	mlx_hook(res.scr.win, 3, 1L << 1, ft_mlx_released, &(res.keys));
	mlx_loop_hook(res.scr.mlx, ft_render, &res);
	mlx_loop(res.scr.mlx);
}
