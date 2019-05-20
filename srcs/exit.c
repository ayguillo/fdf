/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:30:12 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/20 15:39:15 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <mlx.h>
#include <stdlib.h>

void	ft_destroy(t_all *all, int err)
{
	if (err == 1)
		ft_printf("Error\n");
	mlx_destroy_image(all->mlx_ptr, all->img_ptr);
	mlx_destroy_image(all->mlx_ptr, all->img_ptr2);
	mlx_destroy_image(all->mlx_ptr, all->img_ptr3);
	mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	ft_freeall(all);
	exit(-1);
}
