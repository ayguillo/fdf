/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:53:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/26 16:01:56 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"

t_mtx		**alloc_matrix(int **map, t_all *all)
{
	int		y;
	t_mtx	**mtx;

	if (!(mtx = (t_mtx**)malloc(sizeof(t_mtx*) * all->height)))
		return (NULL);
	y = -1;
	while (++y < all->height)
	{
		if (!(mtx[y] = (t_mtx*)malloc(sizeof(t_mtx) * all->width)))
			return (NULL);
	}
	return (mtx);
}

t_mtx		**fill_matrix(int **map, t_all *all)
{
	t_mtx	**mtx;
	int		x;
	int		y;
	int		rx;
	int		ry;

	if (!(mtx = alloc_matrix(map, all)))
		return (NULL);
	y = -1;
	ry = 0;
	while (++y < all->height)
	{
		x = -1;
		rx = 400;
		while (++x < all->width)
		{
			mtx[y][x].x = rx;
			mtx[y][x].y = ry;
			rx += all->distance;
		}
		ry += all->distance;
	}
	return (mtx);
}

void		iso(int *x, int *y, int z)
{
	int	prevx;
	int	prevy;

	prevx = *x;
	prevy = *y;
	*x = ((prevx - prevy) * cos(0.523599));
	*y = -z + ((prevx + prevy) * sin(0.523599));
}

t_mtx		**fill_real_matrix(int **map, t_all *all)
{
	t_mtx	**mtx;
	int		y;
	int		x;

	mtx = fill_matrix(map, all);
	y = -1;
	while (++y < all->height)
	{
		x = -1;
		while (++x < all->width)
			iso(&(mtx[y][x].x), &(mtx[y][x].y), map[y][x]);
	}
	return (mtx);
}

void		ft_printmtx(t_mtx **mtx, t_all *all)
{
	int	y;
	int	x;

	y = -1;
	while (++y < all->height)
	{
		x = -1;
		while (++x < all->width)
			ft_printf("%4i %4i\t", mtx[y][x].x, mtx[y][x].y);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

