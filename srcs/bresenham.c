/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/06 12:17:28 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdlib.h>

void		ft_bresenham(int xdeb, int ydeb, int xfin, int yfin, t_all *all)
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
		if ((ydeb < SZI && xdeb < SZI) && (ydeb >= 0 && xdeb >= 0))
			ft_fill_pixel(all, (int)xdeb, (int)ydeb, buff);
		if (ydeb == yfin && xdeb == xfin)
			break ;
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

void		ft_last(t_all *all, t_mtx **mtx, int x, int y)
{
	int px;
	int py;
	int	plus;

	px = -1;
	while (++px < x)
	{
		colore(all->map, px, y, all);
		ft_bresenham((int)(mtx[y][px].x + MID),
				(int)(mtx[y][px].y + MID),
				(int)(mtx[y][px + 1].x + MID),
				(int)(mtx[y][px + 1].y + MID), all);
	}
	py = -1;
	while (++py < y)
	{
		colore(all->map, x, py, all);
		ft_bresenham((int)(mtx[py][x].x + MID),
				(int)(mtx[py][x].y + MID),
				(int)(mtx[py + 1][x].x + MID),
				(int)(mtx[py + 1][x].y + MID), all);
	}
}

void		ft_grid(t_all *all)
{
	int			x;
	int			y;
	t_mtx		**mtx;

	all->img_ptr2 = mlx_new_image(all->mlx_ptr, SZI, SZI);
	all->buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all->size_line), &(all->endian));
	all->mtx = fill_real_matrix(all->map, all);
	mtx = all->mtx;
	y = -1;
	while (++y < (all->height - 1) && (x = -1))
		while (++x < all->width - 1)
		{
			colore(all->map, x, y, all);
			ft_bresenham((int)(mtx[y][x].x + MID),
					(int)(mtx[y][x].y + MID),
					(int)(mtx[y + 1][x].x + MID),
					(int)(mtx[y + 1][x].y + MID), all);
			ft_bresenham((int)(mtx[y][x].x + MID),
					(int)(mtx[y][x].y + MID),
					(int)(mtx[y][x + 1].x + MID),
					(int)(mtx[y][x + 1].y + MID), all);
			all->color = 0xFFFFFF;
		}
	ft_last(all, mtx, x, y);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 200, 200);
}
