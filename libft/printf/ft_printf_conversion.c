/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:47:26 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/16 18:20:53 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion(t_ft_printf *print_s)
{
	char *str;

	str = 0;
	if (print_s->string[print_s->i] == 'c')
		ft_printf_conversion_char(print_s);
	if (print_s->string[print_s->i] == 's')
		str = ft_printf_conversion_string(print_s);
	if (print_s->string[print_s->i] == '%')
		ft_printf_conversion_percent(print_s);
	if (ft_strchr("di", print_s->string[print_s->i]))
		str = ft_printf_conversion_decimal(print_s);
	if (print_s->string[print_s->i] == 'u')
		str = ft_printf_conversion_unsigned(print_s);
	if (ft_strchr("xX", print_s->string[print_s->i]))
		str = ft_printf_conversion_hex(print_s);
	if (print_s->string[print_s->i] == 'p')
		str = ft_printf_conversion_pointer(print_s);
	if (print_s->string[print_s->i] == 'n')
		ft_printf_conversion_n(print_s);
	if (str)
		ft_printf_output(print_s, str);
}
