/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:04:33 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 17:37:51 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_terminate(f->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
	{
		if (f->color == 4)
			f->color = 0;
		else
			f->color++;
		ft_select_fractal(f);
	}
	else if ((keydata.key == MLX_KEY_0 && keydata.action == MLX_RELEASE) || \
		(keydata.key == MLX_KEY_9 && keydata.action == MLX_RELEASE))
		ft_julia_values(keydata, f);
	else
		ft_arrows(keydata, f);
}

void	ft_julia_values(mlx_key_data_t keydata, t_fractal *f)
{
	if (keydata.key == MLX_KEY_0 && keydata.action == MLX_RELEASE)
	{
		f->julia.x += 0.001;
		f->julia.y += 0.001;
	}
	else if (keydata.key == MLX_KEY_9 && keydata.action == MLX_RELEASE)
	{
		f->julia.x -= 0.001;
		f->julia.y -= 0.001;
	}
	ft_select_fractal(f);
}

void	ft_arrows(mlx_key_data_t keydata, t_fractal *f)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		ft_move(f, 0.2, 'U');
		ft_calculate_ratio(f);
		ft_select_fractal(f);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		ft_move(f, 0.2, 'D');
		ft_calculate_ratio(f);
		ft_select_fractal(f);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		ft_move(f, 0.2, 'L');
		ft_calculate_ratio(f);
		ft_select_fractal(f);
	}
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		ft_move(f, 0.2, 'R');
		ft_calculate_ratio(f);
		ft_select_fractal(f);
	}
}

/*
Moves the view of the fractal by adjusting the complex
number edge values a certain distance in a certain direction.
*/

void	ft_move(t_fractal *f, double distance, char key)
{
	double	centre_x;
	double	centre_y;

	centre_x = (f->min.real - f->max.real);
	centre_y = (f->max.img - f->min.img);
	if (key == 'U')
	{
		f->max.img += distance * centre_y;
		f->min.img += distance * centre_y;
	}
	else if (key == 'D')
	{
		f->max.img -= distance * centre_y;
		f->min.img -= distance * centre_y;
	}
	else if (key == 'R')
	{
		f->max.real -= distance * centre_x;
		f->min.real -= distance * centre_x;
	}
	else if (key == 'L')
	{
		f->max.real += distance * centre_x;
		f->min.real += distance * centre_x;
	}
}

/*Zooms the view of the fractal in or out by adjusting
the complex number edge values by a zoom multiplier.
The fractal can then be generated again at a different resolution,
giving the appearance of zooming in or out.
If the zoom multiplier is small, like 0.5, the view will
zoom in, if it is big, like 1.5, it will zoom out.
*/

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	double		zoom;
	double		centre_x;
	double		centre_y;

	(void)xdelta;
	zoom = 0;
	f = (t_fractal *)param;
	centre_x = (f->min.real - f->max.real);
	centre_y = (f->max.img - f->min.img);
	if (ydelta > 0)
		zoom = 0.5;
	else if (ydelta < 0)
		zoom = 1.5;
	f->max.real = f->max.real + (centre_x - zoom * centre_x) / 2;
	f->min.real = f->max.real + zoom * centre_x;
	f->min.img = f->min.img + (centre_y - zoom * centre_y) / 2;
	f->max.img = f->min.img + zoom * centre_y;
	ft_calculate_ratio(f);
	ft_select_fractal(f);
}
