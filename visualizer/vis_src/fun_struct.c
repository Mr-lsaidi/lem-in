/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 23:16:48 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:04:26 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

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

t_q		*new_q(int id)
{
	t_q *q;

	if (!(q = (t_q*)malloc(sizeof(t_q))))
		return (NULL);
	q->id = id;
	q->room = NULL;
	q->next = NULL;
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

void	add_v(t_v **v, t_v *new)
{
	new->next = *v;
	*v = new;
}
