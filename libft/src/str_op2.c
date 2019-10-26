/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 23:52:14 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 17:00:18 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sum_strme(char *p1, char *p2)
{
	char	*sum;
	int		n;
	int		i;

	if (ft_strlen(p1) > ft_strlen(p2))
		n = ft_strlen(p1) + 1;
	else
		n = ft_strlen(p2) + 1;
	sum = (char *)malloc(sizeof(char) * n + 1);
	sum[n--] = '\0';
	i = ft_strlen(p1) - 1;
	while (i >= 0)
	{
		sum[n--] = p1[i--];
	}
	while (n >= 0)
		sum[n--] = '0';
	return (sum);
}

char	*ft_addme(char *p1, char *p2)
{
	char	*sum;
	int		keep;
	int		res;
	int		n;
	int		i;

	sum = sum_strme(p1, p2);
	keep = 0;
	i = ft_strlen(sum) - 1;
	n = ft_strlen(p2) - 1;
	while (n >= 0)
	{
		sum[i] == '.' ? i-- : 1;
		res = ((sum[i] - '0') + (p2[n] - '0') + keep) % 10;
		keep = ((sum[i] - '0') + (p2[n--] - '0') + keep) / 10;
		sum[i--] = res + '0';
	}
	while (keep)
	{
		sum[i] == '.' ? i-- : 1;
		res = ((sum[i] - '0') + keep) % 10;
		keep = ((sum[i] - '0') + keep) / 10;
		sum[i--] = res + '0';
	}
	return (sum);
}

void	check_infnan(t_printf *pf)
{
	pf->flt = ft_strnew(4);
	pf->flt[3] = '\0';
	if (pf->num.f == 1.0 / 0.0)
	{
		pf->flt[0] = 'i';
		pf->flt[1] = 'n';
		pf->flt[2] = 'f';
	}
	else if (pf->num.f == -1.0 / 0.0)
	{
		pf->flt[0] = 'i';
		pf->flt[1] = 'n';
		pf->flt[2] = 'f';
	}
	else if (pf->num.f != pf->num.f)
	{
		pf->flt[0] = 'n';
		pf->flt[1] = 'a';
		pf->flt[2] = 'n';
	}
	if (pf->num.flt.sign == 0)
		pf->sign = 0;
	else
		pf->sign = 1;
}
