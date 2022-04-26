/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 04:15:01 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/25 06:14:22 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	*tmp;

	i = 0;
	while (i < all->spr->num - 1)
	{
		j = 0;
		while (j < all->spr->num - i - 1)
		{
			if (all->sprite[j]->dist < all->sprite[j + 1]->dist)
			{
				tmp = all->sprite[j];
				all->sprite[j] = all->sprite[j + 1];
				all->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprite_distance(t_all *all)
{
	int			i;

	i = 0;
	while (i < all->spr->num)
	{
		all->sprite[i]->dist = ((all->player->pos_x - all->sprite[i]->x) *
			(all->player->pos_x - all->sprite[i]->x) + (all->player->pos_y -
			all->sprite[i]->y) * (all->player->pos_y - all->sprite[i]->y));
		i++;
	}
}

void	calculate_sprite_height(t_all *all)
{
	all->spr->sprite_height = abs((int)(all->file->res_y /
		all->spr->transform_y));
	all->spr->draw_start_y = -all->spr->sprite_height / 2 +
			all->file->res_y / 2;
	if (all->spr->draw_start_y < 0)
		all->spr->draw_start_y = 0;
	all->spr->draw_end_y = all->spr->sprite_height / 2 +
			all->file->res_y / 2;
	if (all->spr->draw_end_y >= all->file->res_y)
		all->spr->draw_end_y = all->file->res_y - 1;
}

void	calculate_sprite_width(t_all *all)
{
	all->spr->sprite_width = abs((int)(all->file->res_y /
		all->spr->transform_y));
	all->spr->draw_start_x = -all->spr->sprite_width / 2 +
			all->spr->sprite_screen_x;
	if (all->spr->draw_start_x < 0)
		all->spr->draw_start_x = 0;
	all->spr->draw_end_x = all->spr->sprite_width / 2 +
			all->spr->sprite_screen_x;
	if (all->spr->draw_end_x >= all->file->res_x)
		all->spr->draw_end_x = all->file->res_x - 1;
}
