/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 02:15:59 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 12:14:40 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		correct_capacity(t_lem **lem)
{
	t_path		*path;
	int			nb_ants;

	nb_ants = (*lem)->nbant;
	path = (*lem)->best_gp->paths;
	while (path)
	{
		if (path->capacity == 0)
			break ;
		else if (path->capacity <= nb_ants)
			nb_ants = nb_ants - path->capacity;
		else if (path->capacity > nb_ants)
		{
			path->capacity = nb_ants;
			nb_ants = 0;
		}
		path = path->next;
	}
}

static void		less_inst_gp(t_lem **lem)
{
	t_groupe	*groupe;
	t_groupe	*gp;
	int			min_instr;

	min_instr = (*lem)->groupes->ninst;
	groupe = (*lem)->groupes;
	while (groupe)
	{
		if (groupe->ninst <= min_instr)
		{
			min_instr = groupe->ninst;
			gp = groupe;
		}
		groupe = groupe->next;
	}
	(*lem)->best_gp = gp;
}

static void		leftover_ants(t_path **pth, int total_inst)
{
	t_path		*path;
	int			i;

	i = -1;
	path = *pth;
	while (path)
	{
		if (++i < total_inst)
			path->capacity++;
		path = path->next;
	}
}

void			nb_ants_path(t_lem **lem)
{
	int			total_inst;
	t_path		*path;

	less_inst_gp(lem);
	path = (*lem)->best_gp->paths;
	total_inst = 0;
	while (path)
	{
		if ((*lem)->best_gp->ninst - (path->v_nb - 2) >= 0)
			path->capacity = (*lem)->best_gp->ninst - (path->v_nb - 2);
		else
			break ;
		total_inst += path->capacity;
		path = path->next;
	}
	total_inst = (*lem)->nbant - total_inst;
	leftover_ants(&(*lem)->best_gp->paths, total_inst);
	correct_capacity(lem);
}
