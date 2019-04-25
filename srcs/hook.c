/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:50:08 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/25 12:02:19 by ayguillo         ###   ########.fr       */
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
	return (0);
}

int			ft_zoom(int button, int x, int y, t_all *all)
{
	if (button == 5)
		all->max += 1;
	if (button == 4)
		all->max -= 1;
	if (all->max == 1)
		all->max = -1;
	if (all->max == -1)
		all->max = 1;
	ft_grid(all);
	return (0);
}
