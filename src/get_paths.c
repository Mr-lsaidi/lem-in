/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:20:04 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/20 17:22:57 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	update_graph(t_lem **lem, t_path *path)
{
	t_room	*rooms;
	t_room	*rm;

	rooms = path->rooms;
	while (rooms->next)
	{
		rm = (*lem)->hp[rooms->id]->rooms;
		if (rooms->id != 0)
			(*lem)->hp[rooms->id]->in = 0;
		while (rm)
		{
			if (rooms->next->id == rm->id)
			{
				rm->way = 0;
				break ;
			}
			rm = rm->next;
		}
		rooms = rooms->next;
	}
}

static void	q_in(t_lem **lem, t_q **lstq)
{
	t_room	*room;

	room = (*lem)->hp[(*lstq)->id]->rooms;
	while (room)
	{
		if (((*lem)->hp[room->id]->visited != (*lem)->vstd_cmp + 1)
		&& get_way(lem, (*lstq)->id, room->id) == 1)
		{
			if ((*lem)->hp[(*lstq)->id]->in == 1)
				(*lem)->hp[room->id]->visited = (*lem)->vstd_cmp + 1;
			(*lstq)->id != 0 ? room->parent = (*lstq)->room : NULL;
			if (room->id == 1)
			{
				(*lem)->endroom = room;
				(*lem)->ks = 0;
				break ;
			}
			if ((*lem)->hp[(*lstq)->id]->in == 0
			&& (get_way(lem, room->id, (*lstq)->id) == 0))
				add_qrm(lstq, new_q(room->id, 1), room);
			else
				add_qrm(lstq, new_q(room->id, (*lem)->hp[room->id]->in), room);
		}
		room = room->next;
	}
}

static void	q_out(t_lem **lem, t_q **lstq)
{
	t_room	*room;
	t_q		*q;

	room = (*lem)->hp[(*lstq)->id]->rooms;
	while (room)
	{
		if (get_way(lem, (*lstq)->id, room->id) == 1
		&& get_way(lem, room->id, (*lstq)->id) == 0)
		{
			(*lem)->hp[room->id]->visited = (*lem)->vstd_cmp + 1;
			if ((*lstq)->id != 0)
				room->parent = (*lstq)->room;
			if (room->id == 1)
			{
				(*lem)->endroom = room;
				(*lem)->ks = 0;
				break ;
			}
			q = new_q(room->id, 1);
			add_qrm(lstq, q, room);
		}
		room = room->next;
	}
}

static void	link_bfs(t_lem **lem, t_q **lstq)
{
	if ((*lstq)->in == 1)
		q_in(lem, lstq);
	else
		q_out(lem, lstq);
}

void		get_paths(t_lem **lem)
{
	t_q		*q;
	t_path	*path;

	while ((*lem)->routes--)
	{
		(*lem)->ks = 1;
		(*lem)->vstd_cmp++;
		q = new_q(0, 0);
		q->in = 1;
		(*lem)->hp[q->id]->visited = (*lem)->vstd_cmp + 1;
		while (q && (*lem)->ks == 1)
		{
			link_bfs(lem, &q);
			dlt_q(&q);
		}
		free_q(&q);
		path = get_shrtpathroom(lem, (*lem)->endroom);
		if (path)
		{
			(*lem)->nb_paths++;
			update_graph(lem, path);
			free_paths(&path);
			make_paths(lem);
		}
	}
}
