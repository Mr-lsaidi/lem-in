/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:15:18 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 17:23:00 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_groupe	*new_groupe(void)
{
	t_groupe	*groupe;

	if (!(groupe = (t_groupe*)malloc(sizeof(t_groupe))))
		malloc_error();
	groupe->ninst = 2147483647;
	groupe->paths = NULL;
	groupe->next = NULL;
	return (groupe);
}

void		add_groupe(t_groupe **grp, t_groupe *new)
{
	new->next = *grp;
	*grp = new;
}
