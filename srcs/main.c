/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:21:41 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/19 15:39:35 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

void	ft_fill_pixel(char *buff, int x, int y, int color, int bpp,
		int size_line)
{
	char	*castcolor;
	int		bp;

	bp = bpp / 8;
	castcolor = (char *)&color;
	buff[(x*bp) + (y*size_line)] = castcolor[0];
	buff[(x*bp) + (y*size_line) + 1] = castcolor[1];
	buff[(x*bp) + (y*size_line) + 2] = castcolor[2];
	buff[(x*bp) + (y*size_line) + 3] = castcolor[3];
}

int		quit(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(-1);
	}
	return (0);
}

void	init(t_all *all)
{
	all->mlx_ptr = NULL;
	all->win_ptr = NULL;
	all->img_ptr = NULL;
	all->buff = NULL;
	all->bpp = 0;
	all->size_line = 0;
	all->endian = 0;
	all->fd = 0;
	all->width = 0;
	all->height = 1;
	all->depth = 0;
	all->map = NULL;
}

int		main(int ac, char **av)
{
	t_all	all;
	int		x;
	int		y;

	init(&all);
	if (ac != 2)
	{
		ft_printf("Invalid argument number\n");
		return (-1);
	}
	if ((all.fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("open() failed\n");
		return (-1);
	}
	if (!(ft_parsing(all.fd, &all)))
	{
		ft_printf("Error\n");
		return (-1);
	}
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, 1000, 1000, "fdf");
	ft_printmap(all.map, all.height, all.width);
	ft_printf("height = %i & width = %i && depth = %i\n", all.height, all.width, all.depth);
	all.img_ptr = mlx_new_image(all.mlx_ptr, 500, 500);
	all.buff = mlx_get_data_addr(all.img_ptr, &(all.bpp), &(all.size_line),
			&(all.endian));
	y = -1;
	while (++y <= 49)
	{
		x = -1;
		while (++x <= 49)
			ft_fill_pixel(all.buff, x, y, 0xFFFFFF, all.bpp, all.size_line);
	}
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 250, 250);
	mlx_string_put(all.mlx_ptr, all.win_ptr, 0, 0, 0xFFFFFF, "Press esc to quit");
	mlx_key_hook(all.win_ptr, quit, (void *)&all);
	mlx_loop(all.mlx_ptr);
}
