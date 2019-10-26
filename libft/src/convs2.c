/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 03:44:26 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:28:30 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_o(t_printf *pf)
{
	uintmax_t	o;
	int			len;
	int			print;

	print = 1;
	if (pf->length == 1)
		o = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (pf->length == 2)
		o = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->length == 3)
		o = va_arg(pf->ap, unsigned long);
	else if (pf->length == 4)
		o = va_arg(pf->ap, unsigned long long);
	else
		o = va_arg(pf->ap, unsigned int);
	pf->base = 8;
	len = len_hexa(pf, o);
	flags_xxo(pf, o, 'o', len);
	print_prec(pf->prec);
	if (o == 0 && pf->isprec && !pf->hash && pf->xprec == 0)
		print = 0;
	print ? ft_putnbr_unsigned(pf, o, 8) : 1;
	pf->minus ? print_width(pf) : 1;
	pf->i++;
}

void	conv(t_printf *pf)
{
	pf->base = 0;
	pf->width = (pf->width > 1 ? pf->width -= 1 : 0);
	flags_scp(pf, 1);
	ft_putchar(pf->str[pf->i]);
	if (pf->minus == 1)
		print_width(pf);
	pf->i++;
}

void	conv_f(t_printf *pf)
{
	long double		f;
	int				len;

	if (pf->length == 5)
		f = va_arg(pf->ap, long double);
	else
		f = va_arg(pf->ap, double);
	pf->num.f = f;
	if ((f == 1.0 / 0.0) || (f == -1.0 / 0.0) || (f != f))
		check_infnan(pf);
	else
		get_exp(pf);
	len = ft_strlen(pf->flt);
	pf->width = (pf->width > len ? pf->width -= len : 0);
	if (pf->width > 0)
	{
		if ((pf->sign == 1 || pf->space == 1 || pf->plus == 1) && (f == f))
			pf->width--;
	}
	flags_f(pf, len, f);
	ft_putstr(pf->flt);
	pf->minus ? print_widthf(pf, f) : 1;
	free(pf->flt);
	pf->i++;
}

void	tarit_di(t_printf *pf, intmax_t d)
{
	int				len;
	int				print;

	print = 1;
	len = int_len(pf, d);
	flags_di(pf, d, len);
	print_prec(pf->prec);
	if (d == 0 && pf->isprec && pf->xprec == 0)
		print = 0;
	print ? ft_maxnbr(pf, d, len) : 1;
	pf->minus ? print_width(pf) : 1;
	pf->i++;
}

void	conv_di(t_printf *pf)
{
	intmax_t		d;

	if (pf->length == 1)
		d = (short)va_arg(pf->ap, int);
	else if (pf->length == 2)
		d = (char)va_arg(pf->ap, int);
	else if (pf->length == 3)
		d = va_arg(pf->ap, long);
	else if (pf->length == 4)
		d = va_arg(pf->ap, long long);
	else if (pf->length == 6)
		d = va_arg(pf->ap, intmax_t);
	else if (pf->length == 7)
		d = (intmax_t)va_arg(pf->ap, size_t);
	else
		d = va_arg(pf->ap, int);
	tarit_di(pf, d);
}
