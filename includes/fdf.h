/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:56:01 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/19 14:26:31 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_all
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*buff;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	int		fd;
	int		width;
	int		height;
	int		depth;
	int		**map;
}				t_all;

int				ft_parsing(int fd, t_all *all);
void			ft_freetab2i(int ***map, int height);
void			ft_printmap(int **map, int height, int width);
int				ft_getnbr(char *str);
