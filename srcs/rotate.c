/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:19:57 by ayguillo          #+#    #+#             */
/*   Updated: 2019/05/02 16:24:07 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include "../libft/libft.h"

void		rotatex(int *y, int *z, t_all *all)
{
	int	prevy;
	int	prevz;

	prevz = *z;
	prevy = *y;
	*y = prevy * cos(all->thetax) + prevz * sin(all->thetax);
	*z = -prevy * sin(all->thetax) + prevz * cos(all->thetax);
}

void		rotatey(int *x, int *z, t_all *all)
{
	int prevx;
	int	prevz;

	prevx = *x;
	prevz = *z;
	*x = prevx * cos(all->thetay) + prevz * sin(all->thetay);
	*z = -prevx * sin(all->thetay) + prevz * cos(all->thetay);
}

void		rotatez(int *x, int *y, t_all *all)
{
	int prevx;
	int	prevy;

	prevx = *x;
	prevy = *y;
	*x = prevx * cos(all->thetaz) - prevy * sin(all->thetaz);
	*y = prevx * sin(all->thetaz) + prevy * cos(all->thetaz);
}
