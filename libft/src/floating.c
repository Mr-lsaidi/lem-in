/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:35:48 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/01 16:16:17 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pw(int nbr, int puis)
{
	int res;

	res = 1;
	while (puis-- > 0)
		res *= nbr;
	return (res);
}

void	add_man(t_printf *pf, char *pr, int n)
{
	int			i;
	int			carry;
	int			sum;

	carry = 0;
	sum = 0;
	i = ft_strlen(pr) - 1;
	while (i >= 0)
	{
		sum = (pr[i] - '0') + (pf->man[n] - '0') + carry;
		pf->man[n] = (sum % 10) + '0';
		carry = sum / 10;
		i--;
		n--;
	}
	while (carry && n >= 0)
	{
		sum = (pf->man[n] - '0') + carry;
		pf->man[n] = (sum % 10) + '0';
		carry = sum / 10;
		n--;
	}
}

void	conv_man(t_printf *pf)
{
	int			i;
	int			n;
	t_powstr	pr;

	i = 0;
	n = 1;
	while (pf->man[i])
	{
		if (pf->man[i] == '1')
		{
			pr.x = 5;
			pr.n = n;
			power(&pr);
			pf->man[i] = '0';
			add_man(pf, pr.res, i);
			free(pr.res);
		}
		n++;
		i++;
	}
}

void	get_man(t_printf *pf)
{
	int			n;
	int			i;
	char		*tmp;

	n = 62;
	i = 0;
	pf->man = (char*)malloc(sizeof(char) * 65);
	while (n >= 0)
	{
		if (pf->num.flt.man >> n-- & 1)
			pf->man[i++] = '1';
		else
			pf->man[i++] = '0';
	}
	pf->man[i] = '\0';
	conv_man(pf);
	tmp = pf->man;
	if (pf->deno == 1)
		pf->man = ft_strjoin("0", pf->man);
	else
		pf->man = ft_strjoin("1", pf->man);
	fnl_float(pf);
	free(pf->man);
	free(tmp);
}

void	get_exp(t_printf *pf)
{
	int			n;
	uintmax_t	nb;
	int			i;

	n = 14;
	i = 15;
	nb = 0;
	pf->sign = (pf->num.flt.sign == 0 ? 0 : 1);
	if (pf->num.f == 0.0)
	{
		pf->flt = ft_strdup("0.0");
		flt_prec(pf);
	}
	else
	{
		while (n >= 0)
		{
			i--;
			pf->num.flt.exp >> n & 1 ? nb += 1 * pw(2, i) : 1;
			n--;
		}
		pf->deno = (nb == 0 ? 1 : 0);
		pf->exp = nb - 16383;
		get_man(pf);
	}
}
