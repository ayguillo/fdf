/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:05:25 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/17 12:08:20 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

void	ft_printmtx(t_mtx **mtx, t_all *all)
{
	int	y;
	int	x;

	y = -1;
	while (++y < all->height)
	{
		x = -1;
		while (++x < all->width)
			ft_printf("%4i %4i %4i\t", mtx[y][x].x, mtx[y][x].y, mtx[y][x].z);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	ft_printmap(int **map, int height, int width)
{
	int	y;
	int	x;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			ft_printf("%2i ", map[y][x]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
