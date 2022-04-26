/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:01:02 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/25 07:04:39 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**cameraX - all->dda->camera_x
**posX, posY - all->player->pos_x , all->player->pos_y
**dirX, dirY - all->player->dir_x , all->player->dir_y
**planeX, planeY - all->player->plane_x, all->player->plane_y
**rayDirX, rayDirY - all->dda->raydir_x, all->dda->raydir_y
**mapX, mapY - all->dda
**Sides: 1 - ea, 2 - we, 3 - no, 4 - so
*/

static void	calculate_walldist_lineheight(t_all *all)
{
	if (all->dda->side < 3)
		all->dda->walldist = (all->dda->map_x - all->player->pos_x +
				(1 - all->dda->step_x) / 2) / all->dda->raydir_x;
	else
		all->dda->walldist = (all->dda->map_y - all->player->pos_y +
				(1 - all->dda->step_y) / 2) / all->dda->raydir_y;
	all->dda->line_height = (int)(all->file->res_y / all->dda->walldist);
	all->dda->draw_start = -all->dda->line_height / 2 + all->file->res_y / 2;
	if (all->dda->draw_start < 0)
		all->dda->draw_start = 0;
	all->dda->draw_end = all->dda->line_height / 2 + all->file->res_y / 2;
	if (all->dda->draw_end >= all->file->res_y)
		all->dda->draw_end = all->file->res_y - 1;
}

static void	perform_dda(t_all *all)
{
	all->dda->side = 0;
	all->dda->hit = 0;
	while (all->dda->hit == 0)
	{
		if (all->dda->sidedist_x < all->dda->sidedist_y)
		{
			all->dda->sidedist_x += all->dda->deltadist_x;
			all->dda->map_x += all->dda->step_x;
			all->dda->side = 0;
		}
		else
		{
			all->dda->sidedist_y += all->dda->deltadist_y;
			all->dda->map_y += all->dda->step_y;
			all->dda->side = 1;
		}
		if (all->file->map[all->dda->map_x][all->dda->map_y] == '1')
			what_side_got_hit(all);
	}
}

static void	calculate_step_n_sidedist(t_all *all)
{
	if (all->dda->raydir_x < 0)
	{
		all->dda->step_x = -1;
		all->dda->sidedist_x = (all->player->pos_x - all->dda->map_x) *
			all->dda->deltadist_x;
	}
	else
	{
		all->dda->step_x = 1;
		all->dda->sidedist_x = (all->dda->map_x + 1.0 - all->player->pos_x) *
			all->dda->deltadist_x;
	}
	if (all->dda->raydir_y < 0)
	{
		all->dda->step_y = -1;
		all->dda->sidedist_y = (all->player->pos_y - all->dda->map_y) *
			all->dda->deltadist_y;
	}
	else
	{
		all->dda->step_y = 1;
		all->dda->sidedist_y = (all->dda->map_y + 1.0 - all->player->pos_y) *
			all->dda->deltadist_y;
	}
}

static void	calculate_dda(t_all *all)
{
	all->dda->camera_x = 2 * (double)all->dda->x / (double)all->file->res_x - 1;
	all->dda->raydir_x = all->player->dir_x +
		all->player->plane_x * all->dda->camera_x;
	all->dda->raydir_y = all->player->dir_y +
		all->player->plane_y * all->dda->camera_x;
	all->dda->map_x = (int)all->player->pos_x;
	all->dda->map_y = (int)all->player->pos_y;
	all->dda->deltadist_x = fabs(1 / all->dda->raydir_x);
	all->dda->deltadist_y = fabs(1 / all->dda->raydir_y);
	calculate_step_n_sidedist(all);
	perform_dda(all);
	calculate_walldist_lineheight(all);
}

void		render_frame(t_all *all)
{
	if (all->key_w || all->key_s)
		move_forward_backward(all);
	if (all->key_a || all->key_d)
		move_left_right(all);
	if (all->key_left || all->key_right)
		rotate_left_right(all, all->player->dir_x, all->player->plane_x);
	all->dda->x = 0;
	while (all->dda->x < all->file->res_x)
	{
		calculate_dda(all);
		draw_line(all);
		all->spr->z_buffer[all->dda->x] = all->dda->walldist;
		all->dda->x++;
	}
	render_sprites(all);
}
