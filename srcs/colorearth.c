/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorearth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:42:17 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 15:09:59 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	colorexl(int **map, int x, int y, t_all *all)
{
	if (all->map[y][x] <= -30)
		all->color = 0x03224C;
	else if (all->map[y][x] <= 0)
		all->color = 0x0000FF;
	else if (all->map[y][x] < 6)
		all->color = 0xE0CDA9;
	else if (all->map[y][x] < 260)
		all->color = 0x3A9D23;
	else if (all->map[y][x] < 600)
		all->color = 0x582900;
	else if (all->map[y][x] < 1400)
		all->color = 0x808080;
	else
		all->color = 0xFFFFFF;
}

static void	colorel(int **map, int x, int y, t_all *all)
{
	if (all->map[y][x] <= -15)
		all->color = 0x03224C;
	else if (all->map[y][x] <= 0)
		all->color = 0x0000FF;
	else if (all->map[y][x] < 3)
		all->color = 0xE0CDA9;
	else if (all->map[y][x] < 130)
		all->color = 0x3A9D23;
	else if (all->map[y][x] < 300)
		all->color = 0x582900;
	else if (all->map[y][x] < 680)
		all->color = 0x808080;
	else
		all->color = 0xFFFFFF;
}

void		colore(int **map, int x, int y, t_all *all)
{
	if (all->depth > 2500)
		colorexl(map, x, y, all);
	else if (all->depth > 1100)
		colorel(map, x, y, all);
	else
	{
		if (all->map[y][x] <= -7)
			all->color = 0x03224C;
		else if (all->map[y][x] <= 0)
			all->color = 0x0000FF;
		else if (all->map[y][x] < 2)
			all->color = 0xE0CDA9;
		else if (all->map[y][x] < 70)
			all->color = 0x3A9D23;
		else if (all->map[y][x] < 150)
			all->color = 0x582900;
		else if (all->map[y][x] < 350)
			all->color = 0x808080;
		else
			all->color = 0xFFFFFF;
	}
}
