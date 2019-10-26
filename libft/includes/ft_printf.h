/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbahaddi <sbahaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:58:32 by sbahaddi          #+#    #+#             */
/*   Updated: 2019/04/05 19:50:24 by sbahaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_flt
{
	unsigned long long	man : 63;
	unsigned long long	intg : 1;
	unsigned long long	exp : 15;
	unsigned long long	sign : 1;
}				t_flt;

union			u_num
{
	t_flt			flt;
	long double		f;
}					num;

typedef struct	s_printf
{
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	long		prec;
	int			xprec;
	int			isprec;
	int			length;
	char		*str;
	int			i;
	int			size;
	int			base;
	union u_num	num;
	int			exp;
	char		*man;
	int			sign;
	int			deno;
	char		*flt;
	char		*fltprec;
	char		*tmp;
	va_list		ap;
}				t_printf;

typedef struct	s_powstr
{
	int		x;
	int		n;
	char	*res;
	int		temp;
	int		carry;
	int		prod;
	char	*conv;
}				t_powstr;

int				ft_printf(const char *format, ...);
void			check_flags(t_printf *pf);
void			check_width(t_printf *pf);
void			check_prec(t_printf *pf);
void			check_length(t_printf *pf);
void			check_conv(t_printf *pf);
void			conv_char(t_printf *pf);
void			conv_string(t_printf *pf);
void			conv_p(t_printf *pf);
void			conv_xx(t_printf *pf);
void			ft_putnbr_base(unsigned long nbr, unsigned long base, int lc);
void			ft_putnbr_baseint(t_printf *pf, uintmax_t nbr,
				int base, int lc);
void			conv_di(t_printf *pf);
void			conv_o(t_printf *pf);
void			ft_putnbr_unsigned(t_printf *pf, uintmax_t nbr,
				int base);
void			conv_u(t_printf *pf);
void			ft_maxnbr(t_printf *pf, intmax_t n, int len);
void			print_width(t_printf *pf);
int				int_len(t_printf *pf, intmax_t nb);
void			flags_di(t_printf *f, intmax_t nb, int len);
void			flags_xxo(t_printf *f, long long int nb, char c, int len);
int				len_hexa(t_printf *pf, uintmax_t nb);
void			flags_scp(t_printf *pf, int len);
void			ft_putstrlen(char *str, int len);
void			print_prec(int prec);
void			conv(t_printf *pf);
void			conv_f(t_printf *pf);
void			get_exp(t_printf *pf);
void			power(t_powstr *pr);
void			fnl_float(t_printf *pf);
void			flt_prec(t_printf *pf);
char			*ft_addme(char *p1, char *p2);
char			*rm_zr(char *str);
char			*memulti(char *s1, char *s2);
char			*ft_addme(char *p1, char *p2);
void			check_infnan(t_printf *pf);
void			flags_f(t_printf *pf, int len, long double f);
void			print_widthf(t_printf *pf, long double f);
void			flags_u(t_printf *pf, uintmax_t nb, int len);
int				uint_len(t_printf *pf, uintmax_t nb);
void			conv_uu(t_printf *pf);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char const *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnew(size_t size);

#endif
