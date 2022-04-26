/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 02:25:02 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/25 05:27:18 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_each_coordinate(t_all *all)
{
	int i;
	int j;
	int s;

	i = 0;
	s = 0;
	while (all->file->map[i])
	{
		j = 0;
		while (all->file->map[i][j])
		{
			if (all->file->map[i][j] == '2')
			{
				all->sprite[s]->x = (double)i + 0.5;
				all->sprite[s]->y = (double)j + 0.5;
				s++;
			}
			j++;
		}
		i++;
	}
}

static int	find_sprite_number(t_all *all)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while (all->file->map[i])
	{
		j = 0;
		while (all->file->map[i][j])
		{
			if (all->file->map[i][j] == '2')
				num++;
			j++;
		}
		i++;
	}
	return (num);
}

void		set_sprite_parameters(t_all *all)
{
	int num;
	int i;

	num = find_sprite_number(all);
	if (!(all->spr->z_buffer = (double *)ft_calloc(all->file->res_x,
					sizeof(double))))
		ft_error("Array Z_Buffer cannot be malloced [spr]");
	if (!(all->sprite = (t_sprite **)ft_calloc(num, sizeof(t_sprite *))))
		ft_error("Structure Sprite cannot be malloced");
	i = 0;
	while (i < num)
	{
		if (!(all->sprite[i] = (t_sprite *)ft_calloc(1, sizeof(t_sprite))))
			ft_error("Structure Sprite[i] cannot be malloced");
		i++;
	}
	all->spr->num = num;
	find_each_coordinate(all);
}
