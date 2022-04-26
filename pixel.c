/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 02:29:19 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/24 05:06:55 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x *
			(image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		my_pixel_take(t_image *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x *
			(image->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}
