/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:21:49 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 15:19:09 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *src1;
	unsigned char *src2;

	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (*src1 != '\0' && *src2 != '\0')
	{
		if (*src1 != *src2)
		{
			return (*src1 - *src2);
		}
		src1++;
		src2++;
	}
	if (*src1 != '\0')
	{
		return (*src1);
	}
	if (*src2 != '\0')
	{
		return (-*src2);
	}
	return (0);
}
