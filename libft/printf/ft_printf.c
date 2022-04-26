/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:50:33 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 09:29:11 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_initialize(t_ft_printf *print_s)
{
	print_s->ladjust = 0;
	print_s->width = 0;
	print_s->precision = -1;
	print_s->negative = 0;
	print_s->zero = 0;
	print_s->plus = 0;
	print_s->space = 0;
	print_s->sign = 0;
	print_s->hash = 0;
	print_s->prefix = 0;
	print_s->hex_zero = 0;
}

static void	ft_printf_flag_checker(t_ft_printf *print_s)
{
	if (print_s->string[print_s->i] == '-')
		ft_printf_flag_minus(print_s);
	if (print_s->string[print_s->i] == '0')
		ft_printf_flag_zero(print_s);
	if (ft_isdigit(print_s->string[print_s->i]))
		ft_printf_width(print_s);
	if (print_s->string[print_s->i] == '*')
		ft_printf_width_asterics(print_s);
	if (print_s->string[print_s->i] == '.')
		ft_printf_precision(print_s);
	if (print_s->string[print_s->i] == '+')
		ft_printf_flag_plus(print_s);
	if (print_s->string[print_s->i] == ' ')
		ft_printf_flag_space(print_s);
	if (print_s->string[print_s->i] == '#')
		ft_printf_flag_hash(print_s);
}

static void	ft_printf_processing(t_ft_printf *print_s)
{
	ft_printf_initialize(print_s);
	print_s->i++;
	while (ft_isdigit(print_s->string[print_s->i]) ||
			ft_strchr("-.*0# +", print_s->string[print_s->i]))
	{
		ft_printf_flag_checker(print_s);
		if (!print_s->string[print_s->i])
			return ;
	}
	if (ft_strchr("cspdiuxXn%", print_s->string[print_s->i]))
		ft_printf_conversion(print_s);
	else
		ft_printf_putchar(print_s, print_s->string[print_s->i]);
}

static void	ft_printf_handler(t_ft_printf *print_s)
{
	while (print_s->string[print_s->i])
	{
		if (print_s->string[print_s->i] == '%')
			ft_printf_processing(print_s);
		else
			ft_printf_putchar(print_s, print_s->string[print_s->i]);
		if (print_s->string[print_s->i])
			print_s->i++;
	}
}

int			ft_printf(const char *string, ...)
{
	t_ft_printf	print_s;

	print_s.string = string;
	print_s.printed = 0;
	print_s.i = 0;
	va_start(print_s.arguments, string);
	ft_printf_handler(&print_s);
	va_end(print_s.arguments);
	return (print_s.printed);
}
