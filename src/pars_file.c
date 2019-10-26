/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 22:05:43 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/24 23:53:46 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	read_nbant(t_lem **lem)
{
	t_lem	*lm;
	int		i;

	i = -1;
	lm = *lem;
	while (get_next_line(0, &lm->line) > 0)
	{
		if (!ft_strstr((*lem)->line, "#"))
		{
			add_line(lem, lm->line);
			while (lm->line[++i])
				if (!(lm->line[i] >= '0' && lm->line[i] <= '9'))
					return (0);
			break ;
		}
	}
	lm->nbant = ft_atoi(lm->line);
	if (lm->nbant <= 0)
		print_error();
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
		malloc_error();
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

static void	calc_instr(int nbants, t_groupe **group)
{
	t_path		*path;
	int			inst;
	int			nbrooms;
	int			i;

	i = 0;
	nbrooms = 0;
	path = (*group)->paths;
	while (path)
	{
		nbrooms = nbrooms + (path->v_nb - 2);
		inst = (nbrooms + nbants) / ++i;
		if (inst < (*group)->ninst)
			(*group)->ninst = inst;
		else
			break ;
		path = path->next;
	}
}

static int	best_groupe(t_lem **lem)
{
	t_groupe	*group;

	group = (*lem)->groupes;
	if (!group)
		return (0);
	while (group)
	{
		calc_instr((*lem)->nbant, &group);
		group = group->next;
	}
	return (1);
}

int			read_file(t_lem **lem)
{
	t_lem	*lm;

	lm = *lem;
	if (!read_nbant(lem))
		return (0);
	if (!read_rooms(lem, 0))
		return (0);
	lm->v_ln += 2;
	if (!fill_hp(lem) || !start_adlist(lem) || !check_loop(lem))
		return (0);
	get_paths(lem);
	if (!best_groupe(lem))
		return (0);
	print_file(lem);
	nb_ants_path(lem);
	start_solution(lem);
	return (1);
}
