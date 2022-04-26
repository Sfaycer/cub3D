/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 06:03:12 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/22 06:04:04 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_c_f_on_trash(char *line, int i)
{
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] && (line[i] == 32 || line[i] == 9))
		i++;
	if (line[i])
		ft_error("There's some trash in F or C identifier [FILE]");
}
