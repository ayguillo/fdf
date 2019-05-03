/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:56:01 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/03 14:10:31 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SZI 1200

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


typedef struct s_all
{
	t_mtx	**mtx;
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
	float	thetax;
	float	thetay;
	float	thetaz;
	float	addz;
}
t_all;
int				ft_parsing(int fd, t_all *all);
void			ft_freetab2i(int ***map, int height);
void			ft_printmap(int **map, int height, int width);
int				ft_getnbr(char *str);
void			ft_fill_pixel(t_all *all, int x, int y, int color, char *buff);
void			ft_bresemham(int xdeb, int ydeb, int xfin, int yfin,
		t_all *all);
void			ft_grid(t_all *all);
int				ft_zoom(int button, int x, int y, t_all *all);
int				quit(int key, t_all *all);
t_mtx			**alloc_matrix(int **map, t_all *all);
t_mtx			**fill_matrix(int **map, t_all *all);
t_mtx			**fill_real_matrix(int **map, t_all *all);
void			ft_printmtx(t_mtx **mtx, t_all *all);
void			rotatex(float *y, float *z, t_all *all);
void			rotatey(float *x, float *z, t_all *all);
void			rotatez(float *x, float *y, t_all *all);
void			iso(float *x, float *y, float z);
