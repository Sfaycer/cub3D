/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 21:34:27 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/22 02:29:39 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	validate_parameters_aux(t_check *check)
{
	if (check->r > 1)
		ft_error("Resolution parameter is more than 1 [FILE]");
	if (check->no > 1)
		ft_error("North texture parameter is more than 1 [FILE]");
	if (check->so > 1)
		ft_error("South texture parameter is more than 1 [FILE]");
	if (check->we > 1)
		ft_error("West texture parameter is more than 1 [FILE]");
	if (check->ea > 1)
		ft_error("East texture parameter is more than 1 [FILE]");
	if (check->s > 1)
		ft_error("Sprite texture parameter is more than 1 [FILE]");
	if (check->f > 1)
		ft_error("Floor color parameter is more than 1 [FILE]");
	if (check->c > 1)
		ft_error("Ceiling color parameter is more than 1 [FILE]");
}

void		validate_parameters(t_check *check)
{
	if (check->r < 1)
		ft_error("Resolution is missing [FILE]");
	if (check->no < 1)
		ft_error("North texture is missing [FILE]");
	if (check->so < 1)
		ft_error("South texture is missing [FILE]");
	if (check->we < 1)
		ft_error("West texture is missing [FILE]");
	if (check->ea < 1)
		ft_error("East texture is missing [FILE]");
	if (check->s < 1)
		ft_error("Sprite texture is missing [FILE]");
	if (check->f < 1)
		ft_error("Floor color is missing [FILE]");
	if (check->c < 1)
		ft_error("Ceiling color is missing [FILE]");
	if (check->map < 1)
		ft_error("Map is missing [FILE]");
	validate_parameters_aux(check);
}

int			ft_atoi_trick(char *line)
{
	char	*trick_line;
	int		num;

	trick_line = ft_substr(line, 0, 6);
	num = ft_atoi(trick_line);
	free(trick_line);
	return (num);
}

void		skip_digits_and_spaces(char *line, int *i)
{
	while (ft_isdigit(line[*i]))
		(*i)++;
	if (line[*i] == 32 || line[*i] == 9)
		skip_spaces(line, i);
	else if (line[*i])
		ft_error("There's some garbage in R identifier [FILE]");
}
