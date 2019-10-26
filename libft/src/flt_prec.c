/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:59:32 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:22:52 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_flt2(t_printf *pf, int i)
{
	while (pf->flt[i++])
		if (pf->flt[i] > '0')
			break ;
	if ((size_t)i < ft_strlen(pf->flt))
	{
		pf->tmp = pf->fltprec;
		pf->fltprec = ft_addme(pf->fltprec, "1");
		free(pf->tmp);
	}
	else
	{
		i = 0;
		while (pf->flt[i] != '.')
			i++;
		if ((pf->flt[i - 1] - '0') % 2 != 0)
		{
			pf->tmp = pf->fltprec;
			pf->fltprec = ft_addme(pf->fltprec, "1");
			free(pf->tmp);
		}
	}
	pf->tmp = pf->fltprec;
	pf->fltprec = rm_zr(pf->fltprec);
	free(pf->tmp);
}

void	round_flt(t_printf *pf)
{
	int		i;
	char	*tmp;

	i = ft_strlen(pf->fltprec);
	if (pf->flt[i] > '5')
	{
		tmp = pf->fltprec;
		pf->fltprec = ft_addme(pf->fltprec, "1");
		free(tmp);
		tmp = pf->fltprec;
		pf->fltprec = rm_zr(pf->fltprec);
		free(tmp);
	}
	else if (pf->flt[i] == '5')
		round_flt2(pf, i);
}

void	round_fltadd(t_printf *pf, int len)
{
	int		j;

	j = 0;
	while (pf->flt[j])
	{
		pf->fltprec[j] = pf->flt[j];
		j++;
	}
	while (j < len)
	{
		pf->fltprec[j] = '0';
		j++;
	}
}

void	flt_prec(t_printf *pf)
{
	int		i;
	int		len;

	i = 0;
	while (pf->flt[i] != '.')
		i++;
	!pf->isprec ? pf->prec = 6 : 1;
	pf->prec >= 2147483648 ? pf->prec = 6 : 1;
	len = ((i + 1 + pf->prec) >= 2147483647 ? 2147483645 : i + 1 + pf->prec);
	pf->fltprec = ft_strnew(len + 1);
	pf->fltprec[len] = '\0';
	if (ft_strlen(pf->flt) > (size_t)len)
	{
		i = -1;
		while (++i < len)
			pf->fltprec[i] = pf->flt[i];
		round_flt(pf);
	}
	else
		round_fltadd(pf, len);
	if (pf->prec == 0 && pf->hash == 0)
		pf->fltprec[ft_strlen(pf->fltprec) - 1] = '\0';
	free(pf->flt);
	pf->flt = pf->fltprec;
}
