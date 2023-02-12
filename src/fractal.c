/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:44:47 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 12:13:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_complex c, t_data *mlx)
{
	double			temp;
	t_complex		z;
	int				i;

		z.x = c.x;
		z.y = c.y;
		i = 0;
	while (ft_power(z.x) + ft_power(z.y) <= 4 && i < mlx->iter)
	{
		temp = ft_opert(z.x, z.y, 1);
		z.y = ft_opert (z.x, z.y, 2) + c.y;
		z.x = temp + c.x;
		i++;
	}
	return (i);
}

double	julia(t_complex c, t_data *mlx)
{
	double			temp;
	t_complex		z;
	int				i;

		z.x = c.x;
		z.y = c.y;
		i = 0;
	while (ft_power(z.x) + ft_power(z.y) <= 4 && i < mlx->iter)
	{
		temp = ft_opert(z.x, z.y, 1);
		z.y = ft_opert (z.x, z.y, 2) + mlx->julia_y;
		z.x = temp + mlx->julia_x;
		i++;
	}
	return (i);
}

double	tricorn(t_complex c, t_data *mlx)
{
	double			temp;
	t_complex		z;
	int				i;

		z.x = c.x;
		z.y = c.y;
		i = 0;
	while (ft_power(z.x) + ft_power(z.y) < 4 && i < mlx->iter)
	{
		temp = ft_opert(z.x, z.y, 1);
		z.y = -1 * ft_opert (z.x, z.y, 2) + c.y;
		z.x = temp + c.x;
		i++;
	}
	return (i);
}
