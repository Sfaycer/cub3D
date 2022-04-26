/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 04:26:40 by dkarisa           #+#    #+#             */
/*   Updated: 2020/11/21 05:50:20 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dst;
	unsigned char symbol;

	dst = (unsigned char *)b;
	symbol = (unsigned char)c;
	while (len--)
		*dst++ = symbol;
	return (b);
}
