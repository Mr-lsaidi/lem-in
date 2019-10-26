/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:57:22 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:25:41 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_char(t_printf *pf)
{
	char c;

	c = va_arg(pf->ap, int);
	pf->base = 0;
	pf->width = (pf->width > 1 ? pf->width -= 1 : 0);
	flags_scp(pf, 1);
	ft_putchar(c);
	if (pf->minus == 1)
		print_width(pf);
	pf->i++;
}

void	conv_string(t_printf *pf)
{
	char	*s;
	int		len;

	s = va_arg(pf->ap, char*);
	if (s == NULL)
		s = "(null)";
	pf->base = 0;
	len = ft_strlen(s);
	if (pf->isprec && len > pf->prec)
		len = pf->prec;
	pf->width = (pf->width > len ? pf->width -= len : 0);
	flags_scp(pf, len);
	pf->isprec ? ft_putstrlen(s, pf->prec) : ft_putstr(s);
	if (pf->minus == 1)
		print_width(pf);
	pf->i++;
}

void	conv_p(t_printf *pf)
{
	unsigned long	p;
	int				len;

	p = va_arg(pf->ap, unsigned long);
	pf->base = 16;
	pf->hash = 0;
	len = len_hexa(pf, p) + 2;
	pf->width = (pf->width > len ? pf->width -= len : 0);
	flags_scp(pf, len);
	ft_putnbr_base(p, 16, 1);
	if (pf->minus == 1)
		print_width(pf);
	pf->i++;
}

void	trait_xx(t_printf *pf, uintmax_t x)
{
	int		len;
	int		print;

	print = 1;
	pf->base = 16;
	len = len_hexa(pf, x);
	flags_xxo(pf, x, pf->str[pf->i], len);
	print_prec(pf->prec);
	if (x == 0 && pf->isprec && pf->xprec == 0)
		print = 0;
	if (pf->str[pf->i] == 'x' && print)
		ft_putnbr_baseint(pf, x, 16, 1);
	else if (pf->str[pf->i] == 'X' && print)
		ft_putnbr_baseint(pf, x, 16, 0);
	if (pf->minus == 1)
		print_width(pf);
	pf->i++;
}

void	conv_xx(t_printf *pf)
{
	uintmax_t	x;

	if (pf->length == 1)
		x = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (pf->length == 2)
		x = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->length == 3)
		x = va_arg(pf->ap, long);
	else if (pf->length == 4)
		x = va_arg(pf->ap, long long);
	else if (pf->length == 6)
		x = va_arg(pf->ap, uintmax_t);
	else
		x = va_arg(pf->ap, unsigned int);
	trait_xx(pf, x);
}
