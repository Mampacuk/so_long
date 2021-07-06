/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:06:36 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/06 19:06:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_parsed	ft_parser(char *mappath)
{
	t_parsed	res;

	ft_initparser(&res);
	ft_getworldmap(mappath, &res);
	ft_loadtextures1(&res);
	ft_loadtextures2(&res);
	ft_loadtextures3(&res);
	ft_loadtextures4(&res);
	ft_setunitsize(&res);
	return (res);
}
