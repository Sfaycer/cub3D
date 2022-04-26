/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:23:11 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/27 03:02:05 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

static int	key_pressed(int key, t_all *all)
{
	if (key == 13)
		all->key_w = 1;
	if (key == 0)
		all->key_a = 1;
	if (key == 1)
		all->key_s = 1;
	if (key == 2)
		all->key_d = 1;
	if (key == 123)
		all->key_left = 1;
	if (key == 124)
		all->key_right = 1;
	if (key == 53)
		close_win();
	return (0);
}

static int	key_released(int key, t_all *all)
{
	if (key == 13)
		all->key_w = 0;
	if (key == 0)
		all->key_a = 0;
	if (key == 1)
		all->key_s = 0;
	if (key == 2)
		all->key_d = 0;
	if (key == 123)
		all->key_left = 0;
	if (key == 124)
		all->key_right = 0;
	return (0);
}

static int	render(t_all *all)
{
	render_frame(all);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win_ptr,
			all->image[0]->img, 0, 0);
	mlx_do_sync(all->mlx->mlx_ptr);
	return (0);
}

void		run_engine(t_all *all)
{
	all->mlx->win_ptr = mlx_new_window(all->mlx->mlx_ptr, all->file->res_x,
		all->file->res_y, "Poor man's Doom");
	mlx_hook(all->mlx->win_ptr, 17, 0, close_win, all);
	mlx_hook(all->mlx->win_ptr, 2, 0, key_pressed, all);
	mlx_hook(all->mlx->win_ptr, 3, 0, key_released, all);
	mlx_loop_hook(all->mlx->mlx_ptr, render, all);
	mlx_loop(all->mlx->mlx_ptr);
}
