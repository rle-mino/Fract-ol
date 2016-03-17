/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:21:55 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/04 15:53:25 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		divt(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			i;
	int			j;

	j = 0;
	if (n == (-2147483648))
		return (ft_strdup("-2147483648"));
	i = divt(n);
	s = (char*)ft_memalloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		s[j] = '-';
	}
	j = i - 1;
	while (n > 9)
	{
		s[j] = (n % 10) + '0';
		n = n / 10;
		j--;
	}
	s[j] = n + '0';
	return (s);
}
