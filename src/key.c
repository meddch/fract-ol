/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:39:57 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 12:56:09 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_y(int keycode, t_data *mlx)
{
	if (keycode == 125)
	{	
		mlx->endy -= mlx->scale_key;
		mlx->starty -= mlx->scale_key;
		draw_shape(mlx);
	}
	else if (keycode == 126)
	{
		mlx->endy += mlx->scale_key;
		mlx->starty += mlx->scale_key;
		draw_shape(mlx);
	}
}

static void	key_x(int keycode, t_data *mlx)
{
	if (keycode == 123)
	{
		mlx->endx += mlx->scale_key;
		mlx->startx += mlx->scale_key;
		draw_shape(mlx);
	}
	else if (keycode == 124)
	{
		mlx->endx -= mlx->scale_key;
		mlx->startx -= mlx->scale_key;
		draw_shape(mlx);
	}
}

int	manage_key(int keycode, t_data *mlx)
{
	if (keycode == 53)
		destroy(mlx);
	else if (keycode == 125 || keycode == 126)
		key_y(keycode, mlx);
	else if (keycode == 123 || keycode == 124)
		key_x(keycode, mlx);
	else if (keycode == 49)
		mlx->lock_evnt *= -1 ;
	else if (keycode == 4)
	{
		mlx->color_ratio += 10;
		draw_shape(mlx);
	}
	return (0);
}

int	destroy(t_data *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
}
