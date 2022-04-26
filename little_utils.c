/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:59:23 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/26 23:53:51 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_spaces(char *line, int *i)
{
	while (line[*i] != 0 && (line[*i] == 32 || line[*i] == 9))
		(*i)++;
}

void	ft_error(char *text)
{
	ft_printf("Error\n");
	ft_printf("%s\n", text);
	exit(EXIT_FAILURE);
}

/*
**Fills path to texture and increments check parameter
*/

void	fill_texture(char **check, int *c, char *line, int i)
{
	skip_spaces(line, &i);
	if (ft_strncmp(&line[i], "./", 2) == 0)
		*check = ft_strtrim(&line[i], " \t");
	else
		ft_error("Path to texture does not start with ./");
	(*c)++;
}

void	check_color_file(char *line, int *i)
{
	while (ft_isdigit(line[*i]))
		(*i)++;
	if (line[*i] == ',')
		(*i)++;
	else
		ft_error("Color in the file is invalid");
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
