/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_n.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:22:22 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/16 18:31:41 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion_n(t_ft_printf *print_s)
{
	int	*count;

	count = va_arg(print_s->arguments, int *);
	*count = print_s->printed;
}
