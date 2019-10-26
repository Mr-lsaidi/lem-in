/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:13:55 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:26:12 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	trait_u(t_printf *pf, uintmax_t u)
{
	int			len;
	int			print;

	print = 1;
	pf->plus = 0;
	pf->space = 0;
	len = uint_len(pf, u);
	flags_u(pf, u, len);
	print_prec(pf->prec);
	if (u == 0 && pf->isprec && pf->xprec == 0)
		print = 0;
	print ? ft_putnbr_unsigned(pf, u, 10) : 1;
	pf->minus ? print_width(pf) : 1;
	pf->i++;
}

void	conv_u(t_printf *pf)
{
	uintmax_t	u;

	if (pf->length == 1)
		u = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (pf->length == 2)
		u = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (pf->length == 3)
		u = va_arg(pf->ap, unsigned long);
	else if (pf->length == 4)
		u = va_arg(pf->ap, unsigned long long int);
	else if (pf->length == 6)
		u = va_arg(pf->ap, uintmax_t);
	else
		u = va_arg(pf->ap, unsigned int);
	trait_u(pf, u);
}

void	trait_uu(t_printf *pf, uintmax_t u)
{
	int			len;
	int			print;

	print = 1;
	pf->plus = 0;
	pf->space = 0;
	len = uint_len(pf, u);
	flags_u(pf, u, len);
	print_prec(pf->prec);
	if (u == 0 && pf->isprec && pf->xprec == 0)
		print = 0;
	print ? ft_putnbr_unsigned(pf, u, 10) : 1;
	pf->minus ? print_width(pf) : 1;
	pf->i++;
}

void	conv_uu(t_printf *pf)
{
	uintmax_t	u;

	if (pf->length == 1)
		u = (unsigned long)va_arg(pf->ap, unsigned long int);
	else if (pf->length == 2)
		u = (unsigned char)va_arg(pf->ap, unsigned long int);
	else if (pf->length == 3)
		u = va_arg(pf->ap, unsigned long);
	else if (pf->length == 4)
		u = va_arg(pf->ap, unsigned long long int);
	else if (pf->length == 6)
		u = va_arg(pf->ap, uintmax_t);
	else
		u = va_arg(pf->ap, unsigned long int);
	trait_uu(pf, u);
}
