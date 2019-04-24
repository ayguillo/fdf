/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/24 11:40:40 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdlib.h>

void	ft_bresemham(int xdeb, int ydeb, int xfin, int yfin, t_all *all)
{
	t_bre	bre;
	char	*buff;

	buff = all->buff2;
	bre.dx = abs(xfin - xdeb);
	bre.sx = xdeb < xfin ? 1 : -1;
	bre.dy = abs(yfin - ydeb);
	bre.sy = ydeb < yfin ? 1 : -1; 
	bre.err = (bre.dx > bre.dy ? bre.dx : -(bre.dy)) / 2;
	while (1)
	{
		ft_fill_pixel(all, xdeb, ydeb, 0xFFFFFF, buff);
		if (xdeb <= xfin)
		if (ydeb == yfin && xdeb == xfin)
			break;
		bre.e2 = bre.err;
		if (bre.e2 > -(bre.dx))
		{
			bre.err -= bre.dy;
			xdeb += bre.sx;
		}
		if (bre.e2 < bre.dy)
		{
			bre.err += bre.dx;
			ydeb += bre.sy;
		}
	}
}

void		ft_grid(t_all *all)
{
	int		x;
	int		y;
	int		rx;
	int		ry;

	y = -1;
	x = all->height < all->width ? all->width : all->height;
	all->distance = 800 / x;
	all->img_ptr2 = mlx_new_image(all->mlx_ptr, 800, 800);
	all->buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all->size_line), &(all->endian));
	ry = 0;
	while (++y < all->height && (x = -1))
	{
		rx = 0;
		while (++x < all->width)
		{
			ft_bresemham(rx, ry, rx, ry + all->distance, all);
			ft_bresemham(rx, ry, rx + all->distance, ry, all);
			rx = x * all->distance;
		}
		ry = y * all->distance;
	}
	ft_bresemham(rx, 0, rx, ry, all);
	ft_bresemham(0, ry, rx, ry, all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 200, 200);
}
