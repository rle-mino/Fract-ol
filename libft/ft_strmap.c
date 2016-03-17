/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:56:31 by rle-mino          #+#    #+#             */
/*   Updated: 2015/12/14 18:24:54 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	return (s2);
}
