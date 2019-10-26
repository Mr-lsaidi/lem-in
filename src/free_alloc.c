/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:28:15 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 20:28:48 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_mx(char ***tab)
{
	int		i;
	char	**mx;

	i = -1;
	mx = *tab;
	while (mx[++i])
	{
		free(mx[i]);
		mx[i] = NULL;
	}
	free(mx);
	mx = NULL;
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
		room = NULL;
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
		v->name = NULL;
		free_rooms(&v->rooms);
		free(v);
		v = NULL;
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
		q = NULL;
		q = tmp;
	}
}

void	free_lem(t_lem **lem)
{
	t_lem	*lm;

	lm = *lem;
	if (lm->start && lm->hp)
	{
		free(lm->hp[0]->name);
		free_rooms(&lm->hp[0]->rooms);
		free(lm->hp[0]);
	}
	if (lm->end && lm->hp)
	{
		free(lm->hp[1]->name);
		free_rooms(&lm->hp[1]->rooms);
		free(lm->hp[1]);
	}
	if (lm->split)
		free_mx(&lm->split);
	free(lm->start);
	free(lm->end);
	free(lm->hp);
	free_file(lem);
	free(lm);
}
