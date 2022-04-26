/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 01:43:56 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/24 02:19:17 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**Checks on invalid characters in map line
*/

void	check_map_line(t_all *all, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' ||
					line[i] == ' ')
			i++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
				line[i] == 'W')
		{
			all->check->player++;
			all->file->player = line[i];
			i++;
		}
		else
			ft_error("Map contains invalid symbols");
	}
}

int		check_empty_map_line(int fd, char *line)
{
	int		i;
	int		count;

	i = 0;
	skip_spaces(line, &i);
	if (line[i] == 0)
	{
		count = 1;
		free(line);
		while (count > 0)
		{
			i = 0;
			if ((count = get_next_line(fd, &line)) == -1)
				ft_error("Cannot read file");
			skip_spaces(line, &i);
			if (line[i])
				ft_error("Map is not the last parameter");
			free(line);
		}
		return (1);
	}
	return (0);
}

char	*get_space_line(int map, int len)
{
	char	*line;
	int		spaces;

	spaces = len - map;
	if (!(line = (char *)malloc((spaces + 1) * sizeof(char))))
		ft_error("Space line cannot be malloced");
	ft_memset(line, ' ', spaces);
	line[spaces] = 0;
	return (line);
}

void	check_player(t_all *all)
{
	if (all->check->player < 1)
		ft_error("No player position on map");
	else if (all->check->player > 1)
		ft_error("Multiple players positions on map");
}

void	check_surroundings(char **map, int y, int x)
{
	if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ' ||
			map[y + 1][x] == ' ' || map[y][x + 1] == ' ')
		ft_error("Map is not enclosed");
}
