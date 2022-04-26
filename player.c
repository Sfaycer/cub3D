/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 05:36:32 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/26 20:31:04 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static void	player_dir_n_plane(t_all *all)
{
	if (all->file->player == 'N')
	{
		all->player->plane_y = 0.66;
		all->player->dir_x = -1;
	}
	if (all->file->player == 'S')
	{
		all->player->plane_y = -0.66;
		all->player->dir_x = 1;
	}
	if (all->file->player == 'W')
	{
		all->player->plane_x = -0.66;
		all->player->dir_y = -1;
	}
	if (all->file->player == 'E')
	{
		all->player->plane_x = 0.66;
		all->player->dir_y = 1;
	}
}

void		set_player_parameters(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->file->map[i])
	{
		j = 0;
		while (all->file->map[i][j])
		{
			if (is_player(all->file->map[i][j]))
			{
				all->player->pos_x = (double)i + 0.5;
				all->player->pos_y = (double)j + 0.5;
				break ;
			}
			j++;
		}
		i++;
	}
	all->player->move_speed = 0.1;
	all->player->turn_speed = 0.05;
	player_dir_n_plane(all);
}
