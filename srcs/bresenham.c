/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:37:27 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/23 16:52:26 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"

void	ft_bresemham(int xdeb, int ydeb, int xfin, int yfin, t_all *all, char *buff)
{
	t_bre bre;

	bre.dx = abs(xfin - xdeb);
	bre.sx = xdeb < xfin ? 1 : -1;
	bre.dy = abs(yfin - ydeb);
	bre.sy = ydeb < yfin ? 1 : -1;
	bre.err = (bre.dx > bre.dy ? bre.dx : -(bre.dy)) / 2;
	bre.e2 = 0;

	while (1)
	{
		ft_fill_pixel(all, xdeb, ydeb, 0xFFFFFF, buff);
		if (xdeb == xfin && ydeb == yfin)
			break;
		bre.e2 = bre.err;
		if (bre.e2 > -(bre.dx))
		{
			bre.err -= bre.dy;
			xdeb += bre.sy;
		}
		if (bre.e2 < bre.dx)
		{
			bre.err += bre.dx;
			ydeb += bre.sy;
		}
	}
}

void		ft_grid(t_all *all)
{
	int		max;
	int		x;
	int		y;

	x = 0;
	y = 0;
	all->img_ptr2 = mlx_new_image(all->mlx_ptr, 700, 700);
	all.buff2 = mlx_get_data_addr(all->img_ptr2, &(all->bpp),
			&(all.size_line), &(all.endian));
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
			all->img_ptr2, 100, 100);
}
