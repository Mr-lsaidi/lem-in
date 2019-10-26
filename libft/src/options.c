/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 01:44:11 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:29:18 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_widthf(t_printf *pf, long double f)
{
	int		i;
	char	c;

	if (pf->zero == 1 && pf->minus == 0 && f == f)
		c = '0';
	else
		c = ' ';
	if (f == 1.0 / 0.0 || f == -1.0 / 0.0)
		c = ' ';
	i = pf->width;
	while (i > 0)
	{
		ft_putchar(c);
		i--;
	}
}

void	print_width(t_printf *pf)
{
	int		i;
	char	c;

	if (pf->zero == 1 && pf->minus == 0 && pf->isprec == 0)
		c = '0';
	else
		c = ' ';
	i = pf->width;
	while (i > 0)
	{
		ft_putchar(c);
		i--;
	}
}

int		uint_len(t_printf *pf, uintmax_t nb)
{
	int			len;
	uintmax_t	nbr;

	len = 0;
	pf->plus == 1 ? pf->width-- : 1;
	pf->space == 1 && pf->plus == 0 ? pf->width-- : 1;
	nb == 0 ? len++ : len;
	nb == 0 && pf->isprec && pf->xprec == 0 ? len-- : len;
	nbr = nb;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	pf->prec = (pf->prec > len ? pf->prec - len : 0);
	len += pf->prec;
	pf->width = (pf->width > len ? pf->width - len : 0);
	return (len);
}

int		int_len(t_printf *pf, intmax_t nb)
{
	int			len;
	int			sign;
	uintmax_t	nbr;

	len = 0;
	nb == 0 ? len++ : len;
	nb == 0 && pf->isprec && pf->xprec == 0 ? len-- : len;
	if (nb < 0)
	{
		sign = -1;
		nbr = (nb * -1);
		pf->width--;
		pf->size++;
	}
	else
		nbr = nb;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	pf->prec = (pf->prec > len ? pf->prec - len : 0);
	len += pf->prec;
	return (len);
}

int		len_hexa(t_printf *pf, uintmax_t nb)
{
	int		len;

	len = 1;
	pf->hash && pf->base != 8 && nb > 0 ? pf->width -= 2 : pf->width;
	if (pf->hash && pf->base == 8 && !pf->isprec && nb > 0)
		pf->width -= 1;
	if (pf->hash && pf->base == 8 && pf->isprec && nb > 0)
		pf->width -= 1;
	if (nb == 0 && pf->isprec && pf->base == 8 && pf->xprec == 0 && !pf->hash)
		len--;
	nb == 0 && pf->isprec && pf->base != 8 && pf->xprec == 0 ? len-- : len;
	while (nb >= (uintmax_t)pf->base)
	{
		nb = nb / pf->base;
		len++;
	}
	if (pf->hash == 1 && pf->base == 8 && nb > 0 && pf->isprec)
		pf->prec--;
	pf->prec = (pf->prec > len ? pf->prec - len : 0);
	len += pf->prec;
	return (len);
}
