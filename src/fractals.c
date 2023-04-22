/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:00:40 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 16:56:20 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*	This function checks if the complex number is in the mandelbrot set
by iterating the equation z = z^2 + c, where z and c are complex numbers.
Z is initialised to 0, and c is the complex number for the pixel. 
We say that a complex number belongs to the set when the absolute value 
(module) of it's parts doesn't scape from the set limits (which is 4) after
pass for all the iterations*/
void	ft_mandelbrot_equation(t_fractal *f)
{
	t_complex	z_quad;

	f->iter = -1;
	f->z.real = 0;
	f->z.img = 0;
	z_quad.real = 0;
	z_quad.img = 0;
	while (++f->iter < f->max_iter && (z_quad.real + z_quad.img <= 4))
	{
		f->z.img = 2 * f->z.real * f->z.img + f->c.img;
		f->z.real = z_quad.real - z_quad.img + f->c.real;
		z_quad.real = f->z.real * f->z.real;
		z_quad.img = f->z.img * f->z.img;
	}
}

void	ft_fill_julia(t_fractal *f)
{
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		f->c.img = f->max.img - (f->y * f->ratio.y);
		while (++f->x < WIDTH)
		{
			f->c.real = f->min.real + (f->x * f->ratio.x);
			ft_julia_equation(f);
			mlx_put_pixel(f->img, f->x, f->y, ft_colors(f->iter, f));
		}
	}
}
/* For Julia set: z = z^2 + [constant], where z is initialised to 
the pixel's complex number (c.real and c.imag) and [constant] is
the value that enters from the command line (julia.x and julia.y) */

void	ft_julia_equation(t_fractal *f)
{
	double	ztemp;

	f->iter = -1;
	f->z.real = f->c.real;
	f->z.img = f->c.img;
	ztemp = 0;
	while (++f->iter < f->max_iter && ft_module(f->z.real, f->z.img) <= 4)
	{
		ztemp = f->z.real * f->z.real - f->z.img * f->z.img + f->julia.x;
		f->z.img = 2 * f->z.real * f->z.img + f->julia.y;
		f->z.real = ztemp;
	}
}

void	ft_fill_burningship(t_fractal *f)
{
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		f->c.img = f->max.img - (f->y * f->ratio.y);
		while (++f->x < WIDTH)
		{
			f->c.real = f->min.real + (f->x * f->ratio.x);
			ft_burningship_equation(f);
			mlx_put_pixel(f->img, f->x, f->y, ft_colors(f->iter, f));
		}
	}
}
/* The difference between the burning ship fractal and the mandelbrot fractal 
is that the burning ship fractal uses the absolute value of z */

void	ft_burningship_equation(t_fractal *f)
{
	t_complex	z_quad;

	f->iter = -1;
	f->z.real = 0;
	f->z.img = 0;
	z_quad.real = 0;
	z_quad.img = 0;
	while (++f->iter < f->max_iter && (z_quad.real + z_quad.img <= 4))
	{
		f->z.img = 2 * fabs(f->z.real * f->z.img) - f->c.img;
		f->z.real = z_quad.real - z_quad.img + f->c.real;
		z_quad.real = fabs(f->z.real * f->z.real);
		z_quad.img = fabs(f->z.img * f->z.img);
	}
}
