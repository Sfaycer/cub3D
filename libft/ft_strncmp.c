/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 00:55:22 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/14 22:48:00 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Compares two strings up to N characters
**e.g. if N = two, then only two symbols will be compared
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n)
	{
		while ((*p1 == *p2) && (n - 1) && *p1 && *p2)
		{
			p1++;
			p2++;
			n--;
		}
	}
	else
		return (0);
	return (*p1 - *p2);
}
