/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:57:53 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/09 12:07:46 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	int			j;

	i = -1;
	j = -1;
	while (++i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
			j = i;
	}
	if (j >= 0)
		return ((char*)s + j);
	return (NULL);
}
