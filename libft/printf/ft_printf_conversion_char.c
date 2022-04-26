/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_char.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:34:37 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 08:16:08 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*padding_str(t_ft_printf *print_s)
{
	int		padding;
	char	*pad_str;

	padding = print_s->width - 1;
	if (print_s->ladjust)
		print_s->zero = 0;
	if (padding > 0)
	{
		if (!(pad_str = (char *)malloc((padding + 1) * sizeof(char))))
			return (0);
		if (print_s->zero)
			ft_memset(pad_str, '0', padding);
		else
			ft_memset(pad_str, ' ', padding);
		pad_str[padding] = 0;
	}
	else
	{
		if (!(pad_str = (char *)malloc(1 * sizeof(char))))
			return (0);
		pad_str[0] = 0;
	}
	return (pad_str);
}

void		ft_printf_conversion_char(t_ft_printf *print_s)
{
	char c;
	char *padding;

	c = va_arg(print_s->arguments, int);
	padding = padding_str(print_s);
	if (print_s->ladjust)
	{
		ft_printf_putchar(print_s, c);
		ft_printf_putstr(print_s, padding);
	}
	else
	{
		ft_printf_putstr(print_s, padding);
		ft_printf_putchar(print_s, c);
	}
}

void		ft_printf_conversion_percent(t_ft_printf *print_s)
{
	char *padding;

	padding = padding_str(print_s);
	if (print_s->ladjust)
	{
		ft_printf_putchar(print_s, '%');
		ft_printf_putstr(print_s, padding);
	}
	else
	{
		ft_printf_putstr(print_s, padding);
		ft_printf_putchar(print_s, '%');
	}
}
