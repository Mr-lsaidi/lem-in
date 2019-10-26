/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 02:29:54 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 22:08:42 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long nbr, unsigned long base, int lowercase)
{
	char	*str;
	char	c;

	str = "0123456789ABCDEF";
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base, lowercase);
		nbr = nbr % base;
	}
	c = str[nbr];
	if (lowercase && c >= 'A' && c <= 'Z')
		c = c + 32;
	ft_putchar(c);
}

void	ft_putnbr_baseint(t_printf *pf, uintmax_t nbr, int base, int lowercase)
{
	char	*str;
	char	c;

	str = "0123456789ABCDEF";
	if (nbr >= (unsigned long long int)base)
	{
		ft_putnbr_baseint(pf, nbr / base, base, lowercase);
		nbr = nbr % base;
	}
	c = str[nbr];
	if (lowercase && c >= 'A' && c <= 'Z')
		c = c + 32;
	ft_putchar(c);
}

void	ft_putnbr_unsigned(t_printf *pf, uintmax_t nbr, int base)
{
	if (nbr >= (uintmax_t)base)
	{
		ft_putnbr_unsigned(pf, nbr / (uintmax_t)base, base);
		nbr = nbr % base;
	}
	ft_putnbr(nbr);
}

void	ft_maxnbr(t_printf *pf, intmax_t n, int len)
{
	uintmax_t	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	if (nbr >= 10)
		ft_maxnbr(pf, nbr / 10, len);
	ft_putchar(nbr % 10 + 48);
}

void	print_prec(int prec)
{
	while (prec)
	{
		ft_putchar('0');
		prec--;
	}
}
