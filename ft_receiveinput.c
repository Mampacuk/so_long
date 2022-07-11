/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receiveinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:09:49 by aisraely          #+#    #+#             */
/*   Updated: 2022/07/11 21:28:59 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_receiveinput1(t_parsed *res)
{
	if (res->keys.up && !res->keys.left && !res->keys.down && !res->keys.right)
	{
		if (!(res->map.m[res->player.x - 1][res->player.y] == '1'))
		{
			res->player.moves++;
			if (res->map.m[res->player.x - 1][res->player.y] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.m[res->player.x][res->player.y] = 'E';
			else
				res->map.m[res->player.x][res->player.y] = '0';
			res->player.x--;
			if (res->map.m[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.m[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.m[res->player.x][res->player.y] = 'P';
			res->keys.up = 0;
		}
	}
}

void	ft_receiveinput2(t_parsed *res)
{
	if (res->keys.left && !res->keys.right && !res->keys.down && !res->keys.up)
	{
		if (!(res->map.m[res->player.x][res->player.y - 1] == '1'))
		{
			res->player.moves++;
			if (res->map.m[res->player.x][res->player.y - 1] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.m[res->player.x][res->player.y] = 'E';
			else
				res->map.m[res->player.x][res->player.y] = '0';
			res->player.y--;
			if (res->map.m[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.m[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.m[res->player.x][res->player.y] = 'P';
			res->keys.left = 0;
		}
	}
}

void	ft_receiveinput3(t_parsed *res)
{
	if (res->keys.down && !res->keys.left && !res->keys.up && !res->keys.right)
	{
		if (!(res->map.m[res->player.x + 1][res->player.y] == '1'))
		{
			res->player.moves++;
			if (res->map.m[res->player.x + 1][res->player.y] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.m[res->player.x][res->player.y] = 'E';
			else
				res->map.m[res->player.x][res->player.y] = '0';
			res->player.x++;
			if (res->map.m[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.m[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.m[res->player.x][res->player.y] = 'P';
			res->keys.down = 0;
		}
	}
}

void	ft_receiveinput4(t_parsed *res)
{
	if (res->keys.right && !res->keys.up && !res->keys.down && !res->keys.left)
	{
		if (!(res->map.m[res->player.x][res->player.y + 1] == '1'))
		{
			res->player.moves++;
			if (res->map.m[res->player.x][res->player.y + 1] == 'C')
				res->player.items++;
			if (res->player.x == res->exit.x && res->player.y == res->exit.y)
				res->map.m[res->player.x][res->player.y] = 'E';
			else
				res->map.m[res->player.x][res->player.y] = '0';
			res->player.y++;
			if (res->map.m[res->player.x][res->player.y] == 'E'
				&& res->player.items >= res->player.goal)
				ft_triggervictory(res);
			else if (res->map.m[res->player.x][res->player.y] == 'F')
				ft_triggerloss(res);
			res->map.m[res->player.x][res->player.y] = 'P';
			res->keys.right = 0;
		}
	}
}
