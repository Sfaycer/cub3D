/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_numbers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:44:26 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/16 19:32:38 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sign_handler(t_ft_printf *print_s, char *final_str)
{
	if (print_s->negative)
		final_str = ft_strjoin_free("-", final_str, 2);
	else
	{
		if (print_s->plus)
			final_str = ft_strjoin_free("+", final_str, 2);
		else if (print_s->space)
			final_str = ft_strjoin_free(" ", final_str, 2);
	}
	print_s->negative = 0;
	print_s->plus = 0;
	print_s->space = 0;
	print_s->sign = 0;
	return (final_str);
}

static char	*ft_printf_zero_fill(t_ft_printf *print_s, char *str)
{
	char	*final_str;
	int		zero_count;

	zero_count = print_s->precision - (int)ft_strlen(str);
	if (!(final_str = (char *)malloc((zero_count + 1) * sizeof(char))))
		return (str);
	ft_memset(final_str, '0', zero_count);
	final_str[zero_count] = 0;
	final_str = ft_strjoin_free(final_str, str, 3);
	if (ft_strchr("di", print_s->string[print_s->i]))
		final_str = sign_handler(print_s, final_str);
	return (final_str);
}

char		*ft_printf_precision_numbers(t_ft_printf *print_s, char *str)
{
	char	*final_str;

	if (!str)
		return (0);
	if (print_s->precision == 0 && str[0] == 48 && ft_strlen(str) == 1)
	{
		if (!(final_str = (char *)malloc(1 * sizeof(char))))
			return (str);
		final_str[0] = 0;
		free(str);
		return (final_str);
	}
	if (print_s->precision > (int)ft_strlen(str))
		final_str = ft_printf_zero_fill(print_s, str);
	else
		final_str = str;
	return (final_str);
}
