/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 23:05:39 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:04:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

t_room		*new_room(int id)
{
	t_room		*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	room->id = id;
	room->w = 1;
	room->way = 1;
	room->parent = NULL;
	room->next = NULL;
	room->id_ant = 0;
	room->is_ant = 0;
	return (room);
}

void		update_wieght(t_lem **lem)
{
	t_lem	*lm;
	t_room	*room;

	lm = *lem;
	room = lm->hp[0]->rooms;
	while (room)
	{
		room->w = 2;
		room = room->next;
	}
}

t_v			*new_v(char *name, int x, int y, int id)
{
	t_v *v;

	if (!(v = (t_v*)malloc(sizeof(t_v))))
		return (NULL);
	v->name = ft_strdup(name);
	v->x = x;
	v->y = y;
	v->id = id;
	v->next = NULL;
	v->rooms = NULL;
	v->lvl = 0;
	v->visited = 0;
	v->visited2 = 0;
	v->parent = -1;
	v->in = 1;
	v->nb_rooms = 0;
	v->ant = 0;
	v->id_ant = 0;
	return (v);
}
