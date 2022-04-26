/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 04:34:04 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 09:28:41 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_conversion_hex(t_ft_printf *print_s)
{
	unsigned int	hex;
	char			*str;

	hex = va_arg(print_s->arguments, unsigned int);
	if (print_s->string[print_s->i] == 'x')
		str = ft_itoa_base(hex, "0123456789abcdef");
	else
		str = ft_itoa_base(hex, "0123456789ABCDEF");
	if (ft_strlen(str) == 1 && str[0] == '0')
		print_s->hex_zero = 1;
	str = ft_printf_precision_numbers(print_s, str);
	print_s->sign = 0;
	if (print_s->hash && !print_s->hex_zero)
		print_s->prefix = 2;
	return (str);
}
