/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_functs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:15:10 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 17:23:20 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dlt_q(t_q **q)
{
	t_q	*current;
	t_q	*tmp;

	current = *q;
	if (current)
	{
		tmp = current->next;
		free(current);
		*q = tmp;
	}
}

t_q		*new_q(int id, int in)
{
	t_q *q;

	if (!(q = (t_q*)malloc(sizeof(t_q))))
		malloc_error();
	q->id = id;
	q->room = NULL;
	q->next = NULL;
	q->in = in;
	return (q);
}

void	add_q(t_q **q, t_q *new)
{
	t_q	*tmp;

	tmp = *q;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_qrm(t_q **q, t_q *new, t_room *room)
{
	t_q	*tmp;

	tmp = *q;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->room = room;
}
