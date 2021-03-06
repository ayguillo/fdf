/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:56:01 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/21 14:11:06 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define SZI 1200
# define MID SZI / 2

typedef struct	s_bre
{
	double	dx;
	double	dy;
	int		err;
	int		e2;
	int		sx;
	int		sy;
}				t_bre;

typedef struct	s_mtx
{
	float	x;
	float	y;
	float	z;
}				t_mtx;

typedef struct	s_points
{
	int xdeb;
	int ydeb;
	int	xfin;
	int	yfin;
}				t_points;

typedef struct	s_all
{
	t_mtx	**mtx;
	int		**map;
	char	*buff;
	char	*buff2;
	char	*buff3;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr2;
	void	*img_ptr3;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	int		fd;
	int		width;
	int		height;
	int		depth;
	int		trax;
	int		tray;
	int		choicecolor;
	int		max;
	float	distance;
	float	thetax;
	float	thetay;
	float	thetaz;
	float	addz;
	char	padding[sizeof(int)];
}				t_all;

void			presentation(t_all *all, char *nm);

int				ft_parsing(int fd, t_all *all);
void			ft_freeall(t_all *all);
void			ft_freetab2i(int ***map, int height);
int				ft_getnbr(char *str);
void			ft_bresemham(t_points point, t_all *all);
void			ft_grid(t_all *all);
int				ft_checknbr(int x, t_all *all, char **split, int **map);

int				fill_matrix(int **map, t_all *all);
int				fill_real_matrix(int **map, t_all *all);

void			rotatex(float *y, float *z, t_all *all);
void			rotatey(float *x, float *z, t_all *all);
void			rotatez(float *x, float *y, t_all *all);

void			ft_fill_pixel(t_all *all, int x, int y, char *buff);
void			colore(int **map, int x, int y, t_all *all);
void			colorm(int **map, int x, int y, t_all *all);
void			ft_color(int **map, int x, int y, t_all *all);

int				ft_zoom(int button, int x, int y, t_all *all);
int				hook(int key, t_all *all);

void			ft_destroy(t_all *all, int err);

void			ft_printmtx(t_mtx **mtx, t_all *all);
void			ft_printmap(int **map, int height, int width);

#endif
