/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:02:27 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/12 23:45:57 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_width(t_ft_printf *print_s)
{
	print_s->width = 0;
	while (ft_isdigit(print_s->string[print_s->i]))
	{
		print_s->width = 10 * print_s->width +
			(print_s->string[print_s->i] - 48);
		print_s->i++;
	}
}

void	ft_printf_width_asterics(t_ft_printf *print_s)
{
	print_s->width = 0;
	print_s->width = va_arg(print_s->arguments, int);
	if (print_s->width < 0)
	{
		print_s->ladjust = 1;
		print_s->width = ft_abs(print_s->width);
	}
	print_s->i++;
}
