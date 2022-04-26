/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:44:26 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/12 12:58:21 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_precision(t_ft_printf *print_s)
{
	print_s->precision = 0;
	print_s->i++;
	if (print_s->string[print_s->i] == '*')
	{
		print_s->precision = va_arg(print_s->arguments, int);
		print_s->i++;
		return ;
	}
	if (!(ft_isdigit(print_s->string[print_s->i])))
		return ;
	while (ft_isdigit(print_s->string[print_s->i]))
	{
		print_s->precision = 10 * print_s->precision +
			(print_s->string[print_s->i] - 48);
		print_s->i++;
	}
}
