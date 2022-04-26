/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:08:52 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/14 22:15:26 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**Return sub string which starts from START index and has a lens of LEN
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return ((char *)ft_calloc(1, sizeof(char)));
	sublen = (slen >= (len + start)) ? (len) : (slen - start);
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, sublen);
	sub[sublen] = 0;
	return (sub);
}
