/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:10:21 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 11:44:33 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "../includes/fdf.h"
#include <mlx.h>

void		ft_freetab2i(int ***map, int height)
{
	int		i;

	if (!(*map))
		return ;
	i = -1;
	while (++i < height && map[0][i])
		free(map[0][i]);
	if (*map)
		free(*map);
	*map = NULL;
}

void		ft_freemtx(t_mtx ***mtx, int height)
{
	int	i;

	if (!(*mtx))
		return ;
	i = -1;
	while (++i < height)
		free(mtx[0][i]);
	if (*mtx)
		free(*mtx);
	*mtx = NULL;
}

void		ft_fill_pixel(t_all *all, int x, int y, char *buff)
{
	char	*castcolor;
	int		bp;
	int		size_line;

	bp = ((all->bpp) / 8);
	size_line = all->size_line;
	castcolor = (char *)&(all->color);
	buff[(x * bp) + (y * size_line)] = castcolor[0];
	buff[(x * bp) + (y * size_line) + 1] = castcolor[1];
	buff[(x * bp) + (y * size_line) + 2] = castcolor[2];
	buff[(x * bp) + (y * size_line) + 3] = castcolor[3];
}

int			ft_getnbr(char *str)
{
	int		i;
	int		countsign;

	i = -1;
	countsign = 0;
	while (str[++i])
	{
		if ((str[i] == 45 || str[i] == 43) && i != 0)
			return (0);
		else if ((str[i] == 45 || str[i] == 43) && i == 0)
			countsign++;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		if (i > 4)
			return (0);
	}
	if (countsign > 1)
		return (0);
	return (1);
}

void		ft_freeall(t_all *all)
{
	if (all->map)
		ft_freetab2i(&(all->map), all->height);
	if (all->mtx)
		ft_freemtx(&(all->mtx), all->height);
}
