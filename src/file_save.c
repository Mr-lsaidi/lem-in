/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:04:00 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/07/17 20:34:42 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_file(t_lem **lem)
{
	t_file	*file;

	file = (*lem)->file;
	while (file)
	{
		ft_printf("%s\n", file->line);
		file = file->next;
	}
	ft_printf("\n");
}

static t_file	*new_file(char *line)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		malloc_error();
	file->line = line;
	file->next = NULL;
	return (file);
}

void			add_line(t_lem **lem, char *line)
{
	t_file	*file;

	file = (*lem)->file;
	if (file)
	{
		while (file->next)
			file = file->next;
		file->next = new_file(line);
	}
	else
	{
		(*lem)->file = new_file(line);
	}
}
