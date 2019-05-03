/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:21:41 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/03 17:12:15 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

void			init(t_all *all)
{
	all->addz = 1;
	all->mtx = NULL;
	all->mlx_ptr = NULL;
	all->win_ptr = NULL;
	all->img_ptr = NULL;
	all->img_ptr2 = NULL;
	all->img_ptr3 = NULL;
	all->buff = NULL;
	all->buff2 = NULL;
	all->buff3 = NULL;
	all->bpp = 0;
	all->size_line = 0;
	all->endian = 0;
	all->fd = 0;
	all->width = 0;
	all->height = 1;
	all->depth = 0;
	all->map = NULL;
	all->distance = 0;
	all->thetax = -0.523599;
	all->thetay = -0.523599;
	all->thetaz = 0.0;
	all->color = 0xFFFFFF;
	all->trax = 0;
	all->tray = 0;
}


int				main(int ac, char **av)
{
	t_all	all;

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
	ft_printf("width = %i, height = %i, depth = %i\n", all.width, all.height, all.depth);
	presentation(&all, av[1]);
	all.max = all.height < all.width ? all.width : all.height;
	all.distance = SZI / all.max;
	mlx_mouse_hook(all.win_ptr, ft_zoom, (void*)&all);
	mlx_key_hook(all.win_ptr, hook, (void *)&all);
	ft_grid(&all);
	mlx_loop(all.mlx_ptr);
}
