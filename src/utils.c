/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:06:25 by svillalv          #+#    #+#             */
/*   Updated: 2023/04/22 16:58:43 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_calculate_ratio(t_fractal *f)
{
	f->ratio.x = (f->max.real - f->min.real) / WIDTH;
	f->ratio.y = (f->max.img - f->min.img) / HEIGHT;
}

double	ft_module(double a, double b)
{
	return ((a * a) + (b * b));
}

int	ft_check_float(char *av)
{
	int	i;

	i = 0;
	if (av[0] == '-' || av[0] == '+')
		i++;
	while (av[i] != '\0')
	{
		if ((av[i] < '0' || av[i] > '9') && av[i] != '.')
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

/*This function conteins a set of colors palette in hex format,
if the iter value doesn't belongs to the set (escapes before reach the 
max iter value) uses the iter for multiply by a color and then add it
to the choosen palette
This way, each range of iterations will experiment modifications
in its coloring*/
int	ft_colors(int iter, t_fractal *f)
{
	int	color_s[5];

	color_s[0] = 0x7027A0FF;
	color_s[1] = 0xFC6FADFF;
	color_s[2] = 0xC32BADFF;
	color_s[3] = 0x37C2F1FF;
	color_s[4] = 0xFC5300FF;
	if (iter == f->max_iter)
		return (0x03001CFF);
	else
		return (color_s[(f->color % 5)] + iter * 0x06060000);
}
