/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:11:59 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 19:38:15 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_conv(char c)
{
	if (c == 'c' || c == 's' ||
			c == 'p' || c == 'd' ||
			c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' ||
			c == 'X')
		return (1);
	return (0);
}

void	init_pf(t_printf *pf)
{
	pf->hash = 0;
	pf->zero = 0;
	pf->minus = 0;
	pf->plus = 0;
	pf->width = 0;
	pf->space = 0;
	pf->prec = 0;
	pf->length = 0;
	pf->isprec = 0;
	pf->xprec = 0;
	pf->sign = 0;
}

void	params(t_printf *pf)
{
	pf->i++;
	while (pf->str[pf->i])
	{
		if (pf->str[pf->i] == '-' || pf->str[pf->i] == '+' ||
				pf->str[pf->i] == ' ' || pf->str[pf->i] == '0' ||
				pf->str[pf->i] == '#')
			check_flags(pf);
		else if ((pf->str[pf->i] >= '1' && pf->str[pf->i] <= '9')
				|| (pf->str[pf->i]) == '*')
			check_width(pf);
		else if (pf->str[pf->i] == '.')
			check_prec(pf);
		else if (pf->str[pf->i] == 'h' || pf->str[pf->i] == 'l' ||
				pf->str[pf->i] == 'L' || pf->str[pf->i] == 'j' ||
				pf->str[pf->i] == 'z')
			check_length(pf);
		else
		{
			check_conv(pf);
			break ;
		}
	}
}

void	pf_start(t_printf *pf)
{
	while (pf->str[pf->i])
	{
		if (pf->str[pf->i] == '%' && pf->str[pf->i + 1] != '%')
			params(pf);
		else if (pf->str[pf->i] == '%' && pf->str[pf->i + 1] == '%')
		{
			ft_putchar(pf->str[pf->i++]);
			pf->i++;
			pf->size++;
		}
		else
		{
			ft_putchar(pf->str[pf->i]);
			pf->i++;
			pf->size++;
		}
		init_pf(pf);
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf pf;

	if (format)
	{
		va_start(pf.ap, format);
		pf.i = 0;
		pf.size = 0;
		init_pf(&pf);
		pf.str = (char*)format;
		pf_start(&pf);
		va_end(pf.ap);
		return (pf.size);
	}
	else
		return (-1);
}
