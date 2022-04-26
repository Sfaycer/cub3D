/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarisa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:37:42 by dkarisa           #+#    #+#             */
/*   Updated: 2021/03/27 03:02:24 by dkarisa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**Checks if file name ends on .cub
*/

static int	check_file_name(char *name)
{
	int count;

	count = ft_strlen(name);
	if (!(name[count - 4] == '.' && name[count - 3] == 'c' &&
				name[count - 2] == 'u' && name[count - 1] == 'b'))
		return (0);
	return (1);
}

/*
**Fill image structures with corresponding path and data_addr
*/

static void	set_images_to_path(t_all *all, int i, char *path)
{
	all->image[i]->img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, path,
			&all->image[i]->width, &all->image[i]->height);
	if (all->image[i]->img == 0)
		ft_error("Invalid texture path");
	all->image[i]->addr = mlx_get_data_addr(all->image[i]->img,
			&all->image[i]->bits_per_pixel, &all->image[i]->line_length,
			&all->image[i]->endian);
}

/*
**Mallocs check, mlx, player, images Structures (ft_calloc annuls parameters)
*/

static void	init_malloc_all_1(t_all *all)
{
	int i;

	if (!(all->check = (t_check *)ft_calloc(1, sizeof(t_check))))
		ft_error("Structure Check cannot be malloced");
	if (!(all->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		ft_error("Structure MLX cannot be malloced");
	all->mlx->mlx_ptr = mlx_init();
	if (!(all->player = (t_player *)ft_calloc(1, sizeof(t_player))))
		ft_error("Structure Player cannot be malloced");
	if (!(all->image = (t_image **)malloc(sizeof(t_image *) * 6)))
		ft_error("Array of Structures Image cannot be malloced");
	i = 0;
	while (i < 6)
	{
		if (!(all->image[i] = (t_image *)ft_calloc(1, sizeof(t_image))))
			ft_error("Structure Image cannot be malloced");
		i++;
	}
	if (!(all->dda = (t_dda *)ft_calloc(1, sizeof(t_dda))))
		ft_error("Structure DDA cannot be malloced");
	if (!(all->spr = (t_spr *)ft_calloc(1, sizeof(t_spr))))
		ft_error("Structure Spr cannot be malloced");
}

/*
**File parsing and preparating parameters for rendering
*/

void		preprocessing_parameters(char *file_path, t_all *all)
{
	int		fd;

	if ((fd = open(file_path, O_RDONLY)) == -1)
		ft_error("Cannot open file");
	init_malloc_all_1(all);
	imbibe_file_parameters(fd, all);
	close(fd);
	set_images_to_path(all, 1, all->file->no);
	set_images_to_path(all, 2, all->file->so);
	set_images_to_path(all, 3, all->file->we);
	set_images_to_path(all, 4, all->file->ea);
	set_images_to_path(all, 5, all->file->s);
	set_player_parameters(all);
	set_sprite_parameters(all);
	all->image[0]->img = mlx_new_image(all->mlx->mlx_ptr, all->file->res_x,
			all->file->res_y);
	all->image[0]->addr = mlx_get_data_addr(all->image[0]->img,
			&all->image[0]->bits_per_pixel, &all->image[0]->line_length,
			&all->image[0]->endian);
}

int			main(int argc, char **argv)
{
	t_all	all;

	ft_bzero(&all, sizeof(t_all));
	if (argc == 2 && check_file_name(argv[1]) == 1)
	{
		preprocessing_parameters(argv[1], &all);
		run_engine(&all);
	}
	else if (argc == 3 && (check_file_name(argv[1]) == 1 ||
		check_file_name(argv[2]) == 1) && (ft_strncmp(argv[1], "--save", 7) == 0
		|| ft_strncmp(argv[2], "--save", 7) == 0))
	{
		if (check_file_name(argv[1]) == 1)
			create_bmp(argv[1], &all);
		if (check_file_name(argv[2]) == 1)
			create_bmp(argv[2], &all);
	}
	else
		ft_error("Incorrect program arguments");
	return (0);
}
