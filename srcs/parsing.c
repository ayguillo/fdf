/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:10:28 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/02 18:31:25 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/fdf.h"

static int	**ft_allocmap(int **map, int height, int width)
{
	int	y;

	if (!(map = (int**)malloc(sizeof(int*) * height)))
		return (NULL);
	y = -1;
	while (++y < height)
	{
		if (!(map[y] = (int*)malloc(sizeof(int) * width)))
		{
			ft_freetab2i(&map, height);
			return (NULL);
		}
	}
	return (map);
}

static int	**ft_createmap(int height, int width, t_all *all, char **split)
{
	int	**cpy;
	int	x;
	int	y;
	int	**map;
	int	depth;

	map = all->map;
	if (!(cpy = ft_allocmap(cpy, height, width)))
		return (NULL);
	if (map != NULL && (y = -1))
		while (++y < height - 1 && (x = -1))
			while (++x < width)
				cpy[y][x] = map[y][x];
	x = -1;
	while (++x < width)
	{
		if (!(ft_getnbr(split[x])))
			return (NULL);
		cpy[height - 1][x] = ft_atoi(split[x]);
		if (cpy[height - 1][x] > all->depth)
			all->depth = cpy[height - 1][x];
	}
	ft_freetab2i(&map, height);
	return (cpy);
}

int			ft_parsing(int fd, t_all *all)
{
	int		ret;
	char	*line;
	char	**split;

	line = NULL;
	ret = 1;
	split = NULL;
	while (ret >= 0 && ((ret = ft_gnl(fd, &line)) || ret == 0))
	{
		if (ret == 0 && ((all->height)--))
		{
			ft_strdel(&line);
			return (1);
		}
		if (!(split = ft_strsplit(line, ' ')))
			return (0);
		!all->width ? all->width = ft_raws_nbr(split) : 0;
		if (ft_raws_nbr(split) != (all->width) || (!(all->map =
						ft_createmap(all->height, all->width, all, split))))
			return (0);
		ft_free_tab2d(&split);
		(all->height)++;
		ft_strdel(&line);
	}
	return (0);
}
