/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:19:57 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/03 14:07:35 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include "../libft/libft.h"

void		rotatex(float *y, float *z, t_all *all)
{
	float	prevy;
	float	prevz;

	prevz = *z;
	prevy = *y;
	*y = prevy * cos(all->thetax) + prevz * sin(all->thetax);
	*z = -prevy * sin(all->thetax) + prevz * cos(all->thetax);
}

void		rotatey(float *x, float *z, t_all *all)
{
	float	 prevx;
	float	prevz;

	prevx = *x;
	prevz = *z;
	*x = prevx * cos(all->thetay) + prevz * sin(all->thetay);
	*z = -prevx * sin(all->thetay) + prevz * cos(all->thetay);
}

void		rotatez(float *x, float *y, t_all *all)
{
	float	prevx;
	float	prevy;

	prevx = *x;
	prevy = *y;
	*x = prevx * cos(all->thetaz) - prevy * sin(all->thetaz);
	*y = prevx * sin(all->thetaz) + prevy * cos(all->thetaz);
}

void		iso(float *x, float *y, float z)
{
	float	prevx;
	float	prevy;

	prevx = *x;
	prevy = *y;
	*x = ((prevx - prevy) * cos(0.523599));
	*y = -z + ((prevx + prevy) * sin(0.523599));
}
