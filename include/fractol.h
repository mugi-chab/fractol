/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 12:15:35 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 17:28:19 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/***************************** STANDARD LIBRARIES ***************************/
#include "../Libs/MLX42/include/MLX42/MLX42.h"
#include "../Libs/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

/******************************* DEFINITIONS ********************************/
#define WIDTH 1200
#define HEIGHT 800

typedef struct s_complex
{	
	double	real;
	double	img;
}	t_complex;

typedef struct c_comp
{
	double	x;
	double	y;
}	p_comp;

typedef struct s_fractal
{
	int			x;
	int			y;
	int			set;
	int			max_iter;
	int			iter;
	int			color;
	p_comp		ratio;
	p_comp		julia;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	z;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_fractal;

/******************************* FUNCTIONS **********************************/
void	ft_print_usage(void);
int		ft_check_float(char *av);
double 	ft_atof(char *av);
void	ft_check_args(t_fractal *f, int ac, char **av);
void	ft_init_data(t_fractal *f);
void	ft_select_fractal(t_fractal *f);
void	ft_mandelbrot_equation(t_fractal *f);
double	ft_module(double a, double b);
void	ft_julia_equation(t_fractal *f);
void	ft_burningship_equation(t_fractal *f);
void	ft_scroll(double xdelta, double ydelta, void *param);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_fill_mandelbrot(t_fractal *f);
void	ft_fill_julia(t_fractal *f);
void	ft_fill_burningship(t_fractal *f);
void	ft_calculate_ratio(t_fractal *f);
void	ft_move(t_fractal *f, double distance, char key);
void	ft_arrows(mlx_key_data_t keydata, t_fractal *f);
int		ft_colors(int iter, t_fractal *f);
void	ft_julia_values(mlx_key_data_t keydata, t_fractal *f);

#endif