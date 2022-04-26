/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_decimal.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 03:41:33 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/16 19:33:53 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_conversion_decimal(t_ft_printf *print_s)
{
	long	decimal;
	char	*str;

	decimal = va_arg(print_s->arguments, int);
	str = ft_itoa_base(ft_abs(decimal), "0123456789");
	if (decimal < 0)
	{
		print_s->negative = 1;
		print_s->sign = 1;
	}
	str = ft_printf_precision_numbers(print_s, str);
	return (str);
}
