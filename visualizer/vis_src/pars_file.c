/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:05:43 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 15:26:42 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int	read_nbant(t_lem **lem)
{
	t_lem	*lm;
	int		i;

	i = -1;
	lm = *lem;
	if (get_next_line(0, &lm->line) > 0)
		while (lm->line[++i])
			if (!(lm->line[i] >= '0' && lm->line[i] <= '9'))
				return (0);
	lm->nbant = ft_atoi(lm->line);
	if (lm->nbant <= 0)
		return (0);
	free(lm->line);
	return (1);
}

static int	fill_hp(t_lem **lem)
{
	t_lem	*lm;
	t_v		*v;
	int		i;

	i = 1;
	lm = *lem;
	v = lm->v;
	if (!(lm->hp = (t_v**)malloc(sizeof(t_v*) * (lm->v_ln + 1))))
		return (0);
	lm->hp[lm->v_ln] = 0;
	lm->hp[0] = new_v(lm->start, lm->xs, lm->ys, 0);
	lm->hp[1] = new_v(lm->end, lm->xe, lm->ye, 1);
	while (v)
	{
		lm->hp[++i] = v;
		lm->hp[i]->id = i;
		v = v->next;
	}
	return (1);
}

void		index_lvl(t_lem **lem)
{
	t_room	*rooms;
	t_q		*q;

	(*lem)->hp[0]->lvl = 1;
	q = new_q(0);
	while (q)
	{
		rooms = (*lem)->hp[q->id]->rooms;
		while (rooms)
		{
			if ((*lem)->hp[rooms->id]->lvl == 0)
			{
				(*lem)->hp[rooms->id]->lvl = (*lem)->hp[q->id]->lvl + 1;
				add_q(&q, new_q(rooms->id));
			}
			rooms = rooms->next;
		}
		dlt_q(&q);
	}
}

int			read_file(t_lem **lem, t_spliter *vis_split, t_vis *vis)
{
	t_lem	*lm;

	lm = *lem;
	if (!read_nbant(lem))
	{
		ft_printf("ERROR\n");
		exit(0);
	}
	if (!read_rooms(lem, 0))
	{
		free_v(&(*lem)->v);
		ft_printf("ERROR\n");
		exit(0);
	}
	lm->v_ln += 2;
	if (!fill_hp(lem) || !start_adlist(lem))
		return (0);
	index_lvl(&lm);
	init_vars(vis, &lm);
	init_tool(vis);
	lm->hp[1]->lvl = get_max_lvl(lm);
	vis->max_lvl = lm->hp[1]->lvl;
	start_vis(&vis_split, vis, &lm);
	return (1);
}
