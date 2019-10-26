/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_alloc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:16:33 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/15 15:43:39 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_file(t_lem **lem)
{
	t_file	*file;
	t_file	*tmp;

	file = (*lem)->file;
	while (file)
	{
		tmp = file->next;
		free(file->line);
		free(file);
		file = tmp;
	}
}

void	free_paths(t_path **pth)
{
	t_path	*path;
	t_path	*tmp;

	path = *pth;
	while (path)
	{
		tmp = path->next;
		free_rooms(&path->rooms);
		free(path);
		path = NULL;
		path = tmp;
	}
}

void	free_grps(t_lem **lem)
{
	t_groupe	*groupe;
	t_groupe	*tmp;

	groupe = (*lem)->groupes;
	while (groupe)
	{
		tmp = groupe->next;
		free_paths(&groupe->paths);
		free(groupe);
		groupe = tmp;
	}
}
