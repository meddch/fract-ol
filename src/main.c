/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:29:19 by mechane           #+#    #+#             */
/*   Updated: 2023/02/12 14:33:11 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(void)
{
	ft_putstr_fd(ERROR_CODE, 2);
	ft_putstr_fd(MSG, 2);
	ft_putstr_fd(HINT, 2);
	return (exit(0), 0);
}

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac == 1)
		ft_error();
	if (ac == 2 && !ft_strncmp("mandelbrot", av[1], ft_strlen(av[1])))
		mlx.typ = 0;
	else if (ac == 2 && !ft_strncmp("julia", av[1], ft_strlen(av[1])))
		mlx.typ = 1;
	else if (ac == 2 && !ft_strncmp("tricorn", av[1], ft_strlen(av[1])))
		mlx.typ = 2;
	else
		ft_error();
	ft_init(&mlx);
	ft_init_all(&mlx);
	draw_shape(&mlx);
	mlx_mouse_hook(mlx.win, mouse_move, &mlx);
	mlx_hook(mlx.win, 2, 0, manage_key, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_motion, &mlx);
	mlx_hook(mlx.win, 17, 0, destroy, &mlx);
	mlx_loop(mlx.ptr);
}
