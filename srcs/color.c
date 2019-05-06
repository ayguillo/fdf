/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:00:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/06 12:01:53 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		colore(int **map, int x, int y, t_all *all)
{
	if (all->map[y][x] <= -2)
		all->color = 0x03224C;
	else if (all->map[y][x] <= 0 && all->map[y][x] > -2)
		all->color = 0x0000FF;
	else if (all->map[y][x] > 0 && all->map[y][x] < 3)
		all->color = 0xE0CDA9;
	else if (all->map[y][x] >= 3 && all->map[y][x] < 60)
		all->color = 0x3A9D23;
	else if (all->map[y][x] >= 60 && all->map[y][x] < 400)
		all->color = 0x582900;
	else if (all->map[y][x] >= 400 && all->map[y][x] < 700)
		all->color = 0x582900;
	else if (all->map[y][x] >= 700 && all->map[y][x] < 1000)
		all->color = 0x808080;
	else
		all->color = 0xFFFFFF;
}

void		colorm(int **map, int x, int y, t_all *all)
{
	if (all->map[y][x] < 0)
		all->color = 0x0000FF;
	else if (all->map[y][x] >= 0 && all->map[y][x] < 10)
		all->color = 0xFF4901;
	else
		all->color = 0xC60800;
}
