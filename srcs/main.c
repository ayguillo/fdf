/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:21:41 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/26 15:12:04 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <fcntl.h>

void			init(t_all *all)
{
	all->mlx_ptr = NULL;
	all->win_ptr = NULL;
	all->img_ptr = NULL;
	all->img_ptr2 = NULL;
	all->buff = NULL;
	all->buff2 = NULL;
	all->bpp = 0;
	all->size_line = 0;
	all->endian = 0;
	all->fd = 0;
	all->width = 0;
	all->height = 1;
	all->depth = 0;
	all->map = NULL;
	all->distance = 0;
}

static char		*ft_file(char *name)
{
	char	*chr;

	if (!(ft_strchr(name, '/')))
		chr = name;
	else
		chr = ft_strchr(name, '/') + 1;
	return (chr);
}

static void		presentation(t_all *all, char *nm)
{
	int		x;
	int		y;

	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, 1500, 1500, "fdf");
	ft_printmap(all->map, all->height, all->width);
	ft_printf("height = %i & width = %i && depth = %i\n", all->height
			, all->width, all->depth);
	all->img_ptr = mlx_new_image(all->mlx_ptr, 1500, 50);
	all->buff = mlx_get_data_addr(all->img_ptr, &(all->bpp), &(all->size_line),
			&(all->endian));
	y = -1;
	while (++y <= 49)
	{
		x = -1;
		while (++x <= 1499)
			ft_fill_pixel(all, x, y, 0x008080, all->buff);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, 0, 55, 0xFFFFFF
			, "Press esc to quit");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 748, 18, 0xFFFFFF, ft_file(nm));
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
	presentation(&all, av[1]);
	all.max = all.height < all.width ? all.width : all.height;
	mlx_mouse_hook(all.win_ptr, ft_zoom, (void*)&all);
	mlx_key_hook(all.win_ptr, quit, (void *)&all);
	ft_grid(&all);
	mlx_loop(all.mlx_ptr);
}
