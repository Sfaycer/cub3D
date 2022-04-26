/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_pointer.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 05:19:03 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 11:53:44 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_conversion_pointer(t_ft_printf *print_s)
{
	unsigned long	ptr;
	char			*str;

	ptr = (unsigned long)va_arg(print_s->arguments, void *);
	str = ft_itoa_u_base(ptr, "0123456789abcdef");
	str = ft_printf_precision_numbers(print_s, str);
	print_s->prefix = 2;
	print_s->sign = 0;
	return (str);
}
