/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:34:42 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 14:57:57 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_all(t_data *mlx)
{
	mlx->endx = 2.0;
	mlx->startx = -2.0;
	mlx->endy = 2.0;
	mlx->starty = -2.0;
	mlx->iter = 100;
	mlx->color_ratio = 0;
	mlx->scale = 0.5;
	mlx->scale_key = 0.5;
	mlx->lock_evnt = 1;
}

int	creat_color(int color, int c_ratio, int iter)
{
	int	r;
	int	g;
	int	b;

	if (c_ratio >= iter)
		return (0);
	b = 5 * c_ratio * (cos(color) + 1);
	g = 4 * c_ratio * (1 + sin(color) + 1);
	r = c_ratio * (1 - cos(color));
	return (r << 16 | g << 8 | b);
}
