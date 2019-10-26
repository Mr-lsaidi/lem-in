/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 23:05:39 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 17:23:28 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(int id)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		malloc_error();
	room->id = id;
	room->way = 1;
	room->in = 1;
	room->is_ant = 0;
	room->id_ant = 0;
	room->parent = NULL;
	room->next = NULL;
	room->prev = NULL;
	return (room);
}

void	add_vpath(t_path **path, int id)
{
	t_room		*rooms;

	rooms = new_room(id);
	rooms->next = (*path)->rooms;
	if ((*path)->rooms)
		(*path)->rooms->prev = rooms;
	(*path)->rooms = rooms;
}

void	add_pathroom(t_path **pth, t_room *rm)
{
	t_room	*room;

	room = (*pth)->rooms;
	if (room)
	{
		while (room->next)
			room = room->next;
		room->next = rm;
	}
	else
		(*pth)->rooms = rm;
	(*pth)->v_nb++;
}

void	add_path(t_path **pth, t_path *new)
{
	t_path	*path;
	t_path	*next;
	t_path	*node;

	node = NULL;
	path = *pth;
	while (path)
	{
		if (new->v_nb > path->v_nb)
			node = path;
		else
			break ;
		path = path->next;
	}
	if (node)
	{
		next = node->next;
		node->next = new;
		new->next = next;
	}
	else
	{
		new->next = (*pth);
		*pth = new;
	}
}

t_path	*new_path(int nb)
{
	t_path		*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		malloc_error();
	path->v_nb = nb;
	path->nb_ant = 0;
	path->next = NULL;
	path->rooms = NULL;
	path->capacity = 0;
	return (path);
}
