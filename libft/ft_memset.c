/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:51:56 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/03 17:33:26 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			j;
	unsigned char	*d;

	d = (unsigned char*)b;
	j = 0;
	while (j < len)
	{
		d[j] = c;
		j++;
	}
	return (d);
}
