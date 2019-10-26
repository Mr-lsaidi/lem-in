/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 19:00:04 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 21:02:25 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_printf *pf)
{
	while (pf->str[pf->i] == '-' || pf->str[pf->i] == '+' ||
			pf->str[pf->i] == ' ' || pf->str[pf->i] == '0' ||
			pf->str[pf->i] == '#')
	{
		if (pf->str[pf->i] == '-')
			pf->minus = 1;
		else if (pf->str[pf->i] == '+')
			pf->plus = 1;
		else if (pf->str[pf->i] == ' ')
			pf->space = 1;
		else if (pf->str[pf->i] == '0')
			pf->zero = 1;
		else if (pf->str[pf->i] == '#')
			pf->hash = 1;
		pf->i++;
	}
}

void	check_width(t_printf *pf)
{
	pf->width = 0;
	while (pf->str[pf->i] >= '0' && pf->str[pf->i] <= '9')
	{
		pf->width = pf->str[pf->i] - '0' + pf->width * 10;
		pf->i++;
	}
	if (pf->str[pf->i] == '*')
	{
		pf->width = va_arg(pf->ap, int);
		if (pf->width < 0)
		{
			pf->minus = 1;
			pf->width *= -1;
		}
		pf->i++;
	}
}

void	check_prec(t_printf *pf)
{
	pf->prec = 0;
	pf->isprec = 1;
	pf->i++;
	if (pf->str[pf->i] == '*')
	{
		pf->prec = va_arg(pf->ap, int);
		if (pf->prec < 0)
		{
			pf->prec = 0;
			pf->isprec = 0;
		}
		else
			pf->isprec = 1;
		pf->i++;
	}
	else
	{
		while (pf->str[pf->i] >= '0' && pf->str[pf->i] <= '9')
		{
			pf->prec = pf->str[pf->i] - '0' + pf->prec * 10;
			pf->i++;
			pf->isprec = 1;
		}
	}
	pf->xprec = pf->prec;
}

void	check_length(t_printf *pf)
{
	pf->length = 0;
	while (pf->str[pf->i] == 'h' || pf->str[pf->i] == 'l' ||
			pf->str[pf->i] == 'L' || pf->str[pf->i] == 'j' ||
			pf->str[pf->i] == 'z')
	{
		if (pf->str[pf->i] == 'h' && pf->length < 1)
			pf->length = 1;
		else if (pf->str[pf->i] == 'h' && pf->length < 2)
			pf->length = 2;
		else if (pf->str[pf->i] == 'l' && pf->length < 3)
			pf->length = 3;
		else if (pf->str[pf->i] == 'l' && pf->length < 4)
			pf->length = 4;
		else if (pf->str[pf->i] == 'L' && pf->length < 5)
			pf->length = 5;
		else if (pf->str[pf->i] == 'j' && pf->length < 6)
			pf->length = 6;
		else if (pf->str[pf->i] == 'z' && pf->length < 7)
			pf->length = 7;
		pf->i++;
	}
}

void	check_conv(t_printf *pf)
{
	if (pf->str[pf->i] == 'c')
		conv_char(pf);
	else if (pf->str[pf->i] == 's')
		conv_string(pf);
	else if (pf->str[pf->i] == 'p')
		conv_p(pf);
	else if (pf->str[pf->i] == 'x' || pf->str[pf->i] == 'X')
		conv_xx(pf);
	else if (pf->str[pf->i] == 'd' || pf->str[pf->i] == 'i')
		conv_di(pf);
	else if (pf->str[pf->i] == 'o')
		conv_o(pf);
	else if (pf->str[pf->i] == 'u')
		conv_u(pf);
	else if (pf->str[pf->i] == 'U')
		conv_uu(pf);
	else if (pf->str[pf->i] == 'f')
		conv_f(pf);
	else if (pf->str[pf->i] == '%')
		conv(pf);
}
