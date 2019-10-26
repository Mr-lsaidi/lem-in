/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <said.bahaddi@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:46:21 by sbahaddi          #+#    #+#             */
/*   Updated: 2018/10/07 16:21:27 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		src_length;
	char	*tmp;

	i = 0;
	src_length = ft_strlen(s);
	tmp = (char*)malloc(sizeof(*tmp) * (src_length + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < src_length)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[src_length] = '\0';
	return (tmp);
}
