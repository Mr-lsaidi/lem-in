/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqtr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:54:15 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/12 15:55:18 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqtr(double num)
{
	double root;
	double root_n;

	root = 0.0;
	root_n = 1.0;
	while (root_n != root)
	{
		root = root_n;
		root_n = (root + num / root) / 2;
	}
	return (root);
}
