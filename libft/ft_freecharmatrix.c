/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecharmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:23:16 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/10 13:23:17 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freecharmatrix(char **matrix)
{
	int	i;

	i = ft_charmatrixlen(matrix) - 1;
	while (i >= 0)
		free(matrix[i--]);
}
