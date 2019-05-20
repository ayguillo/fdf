/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:21:41 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 16:34:20 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

void			init(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	all->thetax = -0.523599;
	all->height = 1;
	all->choicecolor = 2;
	all->thetay = -0.523599;
	all->color = 0xFFFFFF;
}

static int		ft_error(int ac, char **av, t_all *all)
{
	if (ac != 2)
	{
		ft_printf("Invalid argument number\n");
		return (-1);
	}
	if ((all->fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_printf("open() failed\n");
		return (-1);
	}
	if (!(ft_parsing(all->fd, all)))
	{
		ft_freeall(all);
		ft_printf("Error\n");
		return (-1);
	}
	if (all->width <= 1 || all->height <= 1)
	{
		ft_freeall(all);
		ft_printf("Error, file with less than two lines\n");
		return (-1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_all	all;

	init(&all);
	if (ft_error(ac, av, &all) < 0)
		return (-1);
	if (all.depth > 500)
		all.addz = 0.1;
	else if (all.depth > 100)
		all.addz = 0.5;
	else if (all.depth > 50)
		all.addz = 1;
	else
		all.addz = 10;
	presentation(&all, av[1]);
	all.max = all.height < all.width ? all.width : all.height;
	all.distance = (!(all.max)) ? SZI : SZI / all.max;
	all.distance = !all.distance ? 1 : all.distance;
	mlx_mouse_hook(all.win_ptr, ft_zoom, (void*)&all);
	mlx_key_hook(all.win_ptr, hook, (void *)&all);
	ft_grid(&all);
	mlx_loop(all.mlx_ptr);
	return (0);
}
