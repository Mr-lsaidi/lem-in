/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:58:21 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/17 15:24:42 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void		name_mouse_pos(t_vis *vis, t_lem *lem)
{
	int			x;
	int			y;
	int			i;

	if (vis->movement.type == SDL_MOUSEMOTION)
	{
		i = -1;
		x = vis->movement.motion.x;
		y = vis->movement.motion.y;
		while (++i < lem->v_ln)
		{
			if (x > (lem->hp[i]->x - vis->rooms_size_x / 2) &&\
				x < (lem->hp[i]->x - vis->rooms_size_x / 2) +\
				vis->rect.w && y > (lem->hp[i]->y - vis->rooms_size_y\
				/ 2) && y < (lem->hp[i]->y - vis->rooms_size_y / 2) +\
				vis->rect.h)
			{
				vis->get_id = i;
				print_roomnames(&lem, vis, x, y);
				break ;
			}
		}
	}
}

static void		init_position(t_vis *vis, t_lem *lem)
{
	if (vis->movement.key.keysym.sym == SDLK_SPACE)
	{
		lem->xoffset = 0;
		lem->yoffset = 0;
		lem->scale = 1;
		if (lem->v_ln <= 50)
		{
			vis->rooms_size_x = 50;
			vis->rooms_size_y = 50;
			vis->ant_size_x = 40;
			vis->ant_size_y = 20;
			vis->line_radian = 2;
		}
		else
		{
			vis->rooms_size_x = 10;
			vis->rooms_size_y = 10;
			vis->ant_size_x = 30;
			vis->ant_size_y = 18;
			vis->line_radian = 1;
		}
	}
}

static void		movment_keys(t_vis *vis, t_lem *lem)
{
	if (vis->movement.key.keysym.sym == SDLK_LEFT)
		lem->xoffset -= 10;
	else if (vis->movement.key.keysym.sym == SDLK_RIGHT)
		lem->xoffset += 10;
	else if (vis->movement.key.keysym.sym == SDLK_UP)
		lem->yoffset -= 10;
	else if (vis->movement.key.keysym.sym == SDLK_DOWN)
		lem->yoffset += 10;
	else if (vis->movement.key.keysym.sym == SDLK_KP_PLUS)
	{
		lem->scale *= 1.1;
		vis->rooms_size_x++;
		vis->rooms_size_y++;
		vis->ant_size_x++;
		vis->ant_size_y++;
	}
	else if (vis->movement.key.keysym.sym == SDLK_KP_MINUS)
	{
		lem->scale /= 1.1;
		vis->rooms_size_x--;
		vis->rooms_size_y--;
		vis->ant_size_x--;
		vis->ant_size_y--;
	}
}

static void		mouse_events(t_vis *vis, t_lem *lem)
{
	if (vis->movement.type == SDL_MOUSEWHEEL)
	{
		if (vis->movement.wheel.y > 0)
		{
			lem->scale *= 1.1;
			vis->rooms_size_x++;
			vis->rooms_size_y++;
			vis->ant_size_x++;
			vis->ant_size_y++;
		}
		else if (vis->movement.wheel.y < 0)
		{
			lem->scale /= 1.1;
			vis->rooms_size_x--;
			vis->rooms_size_y--;
			vis->ant_size_x--;
			vis->ant_size_y--;
		}
	}
	else if (vis->movement.type == SDL_MOUSEMOTION && \
			(vis->movement.motion.state & SDL_BUTTON_LEFT))
	{
		lem->xoffset += vis->movement.motion.xrel;
		lem->yoffset += vis->movement.motion.yrel;
	}
}

int				manager_event(t_vis *vis, t_lem *lem)
{
	while (SDL_PollEvent(&vis->movement))
	{
		if (vis->movement.key.keysym.sym == SDLK_ESCAPE)
			return (0);
		if (vis->movement.type == SDL_QUIT)
			return (0);
		if (vis->movement.type)
		{
			name_mouse_pos(vis, lem);
			movment_keys(vis, lem);
			init_position(vis, lem);
			mouse_events(vis, lem);
		}
	}
	return (1);
}
