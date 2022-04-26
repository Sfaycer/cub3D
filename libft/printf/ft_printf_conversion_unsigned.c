/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_unsigned.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 04:14:36 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/16 20:14:46 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_conversion_unsigned(t_ft_printf *print_s)
{
	unsigned int	decimal;
	char			*str;

	decimal = va_arg(print_s->arguments, unsigned int);
	str = ft_itoa_base(decimal, "0123456789");
	str = ft_printf_precision_numbers(print_s, str);
	print_s->sign = 0;
	return (str);
}
