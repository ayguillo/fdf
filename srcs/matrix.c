/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:53:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/17 16:58:45 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"

static int	alloc_matrix(int **map, t_all *all)
{
	int		y;

	if (!(all->mtx = (t_mtx**)malloc(sizeof(t_mtx*) * all->height)))
		return (0);
	y = -1;
	while (++y < all->height)
	{
		if (!(all->mtx[y] = (t_mtx*)malloc(sizeof(t_mtx) * all->width)))
			return (0);
	}
	return (1);
}

int			fill_matrix(int **map, t_all *all)
{
	int		x;
	int		y;
	float	rx;
	float	ry;

	if (!(all->mtx))
		if (!(alloc_matrix(map, all)))
			return (0);
	y = -1;
	ry = -((all->distance * all->height) / 2) + all->tray;
	while (++y < all->height)
	{
		x = -1;
		rx = -((all->distance * all->width) / 2) + all->trax;
		while (++x < all->width)
		{
			all->mtx[y][x].x = rx;
			all->mtx[y][x].y = ry;
			all->mtx[y][x].z = (float)map[y][x] * all->addz;
			rx += all->distance;
		}
		ry += all->distance;
	}
	return (1);
}

int			fill_real_matrix(int **map, t_all *all)
{
	int		y;
	int		x;

	if (!(fill_matrix(map, all)))
		return (0);
	y = -1;
	while (++y < all->height)
	{
		x = -1;
		while (++x < all->width)
		{
			rotatex(&(all->mtx[y][x].y), &(all->mtx[y][x].z), all);
			rotatey(&(all->mtx[y][x].x), &(all->mtx[y][x].z), all);
			rotatez(&(all->mtx[y][x].x), &(all->mtx[y][x].y), all);
		}
	}
	return (1);
}
