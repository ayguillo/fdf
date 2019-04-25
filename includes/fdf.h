/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:56:01 by ayguillo          #+#    #+#             */
/*   Updated: 2019/04/25 12:01:47 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SZI 800

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
	float	distance;
	int		max;
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

typedef struct	s_pos
{
	int	rx;
	int	ry;
	int	rxfin;
	int	ryfin;
}				t_pos;

int				ft_parsing(int fd, t_all *all);
void			ft_freetab2i(int ***map, int height);
void			ft_printmap(int **map, int height, int width);
int				ft_getnbr(char *str);
void			ft_fill_pixel(t_all *all, int x, int y, int color, char *buff);
void			ft_bresemham(int xdeb, int ydeb, int xfin, int yfin, t_all *all);
void			ft_grid(t_all *all);
int				ft_zoom(int button, int x, int y, t_all *all);
int				quit(int key, t_all *all);
