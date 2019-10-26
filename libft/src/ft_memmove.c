/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:53:42 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/09 10:23:32 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*tmp;

	tmp = (char*)malloc(n * sizeof(*tmp));
	if (!tmp)
		return (NULL);
	d = (char*)dest;
	s = (const char*)src;
	ft_memcpy(tmp, s, n);
	ft_memcpy(d, tmp, n);
	free(tmp);
	return (d);
}
