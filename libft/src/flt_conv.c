/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flt_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 03:12:49 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/01 17:28:16 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rm_zr(char *str)
{
	int		i;
	char	*res;

	i = 1;
	if (str[0] == '0')
	{
		res = (char*)malloc(sizeof(char) * ft_strlen(str));
		while (str[i])
		{
			res[i - 1] = str[i];
			i++;
		}
		res[i - 1] = '\0';
	}
	else
		res = ft_strdup(str);
	return (res);
}

char	*fn_flt(char *flt, int n)
{
	char	*res;
	int		i;

	i = ft_strlen(flt) - 1;
	res = ft_strnew(ft_strlen(flt) + 2);
	res[ft_strlen(flt) + 2] = '\0';
	while (n > 0)
	{
		res[i + 1] = flt[i];
		i--;
		n--;
	}
	res[i + 1] = '.';
	while (i >= 0)
	{
		res[i] = flt[i];
		i--;
	}
	return (res);
}

char	*fn_flt2(char *flt, int n)
{
	char	*tmp;

	if (n > 0)
	{
		while (n > 0)
		{
			tmp = flt;
			flt = ft_strjoin("0", flt);
			free(tmp);
			n--;
		}
	}
	tmp = flt;
	flt = ft_strjoin("0.", flt);
	free(tmp);
	return (flt);
}

void	fnl_float2(t_printf *pf, char *str)
{
	char		*tmp;
	int			vrg;

	vrg = ft_strlen(pf->man) - 1;
	if (pf->exp >= 0)
	{
		tmp = str;
		str = fn_flt(str, vrg);
		free(tmp);
	}
	else
		str = fn_flt2(str, (vrg + (-pf->exp)) - ft_strlen(str));
	pf->flt = str;
	flt_prec(pf);
}

void	fnl_float(t_printf *pf)
{
	char		*str;
	t_powstr	pr;

	if (pf->exp >= 0)
	{
		pr.x = 2;
		pr.n = pf->exp;
		power(&pr);
		str = memulti(pf->man, pr.res);
		free(pr.res);
	}
	else
	{
		pr.x = 5;
		pr.n = pf->exp * -1;
		power(&pr);
		str = memulti(pf->man, pr.res);
		free(pr.res);
	}
	fnl_float2(pf, str);
}
