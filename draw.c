/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 00:19:35 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/26 22:54:19 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_all *all)
{
	int y;

	y = 0;
	while (y < all->dda->draw_start)
	{
		my_mlx_pixel_put(all->image[0], all->dda->x, y, all->file->ceil_rgb);
		y++;
	}
}

static void	draw_texture(t_all *all)
{
	int y;
	int color;

	y = all->dda->draw_start;
	all->dda->step = 1.0 * all->image[all->dda->side]->height /
		all->dda->line_height;
	all->dda->tex_pos = (all->dda->draw_start - all->file->res_y / 2 +
			all->dda->line_height / 2) * all->dda->step;
	while (y <= all->dda->draw_end)
	{
		all->dda->tex_y = (int)all->dda->tex_pos;
		if (all->dda->tex_y > all->image[all->dda->side]->height - 1)
			all->dda->tex_y = all->image[all->dda->side]->height - 1;
		all->dda->tex_pos += all->dda->step;
		color = my_pixel_take(all->image[all->dda->side], all->dda->tex_x,
				all->dda->tex_y);
		my_mlx_pixel_put(all->image[0], all->dda->x, y, color);
		y++;
	}
}

static void	draw_floor(t_all *all)
{
	int y;

	y = all->dda->draw_end + 1;
	while (y < all->file->res_y)
	{
		my_mlx_pixel_put(all->image[0], all->dda->x, y, all->file->floor_rgb);
		y++;
	}
}

void		draw_line(t_all *all)
{
	calculate_texture_x(all);
	draw_ceiling(all);
	draw_texture(all);
	draw_floor(all);
}
