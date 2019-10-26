/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:58:24 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/08 17:57:19 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		length;

	i = 0;
	j = 0;
	length = ft_strlen(l);
	if (*l == '\0')
		return ((char *)b);
	while (b[i] != '\0' && len-- >= length)
	{
		while (l[j] == b[i + j])
		{
			if (j == length - 1)
				return ((char *)b + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
