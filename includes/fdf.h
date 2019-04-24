/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:56:01 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/24 11:00:37 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_all
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr2;
	char	*buff;
	char	*buff2;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	int		fd;
	int		width;
	int		height;
	int		depth;
	int		**map;
	int		distance;
}				t_all;

typedef struct	s_bre
{
	double	dx;
	double	dy;
	int		err;
	int		e2;
	int		sx;
	int		sy;
}				t_bre;

int				ft_parsing(int fd, t_all *all);
void			ft_freetab2i(int ***map, int height);
void			ft_printmap(int **map, int height, int width);
int				ft_getnbr(char *str);
void			ft_fill_pixel(t_all *all, int x, int y, int color, char *buff);
void			ft_bresemham(int xdeb, int ydeb, int xfin, int yfin, t_all *all);
void			ft_grid(t_all *all);
