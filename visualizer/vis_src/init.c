/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:51:09 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/16 18:04:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void		free_split(t_spliter **spl)
{
	t_spliter	*room;
	t_spliter	*tmp;

	room = *spl;
	while (room)
	{
		tmp = room->next;
		free(room);
		room = tmp;
	}
}

static int		get_nbr_lvl(t_spliter **vis_splite, t_lem *lem, int lvl)
{
	int			i;
	int			nbr;
	t_spliter	*new_split;

	nbr = 0;
	i = -1;
	while (++i < lem->v_ln)
	{
		if (lvl == lem->hp[i]->lvl)
		{
			if (!(new_split = malloc(sizeof(new_split))))
				return (0);
			nbr++;
			new_split->id = i;
			new_split->next = (*vis_splite);
			(*vis_splite) = new_split;
		}
	}
	return (nbr);
}

void			start_vis(t_spliter **vis_splite, t_vis *vis, t_lem **lem)
{
	int			nb_lvl;
	int			y;

	while (++(*lem)->cmp < (*lem)->v_ln)
	{
		vis->moyenn_x = vis->width;
		vis->moyenn_y = vis->height + vis->height_correct;
		nb_lvl = get_nbr_lvl(vis_splite, *lem, (*lem)->cmp);
		vis->moyenn_y = vis->moyenn_y / (*lem)->hp[1]->lvl;
		if (nb_lvl)
		{
			vis->moyenn_x = vis->moyenn_x / (nb_lvl + 1);
			y = vis->moyenn_y * ((*lem)->hp[1]->lvl - vis->max_lvl);
			while (nb_lvl > 0)
			{
				(*lem)->hp[(*vis_splite)->id]->x = vis->moyenn_x * nb_lvl;
				(*lem)->hp[(*vis_splite)->id]->y = y;
				nb_lvl--;
				(*vis_splite) = (*vis_splite)->next;
			}
			vis->max_lvl--;
		}
		free_split(vis_splite);
	}
}

void			small_big_init(t_vis *vis, t_lem **lem)
{
	if ((*lem)->v_ln <= 50)
	{
		vis->rooms_size_x = 50;
		vis->rooms_size_y = 50;
		vis->ant_size_x = 40;
		vis->ant_size_y = 25;
		vis->line_radian = 2;
		(*lem)->frame_ants = 320;
	}
	else
	{
		vis->rooms_size_x = 10;
		vis->rooms_size_y = 10;
		vis->ant_size_x = 30;
		vis->ant_size_y = 18;
		vis->line_radian = 1;
		(*lem)->frame_ants = 400;
	}
}
