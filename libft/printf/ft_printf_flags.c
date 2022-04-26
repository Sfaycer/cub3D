/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:53:18 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 07:15:11 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag_minus(t_ft_printf *print_s)
{
	print_s->ladjust = 1;
	print_s->i++;
}

void	ft_printf_flag_zero(t_ft_printf *print_s)
{
	print_s->zero = 1;
	print_s->i++;
}

void	ft_printf_flag_plus(t_ft_printf *print_s)
{
	print_s->plus = 1;
	print_s->sign = 1;
	print_s->i++;
}

void	ft_printf_flag_space(t_ft_printf *print_s)
{
	print_s->space = 1;
	print_s->sign = 1;
	print_s->i++;
}

void	ft_printf_flag_hash(t_ft_printf *print_s)
{
	print_s->hash = 1;
	print_s->i++;
}
