/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/26 16:01:55 by ayguillo         ###   ########.fr       */
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

void		ft_last(t_all *all, t_mtx **mtx, int x, int y)
{
	ft_bresemham(mtx[y][0].x, mtx[y][0].y, mtx[y][x].x, mtx[y][x].y, all);
	ft_bresemham(mtx[0][x].x, mtx[0][x].y, mtx[y][x].x, mtx[y][x].y, all);
}


void		ft_grid(t_all *all)
{
	int		x;
	int		y;
	t_mtx	**mtx;

	if (all->max != 0)
		all->distance = SZI / all->max;
	all->img_ptr2 = mlx_new_image(all->mlx_ptr, SZI, SZI);
	all->buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all->size_line), &(all->endian));
	mtx = fill_real_matrix(all->map, all);
	y = -1;
	while (++y < (all->height - 1) && (x = -1))
	{
		while (++x < all->width - 1)
		{
			ft_bresemham(mtx[y][x].x, mtx[y][x].y, mtx[y + 1][x].x,
					mtx[y + 1][x].y, all);
			ft_bresemham(mtx[y][x].x, mtx[y][x].y, mtx[y][x + 1].x,
					mtx[y][x + 1].y, all);
		}
	}
	ft_last(all, mtx, x, y);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 200, 200);
}
