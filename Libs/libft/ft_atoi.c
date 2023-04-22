/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svillalv <svillalv@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:38:08 by svillalv          #+#    #+#             */
/*   Updated: 2022/05/04 18:05:47 by svillalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	s;

	s = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
			return (num * s);
		str++;
	}
	return (num * s);
}
