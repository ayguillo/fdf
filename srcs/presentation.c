/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presentation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:04:19 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 16:34:24 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"

static char		*ft_file(char *name)
{
	char	*chr;

	if (!(ft_strchr(name, '/')))
		chr = name;
	else
		chr = ft_strchr(name, '/') + 1;
	return (chr);
}

static void		presentationstring(t_all *all)
{
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 55, 0xFFFFFF
			, "Press esc to quit");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 85, 0x008080
			, "Scroll to zoom/dezoom");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 115, 0x800080
			, "Press arrows to move");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 200, 0x800080
			, "Color mod :");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 30, 220, 0x800080
			, "Earth : T");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 30, 240, 0x800080
			, "Mars : M");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1200, 85, 0x008080
			, "Q & E : Rotate Z");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1200, 115, 0x800080
			, "W & S : Rotate X");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1200, 145, 0x008080
			, "A & D : Rotate y");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 1200, 175, 0x800080
			, "+ & - : Change Z");
}

static void		encad(t_all *all)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 55)
	{
		x = -1;
		while (++x < 220)
			ft_fill_pixel(all, x, y, all->buff3);
	}
	y = 115;
	while (++y < 180)
	{
		x = -1;
		while (++x < 120)
			ft_fill_pixel(all, x, y, all->buff3);
	}
}

static void		presentationhud(t_all *all)
{
	int	y;
	int	x;

	all->img_ptr3 = mlx_new_image(all->mlx_ptr, 1358, 190);
	all->buff3 = mlx_get_data_addr(all->img_ptr3, &(all->bpp),
			&(all->size_line), &(all->endian));
	all->color = 0xBBBBBB;
	encad(all);
	y = -1;
	while (++y < 190)
	{
		x = 1190;
		while (++x < 1358)
			ft_fill_pixel(all, x, y, all->buff3);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr3, 6, 85);
}

void			presentation(t_all *all, char *nm)
{
	int		x;
	int		y;

	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, 1500, 1500, "fdf");
	all->img_ptr = mlx_new_image(all->mlx_ptr, 1500, 50);
	all->buff = mlx_get_data_addr(all->img_ptr, &(all->bpp), &(all->size_line),
			&(all->endian));
	y = -1;
	all->color = 0x008080;
	while (++y <= 49)
	{
		x = -1;
		while (++x <= 1499)
			ft_fill_pixel(all, x, y, all->buff);
	}
	presentationhud(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	presentationstring(all);
	mlx_string_put(all->mlx_ptr, all->win_ptr, 748, 18, 0xFFFFFF, ft_file(nm));
}
