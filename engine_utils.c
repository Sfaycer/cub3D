/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:29:05 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/27 02:50:48 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(t_all *all)
{
	if (all->key_w)
	{
		if (all->file->map[(int)(all->player->pos_x + all->player->dir_x *
					all->player->move_speed)][(int)(all->player->pos_y)] != '1')
			all->player->pos_x += all->player->dir_x * all->player->move_speed;
		if (all->file->map[(int)(all->player->pos_x)][(int)(all->player->pos_y +
					all->player->dir_y * all->player->move_speed)] != '1')
			all->player->pos_y += all->player->dir_y * all->player->move_speed;
	}
	if (all->key_s)
	{
		if (all->file->map[(int)(all->player->pos_x - all->player->dir_x *
					all->player->move_speed)][(int)(all->player->pos_y)] != '1')
			all->player->pos_x -= all->player->dir_x * all->player->move_speed;
		if (all->file->map[(int)(all->player->pos_x)][(int)(all->player->pos_y -
					all->player->dir_y * all->player->move_speed)] != '1')
			all->player->pos_y -= all->player->dir_y * all->player->move_speed;
	}
}

void	move_left_right(t_all *all)
{
	if (all->key_a)
	{
		if (all->file->map[(int)(all->player->pos_x - all->player->plane_x *
					all->player->move_speed)][(int)(all->player->pos_y)] != '1')
			all->player->pos_x -= all->player->plane_x *
				all->player->move_speed;
		if (all->file->map[(int)(all->player->pos_x)][(int)(all->player->pos_y -
					all->player->plane_y * all->player->move_speed)] != '1')
			all->player->pos_y -= all->player->plane_y *
				all->player->move_speed;
	}
	if (all->key_d)
	{
		if (all->file->map[(int)(all->player->pos_x + all->player->plane_x *
					all->player->move_speed)][(int)(all->player->pos_y)] != '1')
			all->player->pos_x += all->player->plane_x *
				all->player->move_speed;
		if (all->file->map[(int)(all->player->pos_x)][(int)(all->player->pos_y +
					all->player->plane_y * all->player->move_speed)] != '1')
			all->player->pos_y += all->player->plane_y *
				all->player->move_speed;
	}
}

void	rotate_left_right(t_all *all, double old_dir_x, double old_plane_x)
{
	if (all->key_right)
	{
		all->player->dir_x = all->player->dir_x * cos(-all->player->turn_speed)
			- all->player->dir_y * sin(-all->player->turn_speed);
		all->player->dir_y = old_dir_x * sin(-all->player->turn_speed)
			+ all->player->dir_y * cos(-all->player->turn_speed);
		all->player->plane_x = all->player->plane_x *
			cos(-all->player->turn_speed) - all->player->plane_y *
			sin(-all->player->turn_speed);
		all->player->plane_y = old_plane_x * sin(-all->player->turn_speed)
			+ all->player->plane_y * cos(-all->player->turn_speed);
	}
	if (all->key_left)
	{
		all->player->dir_x = all->player->dir_x * cos(all->player->turn_speed)
			- all->player->dir_y * sin(all->player->turn_speed);
		all->player->dir_y = old_dir_x *
			sin(all->player->turn_speed) + all->player->dir_y *
			cos(all->player->turn_speed);
		all->player->plane_x = all->player->plane_x *
			cos(all->player->turn_speed) - all->player->plane_y *
			sin(all->player->turn_speed);
		all->player->plane_y = old_plane_x * sin(all->player->turn_speed)
			+ all->player->plane_y * cos(all->player->turn_speed);
	}
}

void	what_side_got_hit(t_all *all)
{
	all->dda->hit = 1;
	if (all->dda->side == 0)
	{
		if (all->dda->raydir_x < 0)
			all->dda->side = 2;
		else
			all->dda->side = 1;
	}
	else
	{
		if (all->dda->raydir_y < 0)
			all->dda->side = 4;
		else
			all->dda->side = 3;
	}
}

void	calculate_texture_x(t_all *all)
{
	if (all->dda->side < 3)
		all->dda->wall_x = all->player->pos_y + all->dda->walldist *
			all->dda->raydir_y;
	else
		all->dda->wall_x = all->player->pos_x + all->dda->walldist *
			all->dda->raydir_x;
	all->dda->wall_x -= floor(all->dda->wall_x);
	all->dda->tex_x = (int)(all->dda->wall_x *
			(double)all->image[all->dda->side]->width);
	if (all->dda->side < 3 && all->dda->raydir_x > 0)
		all->dda->tex_x = all->image[all->dda->side]->width -
			all->dda->tex_x - 1;
	if (all->dda->side >= 3 && all->dda->raydir_y < 0)
		all->dda->tex_x = all->image[all->dda->side]->width -
			all->dda->tex_x - 1;
}
