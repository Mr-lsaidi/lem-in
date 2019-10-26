/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:53:37 by lsaidi            #+#    #+#             */
/*   Updated: 2019/07/16 18:03:19 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

static int		range_color(int z)
{
	int		k;
	int		tab[N_COLORS];

	k = ((int)z) % N_COLORS;
	tab[0] = 0x362312FF;
	tab[1] = 0x222021FF;
	return (tab[k]);
}

void			drow_line_all(t_lem *lem, t_vis *vis)
{
	int			i;
	t_room		*rooms;

	i = -1;
	while (++i < lem->v_ln)
	{
		rooms = lem->hp[i]->rooms;
		while (rooms)
		{
			vis->x2 = lem->scale * (lem->hp[rooms->id]->x + lem->xoffset -
				vis->width / 2) + vis->width / 2;
			vis->y2 = lem->scale * (lem->hp[rooms->id]->y + lem->yoffset -
				vis->height / 2) + vis->height / 2;
			vis->x1 = lem->scale * (lem->hp[i]->x + lem->xoffset -
				vis->width / 2) + vis->width / 2;
			vis->y1 = lem->scale * (lem->hp[i]->y + lem->yoffset -
				vis->height / 2) + vis->height / 2;
			thickLineColor(vis->renderer, vis->x1,
				vis->y1, vis->x2, vis->y2, vis->line_radian, range_color(i));
			rooms = rooms->next;
		}
	}
}
