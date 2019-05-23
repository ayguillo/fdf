/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:00:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 14:30:01 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		colorm(int **map, int x, int y, t_all *all)
{
	if (map[y][x] < 0)
		all->color = 0x8B0000;
	else if (map[y][x] < 10)
		all->color = 0xFF4901;
	else
		all->color = 0xC60800;
}

void		ft_color(int **map, int x, int y, t_all *all)
{
	if (all->choicecolor == 1)
		colorm(map, x, y, all);
	else if (all->choicecolor == 2)
		colore(map, x, y, all);
}
