/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:33:06 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/18 18:11:26 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void		init_lem(t_lem **lem)
{
	t_ants		*ants;
	t_lem		*lm;

	lm = *lem;
	lm->v = NULL;
	lm->start = NULL;
	lm->v_ln = 0;
	lm->se = 0;
	lm->xoffset = 0;
	lm->yoffset = 0;
	lm->scale = 1;
	lm->xrel = 0;
	lm->yrel = 0;
	lm->nb_ants_ended = 0;
	lm->nb_ants_pass = 0;
	ants = NULL;
	lm->cmp = -1;
	lm->num = 0;
}

int				size(t_ants *ants)
{
	int		size;

	size = 0;
	while (ants)
	{
		size++;
		ants = ants->next;
	}
	return (size - 1);
}

static void		start(t_lem *lem, t_vis *vis)
{
	t_inst		*inst;

	read_rest(lem, &inst);
	drow_ants(inst, vis, lem);
}

int				main(void)
{
	t_lem		*lem;
	t_spliter	*vis_split;
	t_ants		*ants;
	t_vis		vis;

	vis_split = NULL;
	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		return (0);
	init_lem(&lem);
	if (!read_file(&lem, vis_split, &vis))
	{
		free_v(&lem->v);
		free_lem(&lem);
		ft_printf("ERROR\n");
		exit(0);
	}
	lem->hp[0]->y += vis.rooms_size_x / 2;
	start(lem, &vis);
	deletelist(&ants);
	return (0);
}
