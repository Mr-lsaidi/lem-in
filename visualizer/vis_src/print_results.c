/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:17:38 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/16 18:04:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void			deletelist(t_ants **ants)
{
	t_ants	*current;
	t_ants	*next;

	current = (*ants);
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	(*ants) = NULL;
}

t_inst			*create_node(void)
{
	t_inst		*newnode;

	if (!(newnode = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	newnode->ants = NULL;
	newnode->next = NULL;
	return (newnode);
}

void			ant_inst(t_inst **ins, t_inst *new)
{
	t_inst	*head;

	head = *ins;
	if (*ins == NULL)
	{
		(*ins) = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}
