/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parameters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:00:10 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/25 06:15:12 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

static void	file_floor_n_ceiling(t_all *all, char *line, char flag, int i)
{
	int r;
	int g;
	int b;

	skip_spaces(line, &i);
	r = ft_atoi_trick(&line[i]);
	check_color_file(line, &i);
	g = ft_atoi_trick(&line[i]);
	check_color_file(line, &i);
	b = ft_atoi_trick(&line[i]);
	check_c_f_on_trash(line, i);
	if (!((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)))
		ft_error("Color values should be in range 0-255 [FILE]");
	if (flag == 'F')
	{
		all->check->f++;
		all->file->floor_rgb = create_trgb(0, r, g, b);
	}
	else
	{
		all->check->c++;
		all->file->ceil_rgb = create_trgb(0, r, g, b);
	}
}

static void	file_texture(t_all *all, char *line, int *i)
{
	char	*flag;

	flag = ft_substr(line, *i, 2);
	if (ft_strncmp(flag, "NO", 2) == 0)
		fill_texture(&all->file->no, &all->check->no, line, *i + 2);
	else if (ft_strncmp(flag, "SO", 2) == 0)
		fill_texture(&all->file->so, &all->check->so, line, *i + 2);
	else if (ft_strncmp(flag, "WE", 2) == 0)
		fill_texture(&all->file->we, &all->check->we, line, *i + 2);
	else if (ft_strncmp(flag, "EA", 2) == 0)
		fill_texture(&all->file->ea, &all->check->ea, line, *i + 2);
	else if (ft_strncmp(flag, "S", 1) == 0)
		fill_texture(&all->file->s, &all->check->s, line, *i + 1);
	free(flag);
}

static void	file_resolution(t_all *all, char *line, int i)
{
	int		x;
	int		y;

	mlx_get_screen_size(all->mlx->mlx_ptr, &x, &y);
	skip_spaces(line, &i);
	if ((all->file->res_x = ft_atoi_trick(&line[i])) <= 0)
		ft_error("Incorrect width [FILE]");
	skip_digits_and_spaces(line, &i);
	if ((all->file->res_y = ft_atoi_trick(&line[i])) <= 0)
		ft_error("Incorrect height [FILE]");
	skip_digits_and_spaces(line, &i);
	if (line[i])
		ft_error("There's some garbage in R identifier [FILE]");
	if (all->file->res_x > x)
		all->file->res_x = x;
	if (all->file->res_y > y)
		all->file->res_y = y;
	all->check->r++;
}

static void	fill_parameters(t_all *all, char *line, int *i)
{
	if (line[*i] == 0)
		return ;
	if (line[*i] == 'R' && (line[*i + 1] == 32 || line[*i + 1] == 9))
		file_resolution(all, line, *i + 1);
	else if (((line[*i] == 'N' && line[*i + 1] == 'O') ||
			(line[*i] == 'S' && line[*i + 1] == 'O') ||
			(line[*i] == 'W' && line[*i + 1] == 'E') ||
			(line[*i] == 'E' && line[*i + 1] == 'A')) &&
			(line[*i + 2] == 32 || line[*i + 2] == 9))
		file_texture(all, line, i);
	else if (line[*i] == 'S' && (line[*i + 1] == 32 || line[*i + 1] == 9))
		file_texture(all, line, i);
	else if (line[*i] == 'F' && (line[*i + 1] == 32 || line[*i + 1] == 9))
		file_floor_n_ceiling(all, line, 'F', *i + 1);
	else if (line[*i] == 'C' && (line[*i + 1] == 32 || line[*i + 1] == 9))
		file_floor_n_ceiling(all, line, 'C', *i + 1);
	else
		ft_error("Invalid identifier [FILE]");
}

void		imbibe_file_parameters(int fd, t_all *all)
{
	int		count;
	char	*line;
	int		i;

	count = 1;
	if (!(all->file = (t_file *)ft_calloc(1, sizeof(t_file))))
		ft_error("Structure File cannot be malloced");
	while (count > 0)
	{
		i = 0;
		if ((count = get_next_line(fd, &line)) == -1)
			ft_error("Cannot read file");
		skip_spaces(line, &i);
		if (ft_strchr("012", line[i]) && line[i] != 0)
		{
			fill_map(fd, all, line);
			break ;
		}
		else
		{
			fill_parameters(all, line, &i);
			free(line);
		}
	}
	validate_parameters(all->check);
}
