/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:10:28 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 11:35:47 by ayguillo         ###   ########.fr       */
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
	int	x;
	int	y;
	int	**map;

	map = NULL;
	if (!(map = ft_allocmap(map, height, width)))
		return (NULL);
	if (map != NULL && (y = -1))
		while (++y < height - 1 && (x = -1))
			while (++x < width)
				map[y][x] = all->map[y][x];
	x = -1;
	if (all->map)
		ft_freetab2i(&(all->map), height - 1);
	while (++x < width)
	{
		if (!(ft_checknbr(x, all, split, map)))
		{
			ft_freetab2i(&map, all->height);
			return (NULL);
		}
	}
	return (map);
}

static void	ft_free(char *line, char **split)
{
	if (line)
		ft_strdel(&line);
	if (split)
		ft_free_tab2d(&split);
}

static int	ft_raws(char ***split, t_all *all, char **line)
{
	if (!(*split = ft_strsplit(*line, ' ')))
	{
		ft_strdel(line);
		return (0);
	}
	if (all->width == 0)
		all->width = ft_raws_nbr(*split);
	if (ft_raws_nbr(*split) != (all->width)
			|| (!(all->map = ft_createmap(all->height, all->width
						, all, *split))))
	{
		all->height--;
		ft_free(*line, *split);
		return (0);
	}
	return (1);
}

int			ft_parsing(int fd, t_all *all)
{
	int		ret;
	char	*line;
	char	**split;

	if (all->map)
		return (0);
	line = NULL;
	split = NULL;
	ret = 0;
	while (ret >= 0 && ((ret = ft_gnl(fd, &line)) || ret == 0))
	{
		if (ret == 0 && ((all->height)--))
		{
			ft_strdel(&line);
			return (1);
		}
		if (!(ft_raws(&split, all, &line)))
			return (0);
		ft_free(line, split);
		(all->height)++;
	}
	ft_free(line, split);
	return (0);
}
