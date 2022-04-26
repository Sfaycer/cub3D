/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:48:06 by dkarisa           #+#    #+#             */
/*   Updated: 2021/01/17 08:33:44 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(t_ft_printf *print_s, char *s)
{
	char *ptr;

	ptr = s;
	if (s)
	{
		while (*s)
			ft_printf_putchar(print_s, *s++);
		free(ptr);
	}
}
