/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:11:43 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 09:55:41 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

int		ft_checknbr(int x, t_all *all, char **split, int **map)
{
	if (!(ft_getnbr(split[x])))
		return (0);
	map[(all->height) - 1][x] = ft_atoi(split[x]);
	if (map[(all->height) - 1][x] > 25000
			|| map[(all->height) - 1][x] < -25000)
		return (0);
	if (map[(all->height) - 1][x] > all->depth)
		all->depth = map[(all->height) - 1][x];
	return (1);
}
