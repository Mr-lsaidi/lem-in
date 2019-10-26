/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:13:12 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/18 18:13:24 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void			last_format2(t_ants **ants, int s_r, int f_r, t_lem **lm)
{
	double		x;
	double		y;
	t_ants		*new_ants;

	if (!(new_ants = (t_ants*)malloc(sizeof(t_ants))))
		return ;
	x = (*lm)->hp[s_r]->x - (*lm)->hp[f_r]->x;
	y = (*lm)->hp[s_r]->y - (*lm)->hp[f_r]->y;
	new_ants->addx = x / (*lm)->frame_ants;
	new_ants->addy = y / (*lm)->frame_ants;
	new_ants->x = (*lm)->hp[f_r]->x;
	new_ants->y = (*lm)->hp[f_r]->y;
	new_ants->rooms_id = f_r;
	new_ants->nextrooms_id = s_r;
	new_ants->next = (*ants);
	(*ants) = new_ants;
	new_ants = NULL;
}

void			read_rest(t_lem *lem, t_inst **inst)
{
	t_inst		*head;
	char		**split;

	head = create_node();
	while (get_next_line(0, &lem->line) > 0)
	{
		split = ft_strsplit(lem->line, ' ');
		if (split[0] != NULL)
		{
			last_format2(&head->ants, ft_atoi(split[1]),
			ft_atoi(split[0]), &lem);
			lem->num++;
		}
		else
		{
			ant_inst(inst, head);
			head = create_node();
		}
		free(lem->line);
	}
	ant_inst(inst, head);
}

void			drow_select_lines(t_ants *ants, t_lem *lem, t_vis *vis)
{
	vis->x2 = lem->scale * (lem->hp[ants->nextrooms_id]->x + \
	lem->xoffset - vis->width / 2) + vis->width / 2;
	vis->y2 = lem->scale * (lem->hp[ants->nextrooms_id]->y + \
	lem->yoffset - vis->height / 2) + vis->height / 2;
	vis->x1 = lem->scale * (lem->hp[ants->rooms_id]->x +\
		lem->xoffset - vis->width / 2) + vis->width / 2;
	vis->y1 = lem->scale * (lem->hp[ants->rooms_id]->y +\
	lem->yoffset - vis->height / 2) + vis->height / 2;
	thickLineColor(vis->renderer, vis->x1,
	vis->y1, vis->x2, vis->y2, vis->line_radian, 0xFF0090FF);
}

void			spesial_one(t_ants *ants, t_lem *lem, t_vis *vis, int *i)
{
	if ((int)ants->y != lem->hp[ants->nextrooms_id]->y &&
		(int)ants->x != lem->hp[ants->nextrooms_id]->x)
	{
		vis->ants.w = vis->ant_size_x;
		vis->ants.h = vis->ant_size_y;
		vis->ants.x = lem->scale * (ants->x + (lem->xoffset) -\
		vis->width / 2) + vis->width / 2 - (vis->ant_size_x / 2);
		vis->ants.y = lem->scale * (ants->y + (lem->yoffset) -
		vis->height / 2) + vis->height / 2 - (vis->ant_size_y / 2);
		SDL_RenderCopy(vis->renderer, vis->img_ant, NULL, &vis->ants);
		ants->x += ants->addx;
		ants->y += ants->addy;
	}
	else
		*i = 1;
}

void			ants_move(t_ants *ants, t_lem *lem, t_vis *vis, int *i)
{
	if (lem->num == 1)
		spesial_one(ants, lem, vis, i);
	else
	{
		if ((int)ants->y != lem->hp[ants->nextrooms_id]->y ||
			(int)ants->x != lem->hp[ants->nextrooms_id]->x)
		{
			vis->ants.w = vis->ant_size_x;
			vis->ants.h = vis->ant_size_y;
			vis->ants.x = lem->scale * (ants->x + (lem->xoffset) -\
			vis->width / 2) + vis->width / 2 - (vis->ant_size_x / 2);
			vis->ants.y = lem->scale * (ants->y + (lem->yoffset) -
			vis->height / 2) + vis->height / 2 - (vis->ant_size_y / 2);
			SDL_RenderCopy(vis->renderer, vis->img_ant, NULL, &vis->ants);
			ants->x += ants->addx;
			ants->y += ants->addy;
		}
		else
			*i = 1;
	}
}
