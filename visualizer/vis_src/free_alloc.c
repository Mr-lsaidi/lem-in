/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:28:15 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:03:59 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	free_mx(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_rooms(t_room **rms)
{
	t_room	*room;
	t_room	*tmp;

	room = *rms;
	while (room)
	{
		tmp = room->next;
		free(room);
		room = tmp;
	}
}

void	free_v(t_v **lst)
{
	t_v		*v;
	t_v		*tmp;

	v = *lst;
	while (v)
	{
		tmp = v->next;
		free(v->name);
		free_rooms(&v->rooms);
		free(v);
		v = tmp;
	}
}

void	free_q(t_q **lst)
{
	t_q		*q;
	t_q		*tmp;

	q = *lst;
	while (q)
	{
		tmp = q->next;
		free(q);
		q = tmp;
	}
}

void	free_lem(t_lem **lem)
{
	t_lem	*lm;

	lm = *lem;
	free(lm->start);
	free(lm->end);
	free(lm->hp[0]->name);
	free_rooms(&lm->hp[0]->rooms);
	free(lm->hp[0]);
	free(lm->hp[1]->name);
	free_rooms(&lm->hp[1]->rooms);
	if (lm->visited)
		free(lm->visited);
	free(lm->hp[1]);
	free(lm->hp);
	free(lm);
}
