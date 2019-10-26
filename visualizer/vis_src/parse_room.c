/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:25:34 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:04:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int	add_rooms(t_lem **lem, char **split, int tp)
{
	t_lem	*lm;

	lm = *lem;
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
	char	**split;
	int		i;

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	i = ft_mxlength(split);
	if (i != 3)
		return (0);
	if (split[0][0] == 'L')
	{
		free_mx(split);
		return (0);
	}
	i = -1;
	while (split[1][++i])
		if (!(split[1][i] >= '0' && split[1][i] <= '9'))
			return (0);
	i = -1;
	while (split[2][++i])
		if (!(split[2][i] >= '0' && split[2][i] <= '9'))
			return (0);
	if (add_rooms(lem, split, tp) == 0)
		return (0);
	free_mx(split);
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
	free(lm->line);
	if (get_next_line(0, &lm->line) > 0)
	{
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
