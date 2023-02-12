/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechane <mechane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:37:57 by mechane           #+#    #+#             */
/*   Updated: 2023/02/07 13:02:08 by mechane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 500
# define ERROR_CODE "\033[0;31mPlease choose a fractal : \n"
# define MSG "\033[0;33mFRACTALS : mandelbrot / julia / tricorn.\n"
# define HINT "\033[0;32mHINT : ./fractol (fractal_name) \n"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h> 

typedef struct s_complex
{
	double	x;
	double	y;
}t_complex;

typedef struct s_data {
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color_ratio;
	double	startx;
	double	endx;
	double	starty;
	double	endy;
	double	julia_x;
	double	julia_y;
	double	iter;
	double	scale;
	double	scale_key;
	int		typ;
	int		lock_evnt;
}t_data;

int		creat_color(int color, int c_ratio, int iter);
int		mouse_move(int keycode, int x, int y, t_data *mlx);
int		manage_key(int keycode, t_data *mlx);
void	ft_init(t_data *mlx);
void	draw_shape(t_data *mlx);
double	ft_power(double x);
double	ft_opert(double x, double y, int indx);
double	mandelbrot(t_complex c, t_data *mlx);
double	ft_map(double y, double end, double start);
double	julia(t_complex c, t_data *mlx);
int		ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s11, const char *s22, size_t n);
void	ft_init_all(t_data *mlx);
int		ft_atoi(const char *str);
int		mouse_motion(int x, int y, t_data *mlx);
double	tricorn(t_complex c, t_data *mlx);
size_t	ft_strlen(const char *s);
int		destroy(t_data *mlx);

#endif