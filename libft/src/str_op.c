/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 01:10:36 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/02 17:48:05 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrlen(char *str, int prec)
{
	int		i;

	i = 0;
	while (prec && str[i])
	{
		ft_putchar(str[i]);
		i++;
		prec--;
	}
}

void	multiply(t_powstr *pr, int res_size)
{
	int		i;
	char	*tmp;
	char	*conv;

	pr->carry = 0;
	i = res_size;
	pr->prod = 0;
	while (i >= 0)
	{
		pr->prod = (pr->res[i] - '0') * pr->x + pr->carry;
		pr->res[i] = (pr->prod % 10) + '0';
		pr->carry = pr->prod / 10;
		i--;
	}
	while (pr->carry)
	{
		tmp = pr->res;
		conv = ft_itoa(pr->carry % 10);
		pr->res = ft_strjoin(conv, pr->res);
		free(tmp);
		free(conv);
		pr->carry = pr->carry / 10;
	}
}

void	power(t_powstr *pr)
{
	int		i;
	char	*tmp;

	pr->res = ft_strnew(1);
	pr->temp = pr->x;
	i = 2;
	if (pr->n == 0)
	{
		pr->res[0] = '1';
		pr->res[1] = '\0';
	}
	else
	{
		while (pr->temp != 0)
		{
			tmp = pr->res;
			pr->conv = ft_itoa(pr->temp % 10);
			pr->res = ft_strjoin(pr->conv, pr->res);
			free(tmp);
			free(pr->conv);
			pr->temp = pr->temp / 10;
		}
		while (i++ <= pr->n)
			multiply(pr, ft_strlen(pr->res) - 1);
	}
}

char	*memulti2(char *p1, int n, int i)
{
	int		x;
	int		carry;
	int		mul;
	char	*sum;
	int		j;

	carry = 0;
	j = ft_strlen(p1) - 1;
	x = ft_strlen(p1);
	sum = (char*)malloc(sizeof(char) * (x + 2 + i));
	sum[x + i + 1] = '\0';
	x = x + i;
	while (i-- > 0)
		sum[x--] = '0';
	while (j >= 0)
	{
		mul = ((p1[j] - '0') * n) + carry;
		carry = mul / 10;
		sum[x--] = ((mul % 10) + '0');
		j--;
	}
	sum[x] = (char)(carry + '0');
	return (sum);
}

char	*memulti(char *s1, char *s2)
{
	int			i;
	char		*mult;
	char		*res;
	char		*tmp;
	int			sp;

	i = ft_strlen(s2) - 1;
	res = ft_addme("0", "0");
	sp = 0;
	while (i >= 0)
	{
		tmp = res;
		mult = memulti2(s1, (s2[i--] - '0'), sp);
		res = ft_addme(res, mult);
		free(tmp);
		free(mult);
		sp++;
	}
	while (res[0] == '0')
	{
		tmp = res;
		res = rm_zr(res);
		free(tmp);
	}
	return (res);
}
