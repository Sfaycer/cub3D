/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:31:53 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/15 20:46:02 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_front(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (s1[i])
	{
		if ((ft_strchr(set, s1[i++])) == 0)
			break ;
	}
	return (i - 1);
}

static size_t	ft_back(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if ((ft_strchr(set, s1[i])) == 0)
			break ;
		if (i == 0)
			break ;
		else
			i--;
	}
	return (i);
}

/*
**Trims side and frees first string
**If side = one, trims front, any other number - trims back
*/

char			*ft_strtrim_side(char *s1, char const *set, int side)
{
	size_t	i;
	size_t	k;
	char	*trim;

	if (!s1 || !set)
		return (0);
	if (side == 1)
	{
		i = ft_front(s1, set);
		k = ft_strlen(s1);
	}
	else
	{
		i = 0;
		k = ft_back(s1, set);
	}
	if (i > k)
		k = 0;
	else
		k = k - i + 1;
	trim = ft_substr(s1, i, k);
	free(s1);
	return (trim);
}
