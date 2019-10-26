/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:25:34 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 19:23:34 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_exists(t_lem **lem, char **split)
{
	t_v		*v;

	v = (*lem)->v;
	if ((*lem)->start)
		if (ft_strcmp((*lem)->start, split[0]) == 0)
			return (0);
	if ((*lem)->end)
		if (ft_strcmp((*lem)->end, split[0]) == 0)
			return (0);
	while (v)
	{
		if (ft_strcmp(v->name, split[0]) == 0)
			return (0);
		v = v->next;
	}
	return (1);
}

static int	add_rooms(t_lem **lem, char **split, int tp)
{
	t_lem	*lm;

	lm = *lem;
	if (check_exists(lem, split) == 0)
		return (0);
	if (tp == 1)
	{
		lm->start = ft_strdup(split[0]);
		lm->xs = ft_atoi(split[1]);
		lm->ys = ft_atoi(split[2]);
	}
	else if (tp == 2)
	{
		lm->end = ft_strdup(split[0]);
		lm->xe = ft_atoi(split[1]);
		lm->ye = ft_atoi(split[2]);
	}
	else
	{
		add_v(&lm->v, new_v(split[0], ft_atoi(split[1]), ft_atoi(split[2]), 0));
		lm->v_ln++;
	}
	return (1);
}

static int	check_room(t_lem **lem, char *line, int tp)
{
	int		i;

	if (!((*lem)->split = ft_strsplit(line, ' ')))
		malloc_error();
	i = ft_mxlength((*lem)->split);
	if ((i != 3) || ((*lem)->split[0][0] == 'L'))
		return (0);
	i = -1;
	while ((*lem)->split[1][++i])
		if (!((*lem)->split[1][i] >= '0' && (*lem)->split[1][i] <= '9'))
			return (0);
	i = -1;
	while ((*lem)->split[2][++i])
		if (!((*lem)->split[2][i] >= '0' && (*lem)->split[2][i] <= '9'))
			return (0);
	if (add_rooms(lem, (*lem)->split, tp) == 0)
		return (0);
	free_mx(&(*lem)->split);
	(*lem)->split = NULL;
	return (1);
}

static int	add_startend(t_lem **lem)
{
	t_lem	*lm;
	int		tp;

	lm = *lem;
	if ((ft_strcmp(lm->line, "##start") == 0))
		tp = 1;
	else if ((ft_strcmp(lm->line, "##end") == 0))
		tp = 2;
	if (get_next_line(0, &lm->line) > 0)
	{
		add_line(lem, lm->line);
		if (!check_room(lem, lm->line, tp))
			return (0);
	}
	return (1);
}

int			read_rooms(t_lem **lem, int i)
{
	while (get_next_line(0, &(*lem)->line) > 0)
	{
		i = 1;
		add_line(lem, (*lem)->line);
		if (ft_strchr((*lem)->line, '-'))
		{
			if ((*lem)->se != 2)
				return (0);
			return (1);
		}
		if ((ft_strcmp((*lem)->line, "##start") == 0) ||
		(ft_strcmp((*lem)->line, "##end") == 0))
		{
			(*lem)->se++;
			if (!add_startend(lem))
				return (0);
		}
		else if ((!ft_strstr((*lem)->line, "#"))
		&& (!check_room(lem, (*lem)->line, 0)))
			return (0);
	}
	free((*lem)->line);
	if (i == 0)
		return (0);
	return (1);
}
