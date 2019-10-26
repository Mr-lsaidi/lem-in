/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 23:16:48 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 19:05:48 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_v		*new_v(char *name, int x, int y, int id)
{
	t_v *v;

	if (!(v = (t_v*)malloc(sizeof(t_v))))
		malloc_error();
	v->name = ft_strdup(name);
	v->x = x;
	v->y = y;
	v->id = id;
	v->next = NULL;
	v->rooms = NULL;
	v->lvl = 0;
	v->visited = 0;
	v->parent = -1;
	v->in = 1;
	v->nb_rooms = 0;
	return (v);
}

void	add_v(t_v **v, t_v *new)
{
	new->next = *v;
	*v = new;
}
