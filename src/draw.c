/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:20:55 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 12:20:16 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_data *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, SIZE, SIZE, "FRACTOL");
	mlx->img = mlx_new_image(mlx->ptr, SIZE, SIZE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_map(double y, double end, double start)
{
	return ((y / SIZE) * (end - (start)) + (start));
}

void	draw_fractal(t_data *mlx, int x, int y)
{
	double	c_rat;

	if (!mlx->typ)
		c_rat = mandelbrot((t_complex){ft_map(x, mlx->endx, mlx->startx),
				ft_map(y, mlx->endy, mlx->starty)}, mlx);
	else if (mlx->typ == 1)
		c_rat = julia((t_complex){ft_map(x, mlx->endx, mlx->startx),
				ft_map(y, mlx->endy, mlx->starty)}, mlx);
	else
		c_rat = tricorn((t_complex){ft_map(x, mlx->endx, mlx->startx),
				ft_map(y, mlx->endy, mlx->starty)}, mlx);
	my_mlx_pixel_put(mlx, x, y, creat_color(mlx->color_ratio,
			c_rat, mlx->iter));
}

void	draw_shape(t_data *mlx)
{
	int		x;
	int		y;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			draw_fractal(mlx, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
