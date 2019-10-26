/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:28:58 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:31:46 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_vis(t_groupe *groupe)
{
	t_path		*path;
	t_room		*rooms;
	int			tmp;

	path = groupe->paths;
	while (path)
	{
		if (path->capacity > 0)
		{
			tmp = 0;
			rooms = path->rooms->next;
			while (rooms)
			{
				if (rooms->id_ant)
					ft_printf("%d %d\n", tmp, rooms->id);
				tmp = rooms->id;
				rooms = rooms->next;
			}
		}
		path = path->next;
	}
	ft_printf("\n");
}

static void	print_result(t_lem **lem, t_groupe *group)
{
	t_path		*path;
	t_room		*rooms;

	path = group->paths;
	while (path)
	{
		if (path->capacity > 0)
		{
			rooms = path->rooms->next;
			while (rooms->next)
				rooms = rooms->next;
			while (rooms)
			{
				if (rooms->id_ant)
					ft_printf("L%d-%s ", rooms->id_ant,
					(*lem)->hp[rooms->id]->name);
				rooms = rooms->prev;
			}
		}
		path = path->next;
	}
	ft_printf("\n");
}

void		select_solution(t_lem **lem, t_groupe *group)
{
	if ((*lem)->is_visu == 1)
		print_vis(group);
	else
		print_result(lem, group);
}
