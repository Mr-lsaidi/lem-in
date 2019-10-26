/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:11:58 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:26:50 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_sizef(t_printf *pf, long double f)
{
	if (pf->space == 1 && pf->plus == 0 && pf->sign == 0 && (f == f))
		pf->size++;
	if (pf->zero == 1)
	{
		if (pf->sign == 0 && pf->plus == 1 && (f == f))
			pf->size++;
	}
	if (pf->plus == 1 && pf->sign == 0 && pf->zero == 0 && (f == f))
		pf->size++;
	if (pf->sign == 1)
		pf->size++;
}

void	flags_f2(t_printf *pf, long double f)
{
	if (pf->zero == 1)
	{
		if (pf->sign == 0 && pf->isprec && pf->plus == 1
		&& (f == f) && (f != 1.0 / 0.0))
			ft_putchar('+');
		if (pf->sign == 1 && pf->isprec && (f != -1.0 / 0.0))
			ft_putchar('-');
		if (!pf->minus)
			print_widthf(pf, f);
		if (pf->sign == 0 && !pf->isprec && pf->plus == 1 && (f == f))
			ft_putchar('+');
		if (pf->sign == 0 && pf->plus == 1 && (f == 1.0 / 0.0))
			ft_putchar('+');
		if ((pf->sign == 1 && !pf->isprec) || (f == -1.0 / 0.0))
			ft_putchar('-');
	}
	if (pf->plus == 1 && pf->sign == 0 && pf->zero == 0 && (f == f))
		ft_putchar('+');
	count_sizef(pf, f);
}

void	flags_f(t_printf *pf, int len, long double f)
{
	pf->size += pf->width + len;
	if (pf->zero == 0 && pf->minus == 0)
	{
		print_widthf(pf, f);
		if (pf->sign == 1)
			ft_putchar('-');
	}
	if (pf->minus == 1 && pf->sign == 1 && pf->zero == 0)
		ft_putchar('-');
	if (pf->space == 1 && pf->plus == 0 && pf->sign == 0 && (f == f))
		ft_putchar(' ');
	flags_f2(pf, f);
}

void	flags_scp(t_printf *pf, int len)
{
	pf->size += pf->width + len;
	if (pf->base == 16 && pf->zero == 1)
		ft_putstr("0x");
	if (pf->minus == 0)
		print_width(pf);
	if (pf->base == 16 && pf->zero == 0)
		ft_putstr("0x");
}
