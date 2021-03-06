/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlambert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:47 by vlambert          #+#    #+#             */
/*   Updated: 2019/04/15 10:25:56 by vlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (!(*s1))
			return (0);
		s1 += 1;
		s2 += 1;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
