/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 13:08:58 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/18 18:14:38 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void			drow_rooms(t_lem **lem, t_vis *vis, int x, int y)
{
	vis->rect.w = vis->rooms_size_x;
	vis->rect.h = vis->rooms_size_x;
	vis->rect.x = (*lem)->scale * (x + (*lem)->xoffset -
		vis->width / 2) + vis->width / 2 - (vis->rooms_size_y / 2);
	vis->rect.y = (*lem)->scale * (y + (*lem)->yoffset -
		vis->height / 2) + vis->height / 2 - (vis->rooms_size_y / 2);
	if (vis->class == 1)
		SDL_RenderCopy(vis->renderer, vis->img_start, NULL, &vis->rect);
	else if (vis->class == (*lem)->hp[1]->lvl)
		SDL_RenderCopy(vis->renderer, vis->img_end, NULL, &vis->rect);
	else
		SDL_RenderCopy(vis->renderer, vis->img_room, NULL, &vis->rect);
}

void			print_rooms_lines(t_vis *vis, t_lem *lem)
{
	lem->num = 0;
	SDL_SetRenderDrawColor(vis->renderer, 27, 33, 32, 255);
	SDL_RenderClear(vis->renderer);
	drow_line_all(lem, vis);
	drow_rooms_all(lem, vis);
}

void			drow_rooms_all(t_lem *lem, t_vis *vis)
{
	int		j;

	j = -1;
	while (++j < lem->v_ln)
	{
		vis->class = lem->hp[j]->lvl;
		drow_rooms(&lem, vis, lem->hp[j]->x, lem->hp[j]->y);
	}
}
