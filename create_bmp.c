/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 22:32:52 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/26 05:48:33 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

/*
**0, 1 - BM; 10 - 54
*/

static int	bitmap_file_header(int fd, t_all *all)
{
	static unsigned char	header[14];
	int						padding;
	int						bytes;

	padding = all->file->res_x % 4;
	bytes = 14 + 40 + (all->file->res_x * 3 + padding) * all->file->res_y;
	header[0] = 0x42;
	header[1] = 0x4D;
	header[2] = (unsigned char)bytes;
	header[3] = (unsigned char)(bytes >> 8);
	header[4] = (unsigned char)(bytes >> 16);
	header[5] = (unsigned char)(bytes >> 24);
	header[10] = 0x36;
	write(fd, header, 14);
	return (padding);
}

/*
**0 - 40; 14 - 24
*/

static void	bitmap_info_header(int fd, t_all *all)
{
	static unsigned char	header[40];

	header[0] = 0x28;
	header[4] = (unsigned char)all->file->res_x;
	header[5] = (unsigned char)(all->file->res_x >> 8);
	header[6] = (unsigned char)(all->file->res_x >> 16);
	header[7] = (unsigned char)(all->file->res_x >> 24);
	header[8] = (unsigned char)all->file->res_y;
	header[9] = (unsigned char)(all->file->res_y >> 8);
	header[10] = (unsigned char)(all->file->res_y >> 16);
	header[11] = (unsigned char)(all->file->res_y >> 24);
	header[12] = 0x01;
	header[14] = 0x18;
	write(fd, header, 40);
}

static void	add_padding(int fd, int padding)
{
	while (padding--)
		ft_putchar_fd(0, fd);
}

static void	bitmap_pixels(int fd, int padding, t_all *all)
{
	int						x;
	int						y;
	unsigned char			rgb[3];
	int						color;

	y = all->file->res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < all->file->res_x)
		{
			color = my_pixel_take(all->image[0], x, y);
			rgb[0] = (unsigned char)color;
			rgb[1] = (unsigned char)(color >> 8);
			rgb[2] = (unsigned char)(color >> 16);
			write(fd, rgb, 3);
			x++;
		}
		add_padding(fd, padding);
		y--;
	}
}

void		create_bmp(char *file, t_all *all)
{
	int						fd;
	int						padding;

	preprocessing_parameters(file, all);
	if ((fd = open("cub3D.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
		ft_error("file cub3D.bmp can't be created or accessed");
	padding = bitmap_file_header(fd, all);
	bitmap_info_header(fd, all);
	render_frame(all);
	bitmap_pixels(fd, padding, all);
}
