/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 23:04:21 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/13 11:35:55 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path			*get_shortpath(t_lem **lem)
{
	t_path	*path;
	int		i;

	path = NULL;
	if ((*lem)->hp[1]->parent != -1)
	{
		path = new_path(1);
		add_vpath(&path, 1);
		i = 1;
		while (i != 0)
		{
			i = (*lem)->hp[i]->parent;
			path->v_nb++;
			add_vpath(&path, i);
		}
	}
	(*lem)->hp[1]->parent = -1;
	return (path);
}

static void		bfs_path(t_lem **lem, t_q **lstq)
{
	t_room	*room;

	room = (*lem)->hp[(*lstq)->id]->rooms;
	while (room)
	{
		if (((*lem)->hp[room->id]->visited != (*lem)->vstd_cmp + 1)
		&& get_way(lem, (*lstq)->id, room->id) == 0
		&& get_way(lem, room->id, (*lstq)->id) == 1)
		{
			(*lem)->hp[room->id]->visited = (*lem)->vstd_cmp + 1;
			(*lem)->hp[room->id]->parent = (*lstq)->id;
			if (room->id == 1)
			{
				(*lem)->ks = 0;
				break ;
			}
			add_q(lstq, new_q(room->id, 0));
		}
		room = room->next;
	}
}

static void		reset_visited(t_lem **lem, t_groupe *group)
{
	t_path		*path;
	t_room		*room;

	path = group->paths;
	(*lem)->vstd_cmp++;
	while (path)
	{
		room = path->rooms;
		while (room)
		{
			(*lem)->hp[room->id]->visited = (*lem)->vstd_cmp + 1;
			if (room->id != 0)
				(*lem)->hp[room->id]->in = 0;
			room = room->next;
		}
		path = path->next;
	}
	(*lem)->hp[1]->visited = (*lem)->vstd_cmp;
}

static void		start_q(t_lem **lem, t_q **lstq)
{
	while ((*lstq) && (*lem)->ks == 1)
	{
		bfs_path(lem, lstq);
		dlt_q(lstq);
	}
	free_q(lstq);
}

void			make_paths(t_lem **lem)
{
	int			nb_paths;
	t_q			*q;
	t_path		*path;
	t_groupe	*group;

	nb_paths = (*lem)->nb_paths;
	group = new_groupe();
	(*lem)->vstd_cmp++;
	while (nb_paths--)
	{
		(*lem)->ks = 1;
		q = new_q(0, 0);
		start_q(lem, &q);
		path = get_shortpath(lem);
		if (path)
		{
			add_path(&group->paths, path);
			reset_visited(lem, group);
		}
	}
	add_groupe(&(*lem)->groupes, group);
}
