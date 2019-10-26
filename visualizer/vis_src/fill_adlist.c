/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:06:46 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/16 18:03:56 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

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

static int	ft_cmp_opt(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
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
		if (ft_cmp_opt(s1, lm->hp[i]->name) == 0)
		{
			lm->i1 = i;
			break ;
		}
	i = -1;
	while (++i < lm->v_ln)
		if (ft_cmp_opt(s2, lm->hp[i]->name) == 0)
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
		free_mx(split);
		free(str);
		return (0);
	}
	if (!update_adlist(lem, split[0], split[1]))
	{
		free_mx(split);
		free(str);
		return (0);
	}
	free_mx(split);
	return (1);
}

int			start_adlist(t_lem **lem)
{
	t_lem	*lm;

	lm = *lem;
	if (!fill_adlist(lem, lm->line))
		return (0);
	free(lm->line);
	while (get_next_line(0, &lm->line) > 0)
	{
		if (ft_strlen(lm->line) == 0)
			break ;
		if (ft_strchr(lm->line, '#'))
			;
		else if (ft_strlen(lm->line) > 0 && !fill_adlist(lem, lm->line))
			return (0);
		free(lm->line);
	}
	free(lm->line);
	update_wieght(lem);
	return (1);
}
