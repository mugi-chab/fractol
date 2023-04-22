/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:17:32 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 18:33:35 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_print_usage(void);
int		ft_check_float(char *av);
double	ft_atof(char *av);

void	ft_check_args(t_fractal *f, int ac, char **av)
{
	if (ac == 2)
	{
		if ((av[1][0] == 'm' || av[1][0] == 'M') && !av[1][1])
			f->set = 0;
		else if ((av[1][0] == 'b' || av[1][0] == 'B') && !av[1][1])
			f->set = 2;
		else
			ft_print_usage();
	}
	else if (ac == 4)
	{
		if ((av[1][0] == 'j' || av[1][0] == 'J') && av[2][0] && av[3][0])
		{
			if (ft_check_float(av[2]) == 1 || ft_check_float(av[3]) == 1)
				ft_print_usage();
			else
			{
				f->julia.x = ft_atof(av[2]);
				f->julia.y = ft_atof(av[3]);
				f->set = 1;
			}
		}
	}
	else
		ft_print_usage();
}

void	ft_print_usage(void)
{
	ft_printf(GREEN_C"\n\t✗ "RESET_C"Fract-ol usage:");
	ft_printf("\n\n\tKey:\t\tFractal:""\n");
	ft_printf("\n""\t M\t\tMandelbrot\n\t J\t\tJulia\n\t B\t\tBurningship");
	ft_printf("\n\n\tFor Julia enter the [x coordinate] and [y coordinate]");
	ft_printf("\n\tFor change colors press spacebar");
	ft_printf("\n\tFor change julia's values press 9 or 0\n");
	ft_printf(GREEN_C"\n\t✗ "RESET_C"Example:\n");
	ft_printf(GREEN_C"\n\t➜ "RESET_C"./fractol j -0.437 -0.59");
	ft_printf(GREEN_C"\n\t➜ "RESET_C"./fractol j -0.12 -0.77");
	ft_printf(GREEN_C"\n\t➜ "RESET_C"./fractol j -0.79 0.15\n\n");
	exit(EXIT_FAILURE);
}

double	ft_atof(char *av)
{
	double	sign;
	double	result;
	int		decimal;

	sign = 1;
	result = 0;
	decimal = 0;
	if (*av == '-' || *av == '+')
		if (*av == '-')
			sign = -1;
		av++;
	while (*av)
	{
		if (*av == '.')
			decimal = 1;
		if (*av >= '0' && *av <= '9')
		{
			if (decimal == 1)
				sign /= 10;
			result = (result * 10) + (*av - '0');
		}
		av++;
	}
	return (result * sign);
}
