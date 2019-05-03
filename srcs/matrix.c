/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 09:53:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/03 14:20:45 by ayguillo         ###   ########.fr       */
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
	float	rx;
	float	ry;

	if (!(mtx = alloc_matrix(map, all)))
		return (NULL);
	y = -1;
	ry = -((all->distance * all->height) / 2);
	while (++y < all->height)
	{
		x = -1;
		rx = -((all->distance * all->width) / 2);
		while (++x < all->width)
		{
			mtx[y][x].x = rx;
			mtx[y][x].y = ry;
			mtx[y][x].z = (float)map[y][x] * (all->addz/* * all->depth*/);
			rx += all->distance;
		}
		ry += all->distance;
	}
	return (mtx);
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
		{
			rotatex(&(mtx[y][x].y), &(mtx[y][x].z), all);
			rotatey(&(mtx[y][x].x), &(mtx[y][x].z), all);
			rotatez(&(mtx[y][x].x), &(mtx[y][x].y), all);
		}
	}
	return (mtx);
}
