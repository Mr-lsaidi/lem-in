/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:35:38 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/09 11:52:55 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			dest_length;
	size_t			res;

	dest_length = ft_strlen(dest);
	res = ft_strlen(src);
	if (size <= dest_length)
		res += size;
	else
		res += dest_length;
	i = 0;
	while (src[i] != '\0' && dest_length + 1 < size)
	{
		dest[dest_length] = src[i];
		dest_length++;
		i++;
	}
	dest[dest_length] = '\0';
	return (res);
}
