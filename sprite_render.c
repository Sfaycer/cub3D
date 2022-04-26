/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 03:13:09 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/25 05:50:42 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel(t_all *all, int y)
{
	all->spr->color = my_pixel_take(all->image[5], all->spr->tex_x,
		all->spr->tex_y);
	if ((all->spr->color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(all->image[0], all->spr->stripe,
			y, all->spr->color);
}

static void	draw_sprite(t_all *all)
{
	int y;

	while (all->spr->stripe < all->spr->draw_end_x)
	{
		all->spr->tex_x = (int)(256 * (all->spr->stripe -
			(-all->spr->sprite_width / 2 + all->spr->sprite_screen_x)) *
			all->image[5]->width / all->spr->sprite_width) / 256;
		if (all->spr->transform_y > 0 && all->spr->stripe > 0 &&
			all->spr->stripe < all->file->res_x &&
			all->spr->transform_y < all->spr->z_buffer[all->spr->stripe])
		{
			y = all->spr->draw_start_y;
			while (y < all->spr->draw_end_y)
			{
				all->spr->d = y * 256 - all->file->res_y * 128 +
					all->spr->sprite_height * 128;
				all->spr->tex_y = ((all->spr->d * all->image[5]->height) /
					all->spr->sprite_height) / 256;
				draw_pixel(all, y);
				y++;
			}
		}
		all->spr->stripe++;
	}
}

void		render_sprites(t_all *all)
{
	int i;

	sprite_distance(all);
	sort_sprites(all);
	i = 0;
	while (i < all->spr->num)
	{
		all->spr->sprite_x = all->sprite[i]->x - all->player->pos_x;
		all->spr->sprite_y = all->sprite[i]->y - all->player->pos_y;
		all->spr->inv_det = 1.0 / (all->player->plane_x * all->player->dir_y -
			all->player->dir_x * all->player->plane_y);
		all->spr->transform_x = all->spr->inv_det * (all->player->dir_y *
			all->spr->sprite_x - all->player->dir_x * all->spr->sprite_y);
		all->spr->transform_y = all->spr->inv_det * (-all->player->plane_y *
			all->spr->sprite_x + all->player->plane_x * all->spr->sprite_y);
		all->spr->sprite_screen_x = (int)((all->file->res_x / 2) * (1 +
			all->spr->transform_x / all->spr->transform_y));
		calculate_sprite_height(all);
		calculate_sprite_width(all);
		all->spr->stripe = all->spr->draw_start_x;
		draw_sprite(all);
		i++;
	}
}
