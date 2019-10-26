/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:06:46 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 16:31:05 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	add_room(t_lem **lem)
{
	t_lem	*lm;
	t_room	*room;

	lm = *lem;
	room = new_room(lm->i1);
	room->next = lm->hp[lm->i2]->rooms;
	lm->hp[lm->i2]->rooms = room;
	lm->hp[lm->i2]->nb_rooms++;
	room = new_room(lm->i2);
	room->next = lm->hp[lm->i1]->rooms;
	lm->hp[lm->i1]->rooms = room;
	lm->hp[lm->i1]->nb_rooms++;
}

static int	update_adlist(t_lem **lem, char *s1, char *s2)
{
	t_lem	*lm;
	int		i;

	lm = *lem;
	i = -1;
	lm->i1 = -1;
	lm->i2 = -1;
	while (++i < lm->v_ln)
		if (ft_strcmp(s1, lm->hp[i]->name) == 0)
		{
			lm->i1 = i;
			break ;
		}
	i = -1;
	while (++i < lm->v_ln)
		if (ft_strcmp(s2, lm->hp[i]->name) == 0)
		{
			lm->i2 = i;
			break ;
		}
	if (lm->i1 == -1 || lm->i2 == -1)
		return (0);
	add_room(lem);
	return (1);
}

static int	fill_adlist(t_lem **lem, char *str)
{
	char	**split;
	int		i;

	i = -1;
	if (!(split = ft_strsplit(str, '-')))
		return (0);
	while (split[++i])
		;
	if (i != 2)
	{
		free_mx(&split);
		return (0);
	}
	if (!update_adlist(lem, split[0], split[1]))
	{
		free_mx(&split);
		return (0);
	}
	free_mx(&split);
	return (1);
}

static void	calc_routes(t_lem **lem)
{
	t_room	*room;

	room = (*lem)->hp[0]->rooms;
	while (room)
	{
		(*lem)->routes++;
		room = room->next;
	}
}

int			start_adlist(t_lem **lem)
{
	int		i;

	i = 0;
	if (!fill_adlist(lem, (*lem)->line))
		return (0);
	while (get_next_line(0, &(*lem)->line) > 0)
	{
		add_line(lem, (*lem)->line);
		if (ft_strchr((*lem)->line, '#'))
		{
			if ((ft_strcmp((*lem)->line, "##start") == 0) ||
			(ft_strcmp((*lem)->line, "##end") == 0))
				return (0);
		}
		else if (ft_strlen((*lem)->line) == 0)
			i = 1;
		else if (!fill_adlist(lem, (*lem)->line) || i == 1)
			return (0);
	}
	free((*lem)->line);
	calc_routes(lem);
	return (1);
}
