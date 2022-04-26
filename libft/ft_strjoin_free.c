/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:18:32 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/15 20:56:48 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**Joins two string and frees sources.
**ZERO frees none, ONE - first, TWO - second, THREE - both
*/

char	*ft_strjoin_free(char *s1, char *s2, int free_what)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (s1 && (free_what == 1 || free_what == 3))
		free(s1);
	if (s2 && (free_what == 2 || free_what == 3))
		free(s2);
	return (join);
}
