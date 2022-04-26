/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 01:16:50 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/27 02:54:39 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**Validates map inside borders
*/

static void	check_map_validity_2(t_all *all, int height, int width)
{
	int		x;
	int		y;

	y = 1;
	while (y < height)
	{
		x = 1;
		while (x < width)
		{
			if (ft_strchr("02NSWE", all->file->map[y][x]))
				check_surroundings(all->file->map, y, x);
			x++;
		}
		y++;
	}
}

/*
**Validates borders of map
*/

static void	check_map_validity_1(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	check_player(all);
	while (all->file->map[y])
	{
		if (ft_strchr(" 1", all->file->map[y][0]) &&
				ft_strchr(" 1", all->file->map[y][all->file->map_length - 1]))
			y++;
		else
			ft_error("Map is not enclosed");
	}
	while (x < all->file->map_length)
	{
		if (ft_strchr(" 1", all->file->map[0][x]) &&
				ft_strchr(" 1", all->file->map[y - 1][x]))
			x++;
		else
			ft_error("Map is not enclosed");
	}
	check_map_validity_2(all, y - 1, all->file->map_length - 1);
}

/*
**Map grid function transforms map into rectangle grid
*/

static void	make_map_grid(t_all *all)
{
	int		y;
	int		len;
	char	*spaces;

	y = 0;
	while (all->file->map[y])
	{
		len = ft_strlen(all->file->map[y]);
		if (len < all->file->map_length)
		{
			spaces = get_space_line(len, all->file->map_length);
			all->file->map[y] = ft_strjoin_free(all->file->map[y], spaces, 3);
		}
		y++;
	}
}

void		fill_map(int fd, t_all *all, char *line)
{
	int		count;

	count = 1;
	check_map_line(all, line);
	all->file->map_length = ft_strlen(line);
	all->file->map_lines = ft_strjoin_free(line, "#", 1);
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == -1)
			ft_error("Cannot read file");
		if (check_empty_map_line(fd, line))
			break ;
		line = ft_strtrim_side(line, " ", 2);
		check_map_line(all, line);
		if (all->file->map_length < (int)ft_strlen(line))
			all->file->map_length = ft_strlen(line);
		all->file->map_lines = ft_strjoin_free(all->file->map_lines, line, 3);
		all->file->map_lines = ft_strjoin_free(all->file->map_lines, "#", 1);
	}
	all->file->map = ft_split(all->file->map_lines, '#');
	make_map_grid(all);
	check_map_validity_1(all);
	all->check->map++;
}
