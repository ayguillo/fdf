/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:50:08 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 14:31:02 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		hook_rotate(int key, t_all *all)
{
	if (key == 1)
		all->thetax += 0.087;
	if (key == 13)
		all->thetax -= 0.087;
	if (key == 12)
		all->thetaz -= 0.087;
	if (key == 14)
		all->thetaz += 0.087;
	if (key == 2)
		all->thetay += 0.087;
	if (key == 0)
		all->thetay -= 0.087;
}

static void		hookz(int key, t_all *all)
{
	if (key == 78)
	{
		if (all->depth < 150)
			all->addz -= 0.8;
		else if (all->depth >= 150 && all->depth < 1000)
			all->addz -= 0.05;
		else
			all->addz -= 0.015;
	}
	if (key == 69)
	{
		if (all->depth < 150)
			all->addz += 0.8;
		else if (all->depth >= 150 && all->depth < 1000)
			all->addz += 0.05;
		else
			all->addz += 0.015;
	}
}

static void		hookt(int key, t_all *all)
{
	if (key == 123)
		all->trax -= 10;
	if (key == 124)
		all->trax += 10;
	if (key == 126)
		all->tray -= 10;
	if (key == 125)
		all->tray += 10;
}

int				hook(int key, t_all *all)
{
	if (key == 53)
		ft_destroy(all, 0);
	if (key == 1 || key >= 13 || key == 12 || key == 14 || key == 0 || key == 2)
		hook_rotate(key, all);
	if (key == 78 || key == 69)
		hookz(key, all);
	if (key >= 123 && key <= 127)
		hookt(key, all);
	if (key == 46)
		all->choicecolor = 1;
	if (key == 17)
		all->choicecolor = 2;
	ft_grid(all);
	return (0);
}

int				ft_zoom(int button, int x, int y, t_all *all)
{
	x = 1;
	y = 1;
	if (button == 5)
		all->distance -= 1;
	if (button == 4)
		all->distance += 1;
	ft_grid(all);
	return (0);
}
