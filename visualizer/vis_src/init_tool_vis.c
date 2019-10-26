/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tool_vis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 23:40:23 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/17 15:26:46 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static void		ttf_tools(t_vis *vis)
{
	int				tex_w;
	int				tex_h;

	tex_h = 0;
	tex_w = 0;
	TTF_Init();
	vis->police = TTF_OpenFont("visualizer/vis_src/fonts/symbola.ttf", 25);
	vis->color.r = 255;
	vis->color.g = 65;
	vis->color.b = 10;
}

int				get_max_lvl(t_lem *lem)
{
	int		i;
	int		max_lvl;

	i = 0;
	max_lvl = 0;
	while (++i < lem->v_ln)
	{
		if (max_lvl < lem->hp[i]->lvl)
			max_lvl = lem->hp[i]->lvl;
	}
	return (max_lvl);
}

void			init_vars(t_vis *vis, t_lem **lem)
{
	vis->height = 1440;
	vis->width = 2560;
	vis->max_lvl = 0;
	vis->x1 = 0;
	vis->y1 = 0;
	vis->x2 = 0;
	vis->y2 = 0;
	vis->moyenn_x = 0;
	vis->moyenn_y = 0;
	(*lem)->hp[1]->lvl = get_max_lvl(*lem) + 1;
	vis->height_correct = vis->height / (*lem)->hp[1]->lvl;
	small_big_init(vis, lem);
	vis->text_h = 100;
	vis->text_w = 150;
	(*lem)->id_gp = 0;
}

void			init_tool(t_vis *vis)
{
	SDL_Init(SDL_INIT_VIDEO);
	vis->window = SDL_CreateWindow("lsaidi", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, vis->width, vis->height,\
		SDL_WINDOW_FULLSCREEN_DESKTOP);
	vis->renderer = SDL_CreateRenderer(vis->window, -1,
		SDL_RENDERER_ACCELERATED);
	vis->img_room = IMG_LoadTexture(vis->renderer, IMG_PATH);
	SDL_QueryTexture(vis->img_room, NULL, NULL, &vis->w, &vis->h);
	vis->img_start = IMG_LoadTexture(vis->renderer, IMG_PATH_S);
	SDL_QueryTexture(vis->img_start, NULL, NULL, &vis->w, &vis->h);
	vis->img_end = IMG_LoadTexture(vis->renderer, IMG_PATH_E);
	SDL_QueryTexture(vis->img_end, NULL, NULL, &vis->w, &vis->h);
	vis->img_ant = IMG_LoadTexture(vis->renderer, IMG_PATH_ANT);
	SDL_QueryTexture(vis->img_ant, NULL, NULL, &vis->w, &vis->h);
	ttf_tools(vis);
}

int				close_sdl(t_vis *vis, t_lem *lem)
{
	if (!manager_event(vis, lem))
	{
		SDL_DestroyRenderer(vis->renderer);
		SDL_DestroyWindow(vis->window);
		TTF_CloseFont(vis->police);
		TTF_Quit();
		SDL_Quit();
		return (0);
	}
	return (1);
}
