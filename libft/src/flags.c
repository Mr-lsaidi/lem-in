/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:53:53 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:26:44 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_size(t_printf *pf, intmax_t nb)
{
	if (pf->space == 1 && pf->plus == 0 && nb >= 0)
		pf->size++;
	if (pf->zero == 1)
	{
		if (nb >= 0 && pf->plus == 1)
			pf->size++;
	}
	if (pf->plus == 1 && nb >= 0 && pf->zero == 0)
		pf->size++;
}

void	print_sxo(t_printf *pf, char c, unsigned long long int nb)
{
	if (nb > 0)
	{
		if (pf->hash == 1 && c == 'x')
			ft_putstr("0x");
		else if (pf->hash == 1 && c == 'X')
			ft_putstr("0X");
		else if (pf->hash == 1 && c == 'o' && !pf->isprec)
			ft_putstr("0");
		else if (pf->hash == 1 && c == 'o' && pf->isprec)
			ft_putstr("0");
		if ((pf->hash == 1 && c == 'x') || (pf->hash == 1 && c == 'X'))
			pf->size += 2;
		else if (pf->hash == 1 && c == 'o' && !pf->isprec)
			pf->size += 1;
		else if (pf->hash == 1 && c == 'o' && pf->isprec)
			pf->size += 1;
	}
}

void	flags_u(t_printf *pf, uintmax_t nb, int len)
{
	pf->size += pf->width + len;
	if (pf->zero == 0 && pf->minus == 0)
		print_width(pf);
	if (pf->space == 1 && pf->plus == 0)
		ft_putchar(' ');
	if (pf->zero == 1)
	{
		if (pf->plus == 1 && !pf->isprec)
			ft_putchar('+');
		if (!pf->minus)
			print_width(pf);
		if (pf->plus == 1 && pf->isprec)
			ft_putchar('+');
	}
	if (pf->plus == 1 && pf->zero == 0)
		ft_putchar('+');
	count_size(pf, nb);
}

void	flags_di(t_printf *pf, intmax_t nb, int len)
{
	pf->plus == 1 && nb >= 0 ? pf->width-- : 1;
	pf->space == 1 && pf->plus == 0 && nb >= 0 ? pf->width-- : 1;
	pf->width = (pf->width > len ? pf->width - len : 0);
	pf->size += pf->width + len;
	if (pf->zero == 0 && pf->minus == 0)
	{
		print_width(pf);
		nb < 0 ? ft_putchar('-') : 1;
	}
	pf->minus && nb < 0 ? ft_putchar('-') : 1;
	if (pf->space == 1 && pf->plus == 0 && nb >= 0)
		ft_putchar(' ');
	if (pf->zero == 1)
	{
		nb < 0 && !pf->isprec && !pf->minus ? ft_putchar('-') : 1;
		nb >= 0 && pf->plus == 1 && !pf->isprec ? ft_putchar('+') : 1;
		!pf->minus ? print_width(pf) : 1;
		if (nb >= 0 && pf->plus == 1 && pf->isprec)
			ft_putchar('+');
		if (nb < 0 && pf->isprec && !pf->minus)
			ft_putchar('-');
	}
	if (pf->plus == 1 && nb >= 0 && pf->zero == 0)
		ft_putchar('+');
	count_size(pf, nb);
}

void	flags_xxo(t_printf *pf, long long int nb, char c, int len)
{
	pf->width = (pf->width > len ? pf->width -= len : 0);
	pf->size += pf->width + len;
	if (pf->zero == 0 && pf->minus == 0)
	{
		print_width(pf);
		print_sxo(pf, c, nb);
	}
	if (pf->zero == 0 && pf->minus == 1)
		print_sxo(pf, c, nb);
	if (pf->zero == 1)
	{
		pf->isprec == 0 ? print_sxo(pf, c, nb) : 1;
		if (!pf->minus)
			print_width(pf);
		pf->isprec == 1 ? print_sxo(pf, c, nb) : 1;
	}
}
