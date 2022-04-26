/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_string.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:41:11 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 08:53:38 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_precision_string(t_ft_printf *print_s, char *str)
{
	char *final_str;

	if (!str)
		return (str);
	if (print_s->precision >= 0)
	{
		if (!(final_str = (char *)malloc((print_s->precision + 1) *
						sizeof(char))))
			return (str);
		ft_memcpy(final_str, str, print_s->precision);
		final_str[print_s->precision] = 0;
		free(str);
	}
	else
		final_str = str;
	print_s->precision = -1;
	return (final_str);
}

char		*ft_printf_conversion_string(t_ft_printf *print_s)
{
	char *str;

	str = va_arg(print_s->arguments, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = strdup(str);
	str = ft_printf_precision_string(print_s, str);
	print_s->sign = 0;
	return (str);
}
