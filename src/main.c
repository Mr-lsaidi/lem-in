/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:33:06 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/18 23:44:37 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_lem(t_lem **lem)
{
	t_lem	*lm;

	lm = *lem;
	lm->routes = 0;
	lm->groupes = NULL;
	lm->fnlgrps = NULL;
	lm->vstd_cmp = 0;
	lm->nb_paths = 0;
	lm->endroom = NULL;
	lm->nb_ants_pass = 0;
	lm->file = NULL;
	lm->v = NULL;
	lm->start = NULL;
	lm->end = NULL;
	lm->v_ln = 0;
	lm->se = 0;
	lm->is_visu = 0;
	lm->split = NULL;
	lm->hp = NULL;
}

t_path		*get_shrtpathroom(t_lem **lem, t_room *endroom)
{
	t_path	*path;
	t_room	*room;

	path = NULL;
	if (endroom)
	{
		room = endroom->parent;
		path = new_path(1);
		add_vpath(&path, 1);
		while (room)
		{
			path->v_nb++;
			add_vpath(&path, room->id);
			room = room->parent;
		}
		add_vpath(&path, 0);
		path->v_nb++;
	}
	(*lem)->endroom = NULL;
	return (path);
}

int			get_way(t_lem **lem, int id1, int id2)
{
	t_room	*rooms;

	rooms = (*lem)->hp[id1]->rooms;
	while (rooms)
	{
		if (rooms->id == id2)
			return (rooms->way);
		rooms = rooms->next;
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_lem	*lem;

	if (!(lem = (t_lem*)malloc(sizeof(t_lem))))
		malloc_error();
	init_lem(&lem);
	if (ac == 2)
		if (ft_strstr(av[1], "-v"))
			lem->is_visu = 1;
	if (!read_file(&lem))
	{
		free_v(&lem->v);
		free_lem(&lem);
		print_error();
	}
	free_grps(&lem);
	free_v(&lem->v);
	free_lem(&lem);
	return (0);
}
