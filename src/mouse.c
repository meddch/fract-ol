/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:34:46 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 15:19:17 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scroll_up(int x, int y, t_data *mlx)
{
	double	tr_x;
	double	tr_y;

	tr_x = ft_map(x, mlx->endx, mlx->startx);
	tr_y = ft_map(y, mlx->endy, mlx->starty);
	mlx->endx /= mlx->scale ;
	mlx->startx /= mlx->scale;
	mlx->endy /= mlx->scale ;
	mlx->starty /= mlx->scale ;
	mlx->endx -= tr_x;
	mlx->startx -= tr_x;
	mlx->endy -= tr_y;
	mlx->starty -= tr_y;
	mlx->iter -= 10;
	mlx->scale_key /= mlx->scale ;
	draw_shape(mlx);
}

static void	scroll_down(int x, int y, t_data *mlx)
{
	double	tr_x;
	double	tr_y;

	tr_x = ft_map(x, mlx->endx, mlx->startx);
	tr_y = ft_map(y, mlx->endy, mlx->starty);
	mlx->endx += tr_x;
	mlx->startx += tr_x;
	mlx->endy += tr_y;
	mlx->starty += tr_y;
	mlx->endx *= mlx->scale;
	mlx->startx *= mlx->scale;
	mlx->endy *= mlx->scale;
	mlx->starty *= mlx->scale;
	mlx->iter += 10;
	mlx->scale_key *= mlx->scale;
	draw_shape(mlx);
}

int	mouse_move(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == 4)
		scroll_up(x, y, mlx);
	else if (keycode == 5)
		scroll_down(x, y, mlx);
	return (0);
}

int	mouse_motion(int x, int y, t_data *mlx)
{
	if (mlx->typ == 1 && mlx->lock_evnt == 1 && x > 0
		&& x <= SIZE && y > 0 && y <= SIZE)
	{
		mlx->julia_x = ft_map(x, mlx->endx, mlx->startx);
		mlx->julia_y = ft_map(y, mlx->endy, mlx->starty);
		draw_shape (mlx);
	}
	return (0);
}
