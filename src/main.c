/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:46:59 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 16:57:38 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	(void)ac;
	ft_check_args(&fractal, ac, av);
	fractal.mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", false);
	if (!fractal.mlx)
		exit(EXIT_FAILURE);
	ft_init_data(&fractal);
	fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
	if (!fractal.img)
		exit(EXIT_FAILURE);
	ft_select_fractal(&fractal);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_scroll_hook(fractal.mlx, &ft_scroll, &fractal);
	mlx_key_hook(fractal.mlx, &ft_key_hook, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
/*Initialises the fractal data structure with the correct values
depending on the fractal type.
Limits may change, and so will the ratio that is used to calculate
the complex number for each pixel.
*/

void	ft_init_data(t_fractal *f)
{
	f->max_iter = 100;
	f->max.real = 1.2;
	f->min.real = -2.2;
	f->max.img = 1.2;
	f->min.img = -1.2;
	f->color = 0;
	if (f->set == 1)
	{
		f->max.real = 1.7;
		f->min.real = -1.7;
		f->min.img = -1.2;
		f->max.img = 1.2;
	}
	else if (f->set == 2)
	{
		f->max.real = 2.0;
		f->min.real = -2.5;
		f->min.img = -1;
		f->max.img = f->min.img + (f->max.real - f->min.real) \
	* HEIGHT / WIDTH;
	}
	ft_calculate_ratio(f);
}

void	ft_select_fractal(t_fractal *f)
{
	if (f->set == 0)
		ft_fill_mandelbrot(f);
	else if (f->set == 1)
		ft_fill_julia(f);
	else if (f->set == 2)
		ft_fill_burningship(f);
}
/*	
This function is called for each pixel in the window. It calculates
the complex number for the pixel, and then calls the mandelbrot equation 
function to check if the complex number is in the fractal set. 
The complex number for the pixel (c) is calculated by making a 
proportional conversion from the pixel coordinates to the fractal 
coordinates. To do this, we need to know the ratio between the fractal's
limits and the window's limits. We can then multiply the pixel's distance
from the edge of the window by the ratio to get the pixel's distance from
the edge of the fractal. As the limits of the fractal doesn't start at 0 
like the window does, we need to add the minimum value of the fractal to
the pixel's distance from the edge to get the fractal's coordinate.
That is for the X axis. The same logic is applied to the Y axis, but take
note that the Y axis increases in the downward direction in the window,
while our fractal's Y axis increases in the upward direction.
That's why we subtract the pixel's distance from the edge from the
maximum value of the fractal instead of adding it.
*/

void	ft_fill_mandelbrot(t_fractal *f)
{
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		f->c.img = f->max.img - (f->y * f->ratio.y);
		while (++f->x < WIDTH)
		{
			f->c.real = f->min.real + (f->x * f->ratio.x);
			ft_mandelbrot_equation(f);
			mlx_put_pixel(f->img, f->x, f->y, ft_colors(f->iter, f));
		}
	}
}

/* void leak(void)
{
	system("leaks fractol");
} 
atexit(leak);
*/