/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 23:10:41 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/01 23:10:43 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s1;

	s1 = s;
	while (n != 0)
	{
		*s1 = c;
		s1++;
		n--;
	}
	return (s);
}
