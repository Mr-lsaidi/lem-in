/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_vis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:52:22 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/18 18:11:44 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void		print_roomnames(t_lem **lem, t_vis *vis, int x, int y)
{
	if ((*lem)->v_ln <= 20)
	{
		vis->rooms_name.w = 40;
		vis->rooms_name.h = 40;
		vis->rooms_name.x = (*lem)->scale * (x + ((*lem)->xoffset) -\
			vis->width / 2) + vis->width / 2 - (vis->rooms_size_x / 2);
		vis->rooms_name.y = (*lem)->scale * (y + ((*lem)->yoffset) -\
			vis->height / 2) + vis->height / 2 - (vis->rooms_size_y + 5);
		vis->rooms_text = TTF_RenderText_Solid(vis->police,\
			(*lem)->hp[vis->get_id]->name, vis->color);
		vis->texture2 = SDL_CreateTextureFromSurface(vis->renderer,\
			vis->rooms_text);
		SDL_QueryTexture(vis->texture2, NULL, NULL, NULL, NULL);
		SDL_RenderCopy(vis->renderer, vis->texture2, NULL, &vis->rooms_name);
	}
}

void		free_ants(t_ants **ants)
{
	t_ants	*room;
	t_ants	*tmp;

	room = *ants;
	while (room)
	{
		tmp = room->next;
		free(room);
		room = tmp;
	}
}

int			drow_ants(t_inst *inst, t_vis *vis, t_lem *lem)
{
	t_ants		*ants;
	int			i;

	while (inst)
	{
		i = 0;
		while (i != 1)
		{
			print_rooms_lines(vis, lem);
			ants = inst->ants;
			(size(ants) == 1 || size(ants) == 0) ? lem->num = 1 : 1;
			while (ants)
			{
				drow_select_lines(ants, lem, vis);
				ants_move(ants, lem, vis, &i);
				ants = ants->next;
			}
			if (!close_sdl(vis, lem))
				return (0);
			SDL_RenderPresent(vis->renderer);
		}
		SDL_Delay(200);
		inst = inst->next;
	}
	return (1);
}
