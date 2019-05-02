/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:50:08 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/02 17:41:53 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"
#include <stdlib.h>
#include "../libft/libft.h"

int				quit(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		exit(-1);
	}
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
	ft_grid(all);
	return (0);
}

int			ft_zoom(int button, int x, int y, t_all *all)
{
	if (button == 5)
		all->distance -= 1;
	if (button == 4)
		all->distance += 1;
	ft_grid(all);
	return (0);
}
