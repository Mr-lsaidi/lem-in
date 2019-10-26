/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:20:56 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/19 15:23:15 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*src1 == *src2 && n-- > 0)
	{
		src1++;
		src2++;
		if (n == 0)
			return (0);
	}
	if (*src1 != *src2)
	{
		return (*src1 - *src2);
	}
	return (0);
}
