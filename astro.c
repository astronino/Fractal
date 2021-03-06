/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:58:55 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/29 01:59:03 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_iteration(int itr, float x, float y)
{
	int		i;
	t_cord	z;
	double	old_real_nbr;

	i = 0;
	z.x = 0;
	z.y = 0;
	while ((i < itr) && ((z.x * z.x + z.y * z.y) < 4))
	{
		old_real_nbr = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + x;
		z.y = 2 * fabs(old_real_nbr * z.y) + y;
		i++;
	}
	return (i);
}

void		draw_astro(t_fr *fr)
{
	int			i;
	int			j;
	int			res;
	t_cord		cord;

	j = 0;
	while (j < 500)
	{
		i = 0;
		cord.y = fr->min.y + (j * (fr->max.y - fr->min.y)) / 500;
		while (i < 500)
		{
			cord.x = fr->min.x + (i * (fr->max.x - fr->min.x)) / 500;
			res = check_iteration(fr->itr, cord.x, cord.y);
			if (res != fr->itr)
				fr->mlx_addr[(j * 500) + i] = res * fr->color;
			else
				fr->mlx_addr[(j * 500) + i] = 0x000000;
			i++;
		}
		j++;
	}
}

int			ft_astro(t_fr *fr)
{
	fr->max.x = 2;
	fr->min.x = -2;
	fr->max.y = 2;
	fr->min.y = -2;
	fr->itr = 250;
	draw_astro(fr);
	return (1);
}
