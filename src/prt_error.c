/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:42:48 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 20:34:55 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	malloc_error(void)
{
	ft_printf("ERROR malloc\n");
	exit(1);
}

void	print_error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int		check_loop(t_lem **lem)
{
	t_room	*room;

	room = (*lem)->hp[1]->rooms;
	if (room)
		return (1);
	return (0);
}
