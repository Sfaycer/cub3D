/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:52:09 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 11:54:26 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*padding_str(t_ft_printf *print_s, char *str)
{
	int		padding;
	char	*pad_str;

	padding = print_s->width - ft_strlen(str) - print_s->sign - print_s->prefix;
	if (print_s->precision >= 0 || print_s->ladjust)
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

static char	*sign_handler(t_ft_printf *print_s)
{
	char	*sign;

	sign = 0;
	if (ft_strchr("di", print_s->string[print_s->i]))
	{
		if (print_s->negative)
			sign = ft_strdup("-");
		else
		{
			if (print_s->plus)
				sign = ft_strdup("+");
			else if (print_s->space)
				sign = ft_strdup(" ");
		}
	}
	return (sign);
}

static char	*prefix_handler(t_ft_printf *print_s)
{
	char	*prefix;

	prefix = 0;
	if ((print_s->string[print_s->i] == 'p') ||
		((ft_strchr("xX", print_s->string[print_s->i])) && print_s->hash &&
		!print_s->hex_zero))
	{
		if (ft_strchr("xp", print_s->string[print_s->i]))
			prefix = ft_strdup("0x");
		else
			prefix = ft_strdup("0X");
	}
	return (prefix);
}

void		ft_printf_output(t_ft_printf *print_s, char *str)
{
	char	*pad_str;

	pad_str = padding_str(print_s, str);
	if (!print_s->zero && !print_s->ladjust)
		ft_printf_putstr(print_s, pad_str);
	if (print_s->sign)
		ft_printf_putstr(print_s, sign_handler(print_s));
	ft_printf_putstr(print_s, prefix_handler(print_s));
	if (print_s->zero)
		ft_printf_putstr(print_s, pad_str);
	ft_printf_putstr(print_s, str);
	if (print_s->ladjust)
		ft_printf_putstr(print_s, pad_str);
	str = 0;
}
