/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 00:52:46 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/20 17:41:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_ants(t_lem **lem, t_path **path, int ant)
{
	int		tmp_id;
	t_room	*rooms;

	tmp_id = ant;
	rooms = (*path)->rooms;
	rooms = rooms->next;
	while (rooms)
	{
		if (ant != 0)
		{
			tmp_id = rooms->id_ant;
			rooms->id_ant = ant;
			ant = tmp_id;
		}
		else if (ant == 0)
			break ;
		if (rooms->id == 1)
			(*lem)->nb_ants_pass++;
		rooms = rooms->next;
	}
}

static void		move_ants(t_lem **lem, t_path **path)
{
	t_room	*rooms;
	int		tmp_id1;
	int		tmp_id2;

	tmp_id1 = 0;
	tmp_id2 = 0;
	rooms = (*path)->rooms;
	rooms = rooms->next;
	while (rooms)
	{
		if (rooms->id == 1 && tmp_id2 != 0)
			(*lem)->nb_ants_pass++;
		tmp_id1 = rooms->id_ant;
		rooms->id_ant = tmp_id2;
		tmp_id2 = tmp_id1;
		rooms = rooms->next;
	}
}

static void		solution(t_lem **lem)
{
	t_groupe	*groupe;
	t_path		*path;
	int			i;

	i = 0;
	groupe = (*lem)->best_gp;
	while ((*lem)->nb_ants_pass != (*lem)->nbant)
	{
		path = groupe->paths;
		while (path)
		{
			if (path->capacity > 0)
			{
				if (path->capacity != path->nb_ant)
				{
					add_ants(lem, &path, ++i);
					path->nb_ant++;
				}
				else
					move_ants(lem, &path);
			}
			path = path->next;
		}
		select_solution(lem, groupe);
	}
}

static void		solution_onepath(t_lem **lem)
{
	int		nb_ants;
	int		i;

	i = 0;
	nb_ants = (*lem)->nbant;
	while (nb_ants--)
	{
		if ((*lem)->is_visu == 1)
			ft_printf("%d %d\n", 0, 1);
		else
			ft_printf("L%d-%s ", ++i, (*lem)->hp[1]->name);
	}
	ft_printf("\n");
}

void			start_solution(t_lem **lem)
{
	t_path	*path;
	int		sl;

	sl = 0;
	path = (*lem)->best_gp->paths;
	while (path)
	{
		if (path->v_nb == 2)
		{
			sl = 1;
			break ;
		}
		path = path->next;
	}
	if (sl == 1)
		solution_onepath(lem);
	else
		solution(lem);
}
