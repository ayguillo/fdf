/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/25 15:13:27 by ayguillo         ###   ########.fr       */
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
		if (xdeb < 0 || ydeb < 0 || xdeb >= SZI || ydeb >= SZI)
			break;
		ft_fill_pixel(all, xdeb, ydeb, 0xFFFFFF, buff);
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

void		iso(int *x, int *y, int z)
{
	int	prevx;
	int	prevy;

	prevx = *x;
	prevy = *y;
	*x = (prevx - prevy) * cos(0.523599);
	*y = (prevx + prevy) * sin(0.523599) - z;
}

void		ft_grid(t_all *all)
{
	int		x;
	int		y;
	t_pos	pos;

	y = -1;
	if (all->max != 0)
		all->distance = SZI / all->max;
	all->img_ptr2 = mlx_new_image(all->mlx_ptr, SZI, SZI);
	all->buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all->size_line), &(all->endian));
	pos.ry = 0;
	pos.ryfin = all->distance;
	pos.rx = 0;
	while (++y < all->height && (x = -1))
	{
		pos.rx = 0;
		pos.rxfin = 0;
		while (++x < all->width)
		{
			pos.rxfin = pos.rx + all->distance;
			ft_bresemham(pos.rx, pos.ry, pos.rx, pos.ryfin, all);
			ft_bresemham(pos.rx, pos.ry, pos.rxfin, pos.ry, all);
			pos.rx = pos.rxfin;
			pos.rxfin += all->distance;
		}
		pos.ry = pos.ryfin;
		pos.ryfin += all->distance;
	}
	ft_bresemham(pos.rx, 0, pos.rx, pos.ry, all);
	ft_bresemham(0, pos.ry, pos.rx, pos.ry, all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 200, 200);
}
