/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 15:57:12 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdlib.h>

static void	ft_init(t_points point, t_bre *bre)
{
	bre->dx = abs(point.xfin - point.xdeb);
	bre->sx = point.xdeb < point.xfin ? 1 : -1;
	bre->dy = abs(point.yfin - point.ydeb);
	bre->sy = point.ydeb < point.yfin ? 1 : -1;
	bre->err = (bre->dx > bre->dy ? bre->dx : -(bre->dy)) / 2;
}

void		ft_bresenham(t_points point, t_all *all)
{
	t_bre	bre;
	char	*buff;

	buff = all->buff2;
	ft_init(point, &bre);
	while (1)
	{
		if ((point.ydeb < SZI && point.xdeb < SZI) && (point.ydeb >= 0
					&& point.xdeb >= 0))
			ft_fill_pixel(all, point.xdeb, point.ydeb, buff);
		if (point.ydeb == point.yfin && point.xdeb == point.xfin)
			break ;
		bre.e2 = bre.err;
		if (bre.e2 > -(bre.dx))
		{
			bre.err -= bre.dy;
			point.xdeb += bre.sx;
		}
		if (bre.e2 < bre.dy)
		{
			bre.err += bre.dx;
			point.ydeb += bre.sy;
		}
	}
}

void		ft_last(t_all *all, t_mtx **mtx, int x, int y)
{
	int			px;
	int			py;
	t_points	point;

	px = -1;
	while (++px < x)
	{
		ft_color(all->map, px, y, all);
		point.xdeb = (int)(mtx[y][px].x + MID);
		point.ydeb = (int)(mtx[y][px].y + MID);
		point.xfin = (int)(mtx[y][px + 1].x + MID);
		point.yfin = (int)(mtx[y][px + 1].y + MID);
		ft_bresenham(point, all);
	}
	py = -1;
	while (++py < y)
	{
		ft_color(all->map, x, py, all);
		point.xdeb = (int)(mtx[py][x].x + MID);
		point.ydeb = (int)(mtx[py][x].y + MID);
		point.xfin = (int)(mtx[py + 1][x].x + MID);
		point.yfin = (int)(mtx[py + 1][x].y + MID);
		ft_bresenham(point, all);
	}
}

static void	ft_realpoint(t_all *all, t_points *point, int x, int y)
{
	point->xdeb = (int)(all->mtx[y][x].x + MID);
	point->ydeb = (int)(all->mtx[y][x].y + MID);
	point->xfin = (int)(all->mtx[y + 1][x].x + MID);
	point->yfin = (int)(all->mtx[y + 1][x].y + MID);
}

void		ft_grid(t_all *all)
{
	int			x;
	int			y;
	t_points	point;

	all->img_ptr2 = mlx_new_image(all->mlx_ptr, SZI, SZI);
	all->buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all->size_line), &(all->endian));
	if (!(fill_real_matrix(all->map, all)))
		ft_destroy(all, 1);
	y = -1;
	while (++y < (all->height - 1) && (x = -1))
	{
		while (++x < all->width - 1)
		{
			ft_color(all->map, x, y, all);
			ft_realpoint(all, &point, x, y);
			ft_bresenham(point, all);
			point.xfin = (int)(all->mtx[y][x + 1].x + MID);
			point.yfin = (int)(all->mtx[y][x + 1].y + MID);
			ft_bresenham(point, all);
		}
	}
	ft_last(all, all->mtx, x, y);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 200, 200);
}
